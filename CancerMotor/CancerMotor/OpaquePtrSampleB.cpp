#if defined(PLATFORM_B)
#include <iostream>
#include "OpaquePtrSample.h"

class OpaquePtrSample::Implementation
{
public:
	float i;

	Implementation()
		: i(69.0f){}

	void doSomething()
	{
		std::cout << std::endl << "B: " << i << std::endl;
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