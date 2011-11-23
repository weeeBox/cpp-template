#include "AsFoo.h"
#include "AsFoo.h"
 
 
AsFoo_ref AsFoo::__createAsFoo(int value)
{
	AsFoo_ref __reference(new AsFoo());
	__reference->__internalConstructAsFoo(value);
	return __reference;
}
 
void AsFoo::__internalConstructAsFoo(int value)
{
	__internalConstructAsObject();
	__internalInitialiseAsFoo();
	this->value = value;
}
 
void AsFoo::__internalInitialiseAsFoo()
{
}
 
StaticInit AsFoo::__internalStaticInitializerAsFoo(&AsFoo::__internalStaticInit);
BOOL AsFoo::__internalStaticInitializedAsFoo = false;
 
void AsFoo::__internalStaticInit()
{
	if (!__internalStaticInitializedAsFoo)
	{
		__internalStaticInitializedAsFoo = true;
		AsObject::__internalStaticInit();
	}
}
 
AsFoo::AsFoo() :
  value(0)
{
}
