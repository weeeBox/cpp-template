#include "AsMainClass.h"
#include "AsMainClass.h"
#include "AsClassA.h"
#include "AsClassB.h"
#include "AsClassC.h"
#include "AsClassA.h"
#include "AsClassB.h"
#include "AsClassC.h"
 
AsMainClass_ref AsMainClass::instance(true);
 
void AsMainClass::init()
{
	__NEW(AsMainClass, (__NEW(AsClassA, ()), __NEW(AsClassB, ()), __NEW(AsClassC, ())));
}
 
AsMainClass_ref AsMainClass::__createAsMainClass(AsClassA_ref classA, AsClassB_ref classB, AsClassC_ref classC)
{
	AsMainClass_ref __reference(new AsMainClass());
	__reference->__internalConstructAsMainClass(classA, classB, classC);
	return __reference;
}
 
void AsMainClass::__internalConstructAsMainClass(AsClassA_ref classA, AsClassB_ref classB, AsClassC_ref classC)
{
	__internalConstructAsObject();
	__internalInitialiseAsMainClass();
	this->classA = classA;
	this->classB = classB;
	this->classC = classC;
	classA->mainClass = this;
	classB->mainClass = this;
	classC->mainClass = this;
	instance = this;
}
 
void AsMainClass::__internalInitialiseAsMainClass()
{
}
 
StaticInit AsMainClass::__internalStaticInitializerAsMainClass(&AsMainClass::__internalStaticInit);
BOOL AsMainClass::__internalStaticInitializedAsMainClass = false;
 
void AsMainClass::__internalStaticInit()
{
	if (!__internalStaticInitializedAsMainClass)
	{
		__internalStaticInitializedAsMainClass = true;
		AsObject::__internalStaticInit();
	}
}
 
AsMainClass::AsMainClass() :
  classA(false),
  classB(false),
  classC(false)
{
}
 
void AsMainClass::__internalGc()
{
	if(__internalGcNeeded())
	{
		AsObject::__internalGc();
		if (classA != __NULL) classA->__internalGc();
		if (classB != __NULL) classB->__internalGc();
		if (classC != __NULL) classC->__internalGc();
	}
}
