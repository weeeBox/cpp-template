#ifndef AsBaseClass_h__
#define AsBaseClass_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
class AsBaseClass;
typedef _ref<AsBaseClass> AsBaseClass_ref;
class AsMainClass;
typedef _ref<AsMainClass> AsMainClass_ref;
 
class AsBaseClass : public AsObject
{
public:
	__TYPENAME_H(AsBaseClass);
	
public:
	AsMainClass_ref mainClass;
	
public:
	static AsBaseClass_ref __createAsBaseClass();
	void __internalInitialiseAsBaseClass();
	
private:
	static StaticInit __internalStaticInitializerAsBaseClass;
	static BOOL __internalStaticInitializedAsBaseClass;
	
public:
	static void __internalStaticInit();
	
protected:
	AsBaseClass();
	
public:
	void __internalGc();
};
 
#endif // AsBaseClass_h__
