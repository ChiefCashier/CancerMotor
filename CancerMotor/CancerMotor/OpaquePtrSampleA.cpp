#if defined(PLATFORM_A)

#include <iostream>
#include "OpaquePtrSample.h"

class OpaquePtrSample::Implementation
{
public:

	int i;

	Implementation()
		: i(27){}

	void doSomething()
	{
		std::cout << std::endl << "A: " << i << std::endl;
	}
};

OpaquePtrSample::OpaquePtrSample()
	: _impl(new Implementation()) {}



OpaquePtrSample::~OpaquePtrSample()
{
	delete _impl;
}
void OpaquePtrSample::doSomething()
{
	_impl->doSomething();
}
#endif