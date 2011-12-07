#ifndef AsInterface_h__
#define AsInterface_h__

#include "AsBase.h"

#include "AsObject.h"

template <class T> class AsInterface : public AsObject
{
private:
	T m_delegate;

public:
	__TYPENAME(AsObject, AsObject);

public:
	AsInterface() : m_delegate(false) {}
	AsInterface(const AsInterface& other) : m_delegate(other.m_delegate) {};	
	AsInterface(const T& obj) : m_delegate(obj) {}

	inline T* operator->() const { ASSERT(m_delegate); return (T*)m_delegate; }	

protected:
	inline T getDelegate() const { return m_delegate; }

public:
	static inline _ref<AsInterface> __internalBox(const T& m_delegate)
	{
		return _ref<AsInterface>(new AsInterface(m_delegate));
	}

public:
	void __internalGc()
	{
		if(__internalGcNeeded())
		{
			AsObject::__internalGc();
			m_delegate->__internalGc();			
		}
	}

};

#endif // AsInterface_h__
