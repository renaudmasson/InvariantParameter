/*
 * ObjectWithInvariant.hpp
 *
 *  Created on: Apr 16, 2016
 *      Author: renaud
 */

#ifndef OBJECTCHECKONDESTRUCTION_HPP_
#define OBJECTCHECKONDESTRUCTION_HPP_

#include <cassert>

template
<class T, class InvariantChecker>
class ObjectCheckOnDestruction
{
public:
	explicit ObjectCheckOnDestruction(T& obj)
		: object(obj)
	{

	}

	~ObjectCheckOnDestruction()
	{
		assert(checker.operator()(object));
	}

	operator T&()
	{
		return object;
	}

private:
	T&                 object;
	InvariantChecker   checker;
};



#endif /* OBJECTCHECKONDESTRUCTION_HPP_ */
