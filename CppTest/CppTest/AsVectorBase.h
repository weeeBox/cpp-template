#ifndef AsVectorBase_h__
#define AsVectorBase_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
class AsVectorBase;
typedef _ref<AsVectorBase> AsVectorBase_ref;
 
class AsVectorBase : public AsObject
{
public:
	__TYPENAME_H(AsVectorBase);
	
private:
	int m_length;
	BOOL m_fixed;
	
public:
	static AsVectorBase_ref __createAsVectorBase();
	void __internalInitialiseAsVectorBase();
	
private:
	static StaticInit __internalStaticInitializerAsVectorBase;
	static BOOL __internalStaticInitializedAsVectorBase;
	
public:
	static void __internalStaticInit();
	
protected:
	AsVectorBase();
};
 
#endif // AsVectorBase_h__
