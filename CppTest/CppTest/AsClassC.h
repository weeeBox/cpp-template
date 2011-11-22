#ifndef AsClassC_h__
#define AsClassC_h__
 
#include "AsBase.h"
 
#include "AsBaseClass.h"
 
class AsClassC;
typedef _ref<AsClassC> AsClassC_ref;
class AsClassA;
typedef _ref<AsClassA> AsClassA_ref;
 
class AsClassC : public AsBaseClass
{
public:
	__TYPENAME_H(AsClassC);
	
public:
	AsClassA_ref classA;
	
public:
	static AsClassC_ref __createAsClassC();
	void __internalInitialiseAsClassC();
	
private:
	static StaticInit __internalStaticInitializerAsClassC;
	static BOOL __internalStaticInitializedAsClassC;
	
public:
	static void __internalStaticInit();
	
protected:
	AsClassC();
	
public:
	void __internalGc();
};
 
#endif // AsClassC_h__
