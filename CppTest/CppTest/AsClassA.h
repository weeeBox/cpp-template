#ifndef AsClassA_h__
#define AsClassA_h__
 
#include "AsBase.h"
 
#include "AsBaseClass.h"
 
class AsClassA;
typedef _ref<AsClassA> AsClassA_ref;
class AsClassB;
typedef _ref<AsClassB> AsClassB_ref;
 
class AsClassA : public AsBaseClass
{
public:
	__TYPENAME(AsClassA, AsBaseClass);
	
public:
	AsClassB_ref classB;
	
public:
	static AsClassA_ref __createAsClassA();
	void __internalInitialiseAsClassA();
	
private:
	static StaticInit __internalStaticInitializerAsClassA;
	static BOOL __internalStaticInitializedAsClassA;
	
public:
	static void __internalStaticInit();
	
protected:
	AsClassA();
	
public:
	void __internalGc();
};
 
#endif // AsClassA_h__
