#include "AsString.h"
#include "AsString.h"
#include "AsString.h"
 
AsString_ref AsString::charAt(float i)
{
	return __NULL;
}
 
float AsString::charCodeAt(float i)
{
	return 0;
}
 
AsString_ref AsString::concat(AsString_ref arg)
{
	return __NULL;
}
 
AsString_ref AsString::fromCharCode()
{
	return __NULL;
}
 
int AsString::indexOf(AsString_ref s, float i)
{
	return 0;
}
 
int AsString::lastIndexOf(AsString_ref s, float i)
{
	return 0;
}
 
int AsString::getLength()
{
	return m_length;
}
 
int AsString::localeCompare(AsString_ref other)
{
	return 0;
}
 
AsString_ref AsString::replace(AsString_ref p, AsString_ref repl)
{
	return __NULL;
}
 
int AsString::search(AsString_ref p)
{
	return 0;
}
 
AsString_ref AsString::slice(float start, float end)
{
	return __NULL;
}
 
//AsArray_ref AsString::split(AsString_ref delim, int limit)
//{
//	return __NULL;
//}
 
AsString_ref AsString::substr(float start, float len)
{
	return __NULL;
}
 
AsString_ref AsString::substring(float start, float end)
{
	return __NULL;
}
 
AsString_ref AsString::toLocaleLowerCase()
{
	return __NULL;
}
 
AsString_ref AsString::toLocaleUpperCase()
{
	return __NULL;
}
 
AsString_ref AsString::toLowerCase()
{
	return __NULL;
}
 
AsString_ref AsString::toString()
{
	return __NULL;
}
 
AsString_ref AsString::toUpperCase()
{
	return __NULL;
}
 
AsString_ref AsString::valueOf()
{
	return __NULL;
}
 
AsString_ref AsString::__createAsString()
{
	AsString_ref __reference(new AsString());
	return __reference;
}
 
void AsString::__internalInitialiseAsString()
{
	m_length = 1;
}
 
StaticInit AsString::__internalStaticInitializerAsString(&AsString::__internalStaticInit);
BOOL AsString::__internalStaticInitializedAsString = false;
 
void AsString::__internalStaticInit()
{
	if (!__internalStaticInitializedAsString)
	{
		__internalStaticInitializedAsString = true;
		AsObject::__internalStaticInit();
	}
}
 
AsString::AsString()
{
}
