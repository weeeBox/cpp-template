#ifndef AsObject_h__
#define AsObject_h__

#include "Debug.h"

#define JASSERT(expr) ASSERT(expr)
#define JASSERTMSG(expr, msg) ASSERT(expr)

//////////////////////////////////////////////////////////////////////////

typedef void __jinit();

class StaticInit
{
public:
	StaticInit(__jinit* initFunction);

	static void initStatics();

	static StaticInit* root;

	__jinit* initFunction;
	StaticInit* next;
};

//////////////////////////////////////////////////////////////////////////

#define __TYPENAME_H(typeName)  static inline void __hack() { typeName##_ref _hack = typeName##_ref((AsObject*)0); } \
	protected: virtual const char* __internalTypename(int depth); public: static const char* __internalTypename()

#define __TYPENAME_CPP_EX(CLASS, BASE, NAME) const char* CLASS::__internalTypename() { return #NAME; } \
	const char* CLASS::__internalTypename(int depth) { if (depth) return BASE::__internalTypename(depth - 1); else return __internalTypename(); }

#define __TYPENAME_CPP(CLASS, BASE) __TYPENAME_CPP_EX(CLASS, BASE, CLASS)

#define __INSTANCEOF(obj, typeName) (obj != 0 && obj->__internalInstanceOf(typeName::__internalTypename()))

#define __NEW(objType, initializer) objType::__create##objType initializer
#define __NEWARRAY(arrayType, size) ((arrayType##_ref)(arrayType::__createArray(size)))

#define __NULL AsObject::__null__

//////////////////////////////////////////////////////////////////////////

class AsObject;

class ReferenceBase
{
public:
	ReferenceBase();
	ReferenceBase(AsObject* object);
	ReferenceBase(const ReferenceBase& ref);
	explicit ReferenceBase(bool isStatic);
	~ReferenceBase();
		
	inline ReferenceBase& operator= (const ReferenceBase& ref) { set(ref.m_object); return *this; }

	inline bool operator == (const ReferenceBase& ref) { return m_object == ref.m_object; }
	inline bool operator != (const ReferenceBase& ref) { return m_object != ref.m_object; }	

	static bool __initStatics();
	static void __destroyStatics();

public:
	static int refCount;
	static int refStaticCount;
		
public:	
	void set(AsObject* object);
	
	AsObject* m_object;	

	ReferenceBase *__next;
	ReferenceBase *__prev;

private:
	static short __internalGlobalGcTime;

public:
	static void __internalGc();
	static void __checkMemoryLeaks();
	

private:
	friend class AsObject;
	friend class ObjectArrayBase;

	void reg();
	void unreg();
	
	void addToList(ReferenceBase **listHead);
	void removeFromList(ReferenceBase **listHead);	

	bool m_static;

	static ReferenceBase* refHead;
	static ReferenceBase* staticRefHead;	
};

template<class T> class _ref : public ReferenceBase
{
public:
	_ref() : ReferenceBase() {}
	_ref(const ReferenceBase& ref) : ReferenceBase(ref) {};
	_ref(T* obj) : ReferenceBase(obj) { ASSERT(!obj || JINSTANCEOF(obj,T)); }
	explicit _ref(bool isStatic) : ReferenceBase(isStatic) {}

	inline T* operator->() const 
	{
		if(m_object == 0)
		{
			ASSERT(m_object); 
		}
		return (T*)m_object; 
	}

	inline _ref& operator=(const _ref& ref)
	{
		set(ref.m_object);
		return *this;
	}
};

//////////////////////////////////////////////////////////////////////////

class JString;
typedef _ref<JString> JString_ref;

typedef _ref<AsObject> AsObject_ref;

class AsObject
{
public:
	AsObject();
	virtual ~AsObject();

	__TYPENAME_H(AsObject);

	bool __internalInstanceOf(const char* typeName);
	void __removeChildReferences();

	const char * __internalGetTypeName()
	{
		return __internalTypename(0);
	}

public:
	static AsObject_ref __createAsObject();	
	void __internalConstructAsObject();

protected:
	static bool __internalCmp(const char* s1, const char* s2);

private:
	friend class ReferenceBase;
	int __internalReferenceCount;
	
	short __internalGcTime;	

public:
	virtual void __internalGc();	
	bool __internalGcNeeded();

public:
	static void __internalGlobalGc();
		
	static AsObject_ref __null__;

protected:

	static StaticInit __internalStaticInitializer;
	static bool __internalStaticInitialized;	
	static void __internalStaticInit();	
};

#endif // AsObject_h__