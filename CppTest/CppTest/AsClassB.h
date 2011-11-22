#ifndef AsClassB_h__
#define AsClassB_h__
 
#include "AsBase.h"
 
#include "AsBaseClass.h"
 
class AsClassB;
typedef _ref<AsClassB> AsClassB_ref;
class AsClassC;
typedef _ref<AsClassC> AsClassC_ref;
 
class AsClassB : public AsBaseClass
{
public:
	__TYPENAME_H(AsClassB);
	
public:
	AsClassC_ref classC;
	
public:
	static AsClassB_ref __createAsClassB();
	void __internalInitialiseAsClassB();
	
private:
	static StaticInit __internalStaticInitializerAsClassB;
	static BOOL __internalStaticInitializedAsClassB;
	
public:
	static void __internalStaticInit();
	
protected:
	AsClassB();
	
public:
	void __internalGc();
};
 
#endif // AsClassB_h__
