/*
 * InvariantTests.hpp
 *
 *  Created on: Apr 17, 2016
 *      Author: renaud
 */

#include <vector>

#include "../ObjectCheckOnDestruction.hpp"
#include "../ReferenceWithInvariant.hpp"
#include "../ValueWithInvariant.hpp"

#include "gtest/gtest.h"

namespace {
  bool contractBroken = false;
  class InvariantTests : public ::testing::Test {

  protected:
	  virtual void SetUp() {
	        contractBroken = false;
	      }


  };

  class Positive
  {
  public:
  	void operator()(int val)
  	{
  		if(val <= 0)
  		{
  			contractBroken = true;
  		}
  	}
  };

  class NotEmpty
    {
    public:
    	void operator()(std::vector<int> vals)
    	{
    		if(vals.empty())
    		{
    			contractBroken = true;
    		}
    	}
    };

  void foo(ReferenceWithInvariant<int, Positive> a)
  {
	  a.get() -= 1;
	  a.get() -= 2;
  }

  void bar(std::vector<int> &vec)
  {
	  vec.pop_back();
	  vec.pop_back();
  }

  void fooBar(ValueWithInvariant<std::vector<int>, NotEmpty> vals)
  {
	  bar(vals.get());
	  vals.get().get().push_back(1);
  }




  TEST_F(InvariantTests, ReferenceFails) {
	int i = 3;
	foo(i);
    ASSERT_TRUE(contractBroken);
  }

  TEST_F(InvariantTests, ReferenceFailsNull) {
	int i = 0;
	foo(i);
	ASSERT_TRUE(contractBroken);
  }

  TEST_F(InvariantTests, ReferenceSucceed) {
	int i = 4;
	foo(i);
    ASSERT_FALSE(contractBroken);
  }


  TEST_F(InvariantTests, ValueFails) {
	auto v = std::vector<int>{1,2};
	fooBar(std::move(v));
	ASSERT_TRUE(contractBroken);
  }


  TEST_F(InvariantTests, ValueSucceed) {
	auto v = std::vector<int>{1,2,3};
	fooBar(v);
	ASSERT_FALSE(contractBroken);
  }
}

