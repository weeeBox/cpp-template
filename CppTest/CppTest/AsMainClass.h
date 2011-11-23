#ifndef AsMainClass_h__
#define AsMainClass_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
class AsMainClass;
typedef _ref<AsMainClass> AsMainClass_ref;
class AsClassA;
typedef _ref<AsClassA> AsClassA_ref;
class AsClassB;
typedef _ref<AsClassB> AsClassB_ref;
class AsClassC;
typedef _ref<AsClassC> AsClassC_ref;
 
class AsMainClass : public AsObject
{
public:
	__TYPENAME(AsMainClass, AsObject);
	
public:
	AsClassA_ref classA;
	AsClassB_ref classB;
	AsClassC_ref classC;
	static AsMainClass_ref instance;
	
public:
	static void init();
	
public:
	static AsMainClass_ref __createAsMainClass(AsClassA_ref classA, AsClassB_ref classB, AsClassC_ref classC);
	
private:
	void __internalConstructAsMainClass(AsClassA_ref classA, AsClassB_ref classB, AsClassC_ref classC);
	
public:
	void __internalInitialiseAsMainClass();
	
private:
	static StaticInit __internalStaticInitializerAsMainClass;
	static BOOL __internalStaticInitializedAsMainClass;
	
public:
	static void __internalStaticInit();
	
protected:
	AsMainClass();
	
public:
	void __internalGc();
};
 
#endif // AsMainClass_h__
