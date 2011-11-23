#ifndef AsString_h__
#define AsString_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
class AsString;
typedef _ref<AsString> AsString_ref;
//class AsArray;
//typedef _ref<AsArray> AsArray_ref;
 
class AsString : public AsObject
{
public:
	__TYPENAME(AsString, AsObject);
	
public:
	int m_length;
	
public:
	AsString_ref charAt(float i);
	float charCodeAt(float i);
	AsString_ref concat(AsString_ref arg);
	static AsString_ref fromCharCode();
	int indexOf(AsString_ref s, float i);
	int lastIndexOf(AsString_ref s, float i);
	int getLength();
	int localeCompare(AsString_ref other);
	AsString_ref replace(AsString_ref p, AsString_ref repl);
	int search(AsString_ref p);
	AsString_ref slice(float start, float end);
	/*AsArray_ref split(AsString_ref delim, int limit);*/
	AsString_ref substr(float start, float len);
	AsString_ref substring(float start, float end);
	AsString_ref toLocaleLowerCase();
	AsString_ref toLocaleUpperCase();
	AsString_ref toLowerCase();
	AsString_ref toString();
	AsString_ref toUpperCase();
	AsString_ref valueOf();
	
public:
	static AsString_ref __createAsString();
	void __internalInitialiseAsString();
	
private:
	static StaticInit __internalStaticInitializerAsString;
	static BOOL __internalStaticInitializedAsString;
	
public:
	static void __internalStaticInit();
	
protected:
	AsString();
};
 
#endif // AsString_h__
