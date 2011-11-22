#include "AsBaseClass.h"
#include "AsBaseClass.h"
#include "AsMainClass.h"
 
__TYPENAME_CPP(AsBaseClass,AsObject)
 
 
AsBaseClass_ref AsBaseClass::__createAsBaseClass()
{
	AsBaseClass_ref __reference(new AsBaseClass());
	return __reference;
}
 
void AsBaseClass::__internalInitialiseAsBaseClass()
{
}
 
StaticInit AsBaseClass::__internalStaticInitializerAsBaseClass(&AsBaseClass::__internalStaticInit);
BOOL AsBaseClass::__internalStaticInitializedAsBaseClass = false;
 
void AsBaseClass::__internalStaticInit()
{
	if (!__internalStaticInitializedAsBaseClass)
	{
		__internalStaticInitializedAsBaseClass = true;
		AsObject::__internalStaticInit();
	}
}
 
AsBaseClass::AsBaseClass() :
  mainClass(false)
{
}
 
void AsBaseClass::__internalGc()
{
	if(__internalGcNeeded())
	{
		AsObject::__internalGc();
		if (mainClass != __NULL) mainClass->__internalGc();
	}
}
