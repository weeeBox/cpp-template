#include <memory>
#include <iostream>

#include "AsObject.h"

#include "AsVector.h"
#include "AsFoo.h"

int main()
{
	
	ObjectVector<AsFoo_ref>::Ref arr = __NEWVECTOR(ObjectVector<AsFoo_ref>, 3) << __NEW(AsFoo,(1)) << __NEW(AsFoo,(2)) << __NEW(AsFoo,(3));	

	for (int i = 0; i < arr->getLength(); ++i)
	{
		std::cout << arr[i]->value << std::endl;
	}

	std::cout << (__INSTANCEOF(arr, AsFoo) ? "true" : "false") << std::endl;
	std::cout << (__INSTANCEOF(arr, AsObject) ? "true" : "false") << std::endl;
	std::cout << (__INSTANCEOF(arr, ObjectVector<AsFoo_ref>) ? "true" : "false") << std::endl;
	
	ReferenceBase::__internalGc();
	ReferenceBase::__checkMemoryLeaks();
	
	return 0;
}