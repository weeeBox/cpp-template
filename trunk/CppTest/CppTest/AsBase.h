#ifndef AsBase_h__
#define AsBase_h__

#ifndef BOOL
#define BOOL bool
#endif

#ifndef NULL
#define NULL 0
#endif

#define __TYPEREF_DEF(typeName) class typeName; typedef _ref<typeName> typeName##_ref;

#include "AsVector.h"

#endif // AsBase_h__