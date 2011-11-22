#include <memory>
#include <iostream>

#include "AsObject.h"

#include "AsMainClass.h"

int main()
{
	AsMainClass::init();

	ReferenceBase::__internalGc();
	ReferenceBase::__checkMemoryLeaks();

	AsMainClass::instance = __NULL;

	ReferenceBase::__internalGc();
	ReferenceBase::__checkMemoryLeaks();

	ReferenceBase::__internalGc();
	ReferenceBase::__checkMemoryLeaks();

	return 0;
}