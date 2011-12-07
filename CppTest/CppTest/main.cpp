#include <memory>
#include <iostream>

#include "AsObject.h"

#include "AsClassA.h"
#include "AsClassB.h"
#include "AsClassC.h"
#include "AsMainClass.h"
#include "AsIFooInterface.h"

typedef _ref<AsBaseClass> AsBaseClass_ref;
typedef AsVector<AsBaseClass_ref> __V_AsBaseClass;
typedef __V_AsBaseClass::Ref __V_AsBaseClass_ref;

typedef AsIFooInterface<AsClassA_ref> __I_AsClassA;
typedef _ref<__I_AsClassA> __I_AsClassA_ref;

int main()
{
	AsMainClass::init();

	AsMainClass::instance->foo();
	AsMainClass::instance = __NULL;

	ReferenceBase::__internalGc();
	ReferenceBase::__checkMemoryLeaks();

	AsMainClass::vector = __NULL;

	ReferenceBase::__internalGc();
	ReferenceBase::__checkMemoryLeaks();

	return 0;
}