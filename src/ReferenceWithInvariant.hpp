/*
 * ParameterWithInvariant.hpp
 *
 *  Created on: Apr 16, 2016
 *      Author: renaud
 */

#ifndef REFERENCEWITHINVARIANT_HPP_
#define REFERENCEWITHINVARIANT_HPP_

#include "ObjectCheckOnDestruction.hpp"


template
<class T, class InvariantChecker>
class ReferenceWithInvariant
{
public:
	ReferenceWithInvariant(T& obj)
		: object(obj)
	{
    checker.operator()(object);
	}

	~ReferenceWithInvariant()
	{
	    checker.operator()(object);
	}

	ObjectCheckOnDestruction<T,InvariantChecker> get()
	{
		return ObjectCheckOnDestruction<T,InvariantChecker>{object};
	}

private:
	T&                 object;
	InvariantChecker   checker;
};



#endif /* REFERENCEWITHINVARIANT_HPP_ */
