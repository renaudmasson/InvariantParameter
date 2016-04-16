/*
 * ParameterWithInvariant.hpp
 *
 *  Created on: Apr 16, 2016
 *      Author: renaud
 */

#ifndef PARAMETERWITHINVARIANT_HPP_
#define PARAMETERWITHINVARIANT_HPP_

#include "ObjectCheckOnDestruction.hpp"

#include <cassert>

template
<class T, class InvariantChecker>
class ParameterWithInvariant
{
public:
	ParameterWithInvariant(T& obj)
		: object(obj)
	{
    assert(object);
	}

	~ParameterWithInvariant()
	{
	}

	ObjectCheckOnDestruction<T,InvariantChecker> get()
	{
		return ObjectCheckOnDestruction<T,InvariantChecker>{object};
	}

private:
	T&                 object;
	InvariantChecker   checker;
};



#endif /* PARAMETERWITHINVARIANT_HPP_ */
