#include "AsVector.h"
#include "AsVector.h"
#include "AsObject.h"
#include "AsString.h"
#include "AsObject.h"
#include "AsString.h"
 
#include <memory>

VectorBase::VectorBase(int size, int elemSize) :
	m_size(size),
	m_length(0),
	m_elemSize(elemSize),	
	m_data(NULL)
{	
	if (size > 0)
	{
		m_data = calloc(size, elemSize);
	}
}

VectorBase::~VectorBase()
{
	if (m_data)
	{
		free(m_data);
	}
}

//__TYPENAME_CPP(AsVector,AsObject)
// 
// 
//AsVector_ref AsVector::concat(AsObject_ref arg)
//{
//	return __NULL;
//}
// 
//BOOL AsVector::every()
//{
//	return false;
//}
// 
//AsVector_ref AsVector::filter()
//{
//	return __NULL;
//}
// 
//void AsVector::forEach()
//{
//}
// 
//int AsVector::indexOf(AsObject_ref searchElement, int fromIndex)
//{
//	return 0;
//}
// 
//AsString_ref AsVector::join(AsString_ref sep)
//{
//	return __NULL;
//}
// 
//int AsVector::lastIndexOf(AsObject_ref searchElement, int fromIndex)
//{
//	return 0;
//}
// 
//AsVector_ref AsVector::map()
//{
//	return __NULL;
//}
// 
//AsObject_ref AsVector::pop()
//{
//	return __NULL;
//}
// 
//int AsVector::push(AsObject_ref arg)
//{
//	return 0;
//}
// 
//AsVector_ref AsVector::reverse()
//{
//	return __NULL;
//}
// 
//AsObject_ref AsVector::shift()
//{
//	return __NULL;
//}
// 
//AsVector_ref AsVector::slice(int startIndex, int endIndex)
//{
//	return __NULL;
//}
// 
//BOOL AsVector::some()
//{
//	return false;
//}
// 
//AsVector_ref AsVector::sort()
//{
//	return __NULL;
//}
// 
//AsVector_ref AsVector::splice()
//{
//	return __NULL;
//}
// 
//AsString_ref AsVector::toLocaleString()
//{
//	return __NULL;
//}
// 
//AsString_ref AsVector::toString()
//{
//	return __NULL;
//}
// 
//int AsVector::unshift(AsObject_ref arg)
//{
//	return __NULL;
//}
// 
//AsVector_ref AsVector::__createAsVector(int length, BOOL fixed)
//{
//	AsVector_ref __reference(new AsVector());
//	__reference->__internalConstructAsVector(length, fixed);
//	return __reference;
//}
// 
//void AsVector::__internalConstructAsVector(int length, BOOL fixed)
//{
//	__internalConstructAsObject();
//	__internalInitialiseAsVector();
//}
// 
//void AsVector::__internalInitialiseAsVector()
//{
//}
// 
//StaticInit AsVector::__internalStaticInitializerAsVector(&AsVector::__internalStaticInit);
//BOOL AsVector::__internalStaticInitializedAsVector = false;
// 
//void AsVector::__internalStaticInit()
//{
//	if (!__internalStaticInitializedAsVector)
//	{
//		__internalStaticInitializedAsVector = true;
//		AsObject::__internalStaticInit();
//	}
//}
// 
//AsVector::AsVector() :
//  fixed(0),
//  length(0)
//{
//}
