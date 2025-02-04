
#include "internals.h"

#include <stdlib.h>

#include <stdio.h>

/*
*
*/

/*
* Allocator
*/
typedef void* (*pxlAllocateFun)(size_t size);
typedef void* (*pxlReallocateFun)(void* mem, size_t size);
typedef void  (*pxlDeallocateFun)(void* mem);

typedef struct PXLallocator
{
    pxlAllocateFun allocate;

    pxlReallocateFun reallocate;

    pxlDeallocateFun deallocate;

} PXLallocator;


PXLallocator _pxlAllocator; // Shared Memory Allocator


void* _pxlMalloc(size_t size)
{
    _pxlAllocator.allocate(size);
}

void* _pxlRealloc(void* mem, size_t size)
{
    _pxlAllocator.reallocate(mem, size);
}

void _pxlFree(void* mem)
{
    _pxlAllocator.deallocate(mem);
}

void _pxlUseDefaultAllocater()
{
    _pxlAllocator.allocate = malloc;
    _pxlAllocator.reallocate = realloc;
    _pxlAllocator.deallocate = free;
}

void pxlSetAllocator(PXLallocator* allocator)
{
    if(allocator->allocate && allocator->reallocate && allocator->deallocate)
    {
        _pxlAllocator.allocate = allocator->allocate;
        _pxlAllocator.reallocate = allocator->reallocate;
        _pxlAllocator.deallocate = allocator->deallocate;   
    }
}


/*
*
*/
PXLresult pxlInit()
{
    _pxlUseDefaultAllocater();

    return PXL_SUCCESS;
}


/*
*
*/
void pxlTerminate()
{
}
