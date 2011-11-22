#include "AsClassC.h"
#include "AsClassC.h"
#include "AsClassA.h"
 
__TYPENAME_CPP(AsClassC,AsBaseClass)
 
 
AsClassC_ref AsClassC::__createAsClassC()
{
	AsClassC_ref __reference(new AsClassC());
	return __reference;
}
 
void AsClassC::__internalInitialiseAsClassC()
{
}
 
StaticInit AsClassC::__internalStaticInitializerAsClassC(&AsClassC::__internalStaticInit);
BOOL AsClassC::__internalStaticInitializedAsClassC = false;
 
void AsClassC::__internalStaticInit()
{
	if (!__internalStaticInitializedAsClassC)
	{
		__internalStaticInitializedAsClassC = true;
		AsBaseClass::__internalStaticInit();
	}
}
 
AsClassC::AsClassC() :
  classA(false)
{
}
 
void AsClassC::__internalGc()
{
	if(__internalGcNeeded())
	{
		AsBaseClass::__internalGc();
		if (classA != __NULL) classA->__internalGc();
	}
}
