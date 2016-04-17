/*
 * allTests.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: renaud
 */

#include "gtest/gtest.h"
#include "InvariantTests.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


