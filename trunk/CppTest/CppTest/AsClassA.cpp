#include "AsClassA.h"
#include "AsClassA.h"
#include "AsClassB.h"
 
__TYPENAME_CPP(AsClassA,AsBaseClass)
 
 
AsClassA_ref AsClassA::__createAsClassA()
{
	AsClassA_ref __reference(new AsClassA());
	return __reference;
}
 
void AsClassA::__internalInitialiseAsClassA()
{
}
 
StaticInit AsClassA::__internalStaticInitializerAsClassA(&AsClassA::__internalStaticInit);
BOOL AsClassA::__internalStaticInitializedAsClassA = false;
 
void AsClassA::__internalStaticInit()
{
	if (!__internalStaticInitializedAsClassA)
	{
		__internalStaticInitializedAsClassA = true;
		AsBaseClass::__internalStaticInit();
	}
}
 
AsClassA::AsClassA() :
  classB(false)
{
}
 
void AsClassA::__internalGc()
{
	if(__internalGcNeeded())
	{
		AsBaseClass::__internalGc();
		if (classB != __NULL) classB->__internalGc();
	}
}
