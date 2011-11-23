#include "AsVectorBase.h"
#include "AsVectorBase.h"
 
__TYPENAME_CPP(AsVectorBase,AsObject)
 
 
AsVectorBase_ref AsVectorBase::__createAsVectorBase()
{
	AsVectorBase_ref __reference(new AsVectorBase());
	return __reference;
}
 
void AsVectorBase::__internalInitialiseAsVectorBase()
{
}
 
StaticInit AsVectorBase::__internalStaticInitializerAsVectorBase(&AsVectorBase::__internalStaticInit);
BOOL AsVectorBase::__internalStaticInitializedAsVectorBase = false;
 
void AsVectorBase::__internalStaticInit()
{
	if (!__internalStaticInitializedAsVectorBase)
	{
		__internalStaticInitializedAsVectorBase = true;
		AsObject::__internalStaticInit();
	}
}
 
AsVectorBase::AsVectorBase() :
  m_length(0),
  m_fixed(0)
{
}
