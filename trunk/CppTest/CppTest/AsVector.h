#ifndef AsVector_h__
#define AsVector_h__
 
#include "AsBase.h"
 
#include "AsObject.h"
 
class AsVector;
typedef _ref<AsVector> AsVector_ref;
class AsObject;
typedef _ref<AsObject> AsObject_ref;
class AsString;
typedef _ref<AsString> AsString_ref;
 
class VectorBase;
typedef _ref<VectorBase> VectorBase_ref;

class VectorBase : public AsObject
{
protected:
	int m_size;
	int m_length;
	int m_elemSize;
	void* m_data;	

public:
	__TYPENAME(VectorBase, AsObject);

	VectorBase(int size, int elemSize);
	~VectorBase();
	
public:
	inline int getLength() const { return m_length; }
};

/////////////////////////////////////////////////////////////////////////

template <class T> class ObjectVector : public VectorBase
{
public:
	class Ref : public _ref<ObjectVector>
	{
	public:
		Ref() : _ref() {}
		Ref(ObjectVector* obj) : _ref(obj) {}

		inline Ref& operator << (const T& val) { ((ObjectVector*)m_object)->__internalAdd(val); return *this; }
		inline T& operator[] (int index) { return (*(ObjectVector*)m_object)[index]; }
	};

public:
	__TYPENAME(ObjectVector, VectorBase);

public:

	ObjectVector(int size);

	inline T& operator[] (int index) { ASSERT(index >= 0 && index < m_length); return ((T*)m_data)[index]; }	

public:
	static Ref __createVector(int size) { ASSERT(size >= 0); return Ref(new ObjectVector(size)); }

	void __internalAdd(const T& element)
	{
		if (m_length == m_size)
		{
			int newSize = 2 * m_size;
			m_data = realloc(m_data, newSize * m_elemSize);
			__nullifyRange(m_size, newSize);
			m_size = newSize;
		}
		(*this)[m_length++] = element;
	}

	void __internalGc();

private:
	inline void __nullifyRange(int start, int end);
};

template <class T> ObjectVector<T>::ObjectVector(int size) : VectorBase(size, sizeof(AsObject_ref))
{
	__nullifyRange(0, size);
}

template <class T> void ObjectVector<T>::__internalGc()
{
	if(__internalGcNeeded())
	{
		AsObject::__internalGc();
		for (int i = 0; i < m_length; ++i)
		{
			AsObject_ref& ref = ((AsObject_ref*)m_data)[i];
			if (ref != __NULL) ref->__internalGc();
		}	
	}
}

template <class T> void ObjectVector<T>::__nullifyRange(int start, int end)
{	
	for (int i = start; i < end; ++i)
	{		
		((AsObject_ref*)m_data)[i] = __NULL;
	}
}

/////////////////////////////////////////////////////////////////////////

//class ObjectVector;
//typedef _ref<ObjectVector> ObjectVector_ref;
//
//template <class T> ObjectVector : public ObjectVector
//{
//
//};

//class AsVector : public AsObject
//{
//public:
//	__TYPENAME_H(AsVector);
//	
//public:
//	BOOL fixed;
//	int length;
//	
//public:
//	AsVector_ref concat(AsObject_ref arg);
//	BOOL every();
//	AsVector_ref filter();
//	void forEach();
//	int indexOf(AsObject_ref searchElement, int fromIndex);
//	AsString_ref join(AsString_ref sep);
//	int lastIndexOf(AsObject_ref searchElement, int fromIndex);
//	AsVector_ref map();
//	AsObject_ref pop();
//	int push(AsObject_ref arg);
//	AsVector_ref reverse();
//	AsObject_ref shift();
//	AsVector_ref slice(int startIndex, int endIndex);
//	BOOL some();
//	AsVector_ref sort();
//	AsVector_ref splice();
//	AsString_ref toLocaleString();
//	AsString_ref toString();
//	int unshift(AsObject_ref arg);
//	
//public:
//	static AsVector_ref __createAsVector(int length, BOOL fixed);
//	
//private:
//	void __internalConstructAsVector(int length, BOOL fixed);
//	
//public:
//	void __internalInitialiseAsVector();
//	
//private:
//	static StaticInit __internalStaticInitializerAsVector;
//	static BOOL __internalStaticInitializedAsVector;
//	
//public:
//	static void __internalStaticInit();
//	
//protected:
//	AsVector();
//};
 
#endif // AsVector_h__
