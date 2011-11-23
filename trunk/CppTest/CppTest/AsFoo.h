#ifndef AsFoo_h__
#define AsFoo_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
class AsFoo;
typedef _ref<AsFoo> AsFoo_ref;
 
class AsFoo : public AsObject
{
public:
	__TYPENAME(AsFoo, AsObject);
	
public:
	int value;
	
public:
	static AsFoo_ref __createAsFoo(int value);
	
private:
	void __internalConstructAsFoo(int value);
	
public:
	void __internalInitialiseAsFoo();
	
private:
	static StaticInit __internalStaticInitializerAsFoo;
	static BOOL __internalStaticInitializedAsFoo;
	
public:
	static void __internalStaticInit();
	
protected:
	AsFoo();
};
 
#endif // AsFoo_h__
