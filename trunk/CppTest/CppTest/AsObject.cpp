#include <iostream>

#include "AsObject.h"

////////////////////////////////////////////////////////////////////////////////////

StaticInit* StaticInit::root = (StaticInit*)(0);

StaticInit::StaticInit(__jinit* initFunction)
{
	this->initFunction = initFunction;
	next = root;
	root = this;
}

void StaticInit::initStatics()
{
	StaticInit* c = root;
	while (c)
	{
		c->initFunction();
		c = c->next;
	}
	root = 0;
}

////////////////////////////////////////////////////////////////////////////////////

short ReferenceBase::__internalGlobalGcTime;

ReferenceBase* ReferenceBase::staticRefHead = 0;
ReferenceBase* ReferenceBase::refHead = 0;

int ReferenceBase::refCount = 0;
int ReferenceBase::refStaticCount = 0;

ReferenceBase::ReferenceBase() : m_object(0), m_static(false), __prev(0), __next(0)
{
	reg();
}

ReferenceBase::ReferenceBase(AsObject *obj) : m_object(0), m_static(false), __prev(0), __next(0)
{
	set(obj);
	reg();
}

ReferenceBase::ReferenceBase(const ReferenceBase& other) : m_object(0), m_static(false), __prev(0), __next(0)
{
	set(other.m_object);
	reg();
}

ReferenceBase::ReferenceBase(bool isStatic) : m_object(0), m_static(isStatic), __prev(0), __next(0)
{
	reg();	
}

ReferenceBase::~ReferenceBase()
{
	set(0);
	unreg();
}

void ReferenceBase::set(AsObject *obj)
{
	AsObject *prevObject = m_object;

	m_object = obj;
	if (obj)
	{
		m_object->__internalReferenceCount++;
	}

	if (prevObject)
	{
		prevObject->__internalReferenceCount--;
		if (prevObject->__internalReferenceCount == 0)
		{
			delete prevObject;
		}
	}
}

void ReferenceBase::reg()
{	
	if (m_static)
	{
		refStaticCount++;		
		addToList(&staticRefHead);
	}
	else
	{
		refCount++;		
		addToList(&refHead);
	}	
}

void ReferenceBase::unreg()
{
	if (m_static)
	{
		refStaticCount--;
		removeFromList(&staticRefHead);
	}
	else
	{
		refCount--;		
		removeFromList(&refHead);
	}
}

void ReferenceBase::addToList(ReferenceBase **listHead)
{	
	if (*listHead) (*listHead)->__prev = this;
	__next = *listHead;
	*listHead = this;
}

void ReferenceBase::removeFromList(ReferenceBase **listHead)
{
	if (__prev) __prev->__next = __next; else if (*listHead) *listHead = __next;
	if (__next) __next->__prev = __prev;
}

void ReferenceBase::__internalGc()
{
	std::cout << "GC tick" << std::endl;

	// inc gc time
	__internalGlobalGcTime = __internalGlobalGcTime == 32767 ? 1 : (__internalGlobalGcTime + 1);

	// mark	
	for (ReferenceBase* ref = staticRefHead; ref; ref = ref->__next)
	{
		AsObject* obj = ref->m_object;
		if (obj)
		{
			obj->__internalGc();
		}
	}	

	// delete statics
	ReferenceBase* ref = staticRefHead;
	while (ref)
	{		
		if (ref->m_object && ref->m_object->__internalGcTime != __internalGlobalGcTime)
		{			
			ReferenceBase* prev = ref->__prev;

			ref->unreg();
			ref->set(0);			

			if (prev) ref = prev->__next;
			else ref = staticRefHead;
		}
		else
		{
			ref = ref->__next;
		}
	}

	// delete non statics
	ref = refHead;
	while (ref)
	{		
		AsObject* obj = ref->m_object;
		if (obj && obj->__internalGcTime != __internalGlobalGcTime)
		{			
			ReferenceBase* prev = ref->__prev;

			ref->unreg();
			ref->set(0);			

			if (prev) ref = prev->__next;
			else ref = refHead;
		}
		else
		{
			ref = ref->__next;
		}
	}
}

void ReferenceBase::__checkMemoryLeaks()
{
	int leaksCount = 0;
	int staticRefCount = 0;
	int refCount = 0;
		
	for (ReferenceBase* ref = staticRefHead; ref; ref = ref->__next)
	{
		AsObject* obj = ref->m_object;
		if (obj)
		{
			leaksCount++;
		}
		staticRefCount++;
	}	

	for (ReferenceBase* ref = refHead; ref; ref = ref->__next)
	{
		AsObject* obj = ref->m_object;
		if (obj)
		{
			leaksCount++;
		}
		refCount++;
	}

	std::cout << "Leaks count: " << leaksCount << " refCount: " << refCount << " static: " << staticRefCount << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////

AsObject_ref AsObject::__null__(true);

StaticInit AsObject::__internalStaticInitializer = (StaticInit)0;

bool AsObject::__internalStaticInitialized = false;	

bool AsObject::__internalInstanceOf(const char* typeName)
{
	int i = 0;
	const char* ourTypeName = 0;
	while (ourTypeName = __internalTypename(i))
	{
		if (__internalCmp(typeName, ourTypeName))
			return true;
		i++;
	}
	return false;
}

const char* AsObject::__internalTypename()
{
	return "AsObject";
}

const char* AsObject::__internalTypename(int depth)
{
	if (depth)
		return 0;
	else
		return __internalTypename();
}

bool AsObject::__internalCmp(const char* s1, const char* s2)
{
	while (*s1 || *s2)
	{
		if (*s1++ != *s2++)
			return false;
	}
	return true;
}


AsObject::AsObject() : __internalReferenceCount(0), __internalGcTime(0)
{
}

AsObject::~AsObject()
{
}

AsObject_ref AsObject::__createAsObject()
{
	return AsObject_ref(new AsObject());
}

void AsObject::__internalConstructAsObject()
{
}

void AsObject::__internalStaticInit()
{

}

void AsObject::__internalGc()
{
	__internalGcTime = ReferenceBase::__internalGlobalGcTime;
}

bool AsObject::__internalGcNeeded()
{
	return __internalGcTime != ReferenceBase::__internalGlobalGcTime;
}