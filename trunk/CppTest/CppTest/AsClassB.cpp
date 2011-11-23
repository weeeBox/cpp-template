#include "AsClassB.h"
#include "AsClassB.h"
#include "AsClassC.h"
 
 
AsClassB_ref AsClassB::__createAsClassB()
{
	AsClassB_ref __reference(new AsClassB());
	return __reference;
}
 
void AsClassB::__internalInitialiseAsClassB()
{
}
 
StaticInit AsClassB::__internalStaticInitializerAsClassB(&AsClassB::__internalStaticInit);
BOOL AsClassB::__internalStaticInitializedAsClassB = false;
 
void AsClassB::__internalStaticInit()
{
	if (!__internalStaticInitializedAsClassB)
	{
		__internalStaticInitializedAsClassB = true;
		AsBaseClass::__internalStaticInit();
	}
}
 
AsClassB::AsClassB() :
  classC(false)
{
}
 
void AsClassB::__internalGc()
{
	if(__internalGcNeeded())
	{
		AsBaseClass::__internalGc();
		if (classC != __NULL) classC->__internalGc();
	}
}
