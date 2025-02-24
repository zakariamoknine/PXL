#include "internals.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
* Error Manager
*/
static char* _pxlErrorMessages[5] =
{
    "PXLSEGFAULT",
    "\0"
    "Allocator out of memory",
    "Invalid argument(s)",
    "File operation failed, check your provided filepath(s)"
};

static PXL_THREAD_LOCAL char _pxlCurrentThreadError[PXL_MAX_ERROR_LENGTH];
static PXL_THREAD_LOCAL char* _pxlCurrentThreadErrorPtr = NULL;

void _pxlInputError(PXLresult result, const char* description)
{
	if (result == PXL_ERROR && description)
	{
		uint32_t desciption_length = strnlen(description, PXL_MAX_ERROR_LENGTH - 1);
		memcpy(_pxlCurrentThreadError, description, desciption_length);
		_pxlCurrentThreadError[desciption_length] = '\0';
		_pxlCurrentThreadErrorPtr = _pxlCurrentThreadError;
	}
	else
	{
		_pxlCurrentThreadErrorPtr = _pxlErrorMessages[result];
	}
}

PXLAPI const char* pxlGetError(void)
{
    return _pxlCurrentThreadErrorPtr;
}


/*
* Memory Allocator
*/
PXLallocator _pxlAllocator = { NULL, NULL, NULL };


void* _pxlMalloc(size_t size)
{
    return _pxlAllocator.allocate(size);
}

void* _pxlRealloc(void* mem, size_t size)
{
    return _pxlAllocator.reallocate(mem, size);
}

void _pxlFree(void* mem)
{
    _pxlAllocator.deallocate(mem);
}

static void _pxlUseDefaultAllocator(void)
{
    _pxlAllocator.allocate = malloc;
    _pxlAllocator.reallocate = realloc;
    _pxlAllocator.deallocate = free;
}

PXLAPI void pxlSetAllocator(PXLallocator* allocator)
{
    if (allocator->allocate && allocator->reallocate && allocator->deallocate)
    {
        _pxlAllocator.allocate = allocator->allocate;
        _pxlAllocator.reallocate = allocator->reallocate;
        _pxlAllocator.deallocate = allocator->deallocate;
    }
}


/*
*
*/
PXLAPI PXLresult pxlInit(void)
{
	// If a custom allocator is set by the USER, don't use the default allocator
	if (_pxlAllocator.allocate == NULL)
	{
		_pxlUseDefaultAllocator();
	}
	
    return PXL_SUCCESS;
}


/*
*
*/
PXLAPI void pxlTerminate(void)
{
}
