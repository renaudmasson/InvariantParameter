/*
 * ValueWithInvariant.hpp
 *
 *  Created on: Apr 17, 2016
 *      Author: renaud
 */

#ifndef VALUEWITHINVARIANT_HPP_
#define VALUEWITHINVARIANT_HPP_



#include "ObjectCheckOnDestruction.hpp"


template
<class T, class InvariantChecker>
class ValueWithInvariant
{
public:
	ValueWithInvariant(T& obj)
		: object(obj)
	{
    checker.operator()(object);
	}

	ValueWithInvariant(T&& obj)
		: object(std::move(obj))
	{
    checker.operator()(object);
	}

	~ValueWithInvariant()
	{
	    checker.operator()(object);
	}

	ObjectCheckOnDestruction<T,InvariantChecker> get()
	{
		return ObjectCheckOnDestruction<T,InvariantChecker>{object};
	}

private:
	T                  object;
	InvariantChecker   checker;
};






#endif /* VALUEWITHINVARIANT_HPP_ */
