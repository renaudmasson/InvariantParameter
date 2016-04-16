//============================================================================
// Name        : InvariantTest.cpp
// Author      : Renaud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ObjectCheckOnDestruction.hpp"
#include "ParameterWithInvariant.hpp"
using namespace std;

class Positive
{
public:
	bool operator()(int val)
	{
		return val > 0;
	}
};

void doStuff(int &d)
{
	d -= 1;
}

void bar(int &d)
{
	doStuff(d);
	doStuff(d);
	doStuff(d);
}

void foo(ParameterWithInvariant<int, Positive> pos)
{
	bar(pos.get());
}


int main() {
	int d = 3;
	foo(d);
	return 0;
}
