#ifndef _PXL_INTERNALS_H_
#define _PXL_INTERNALS_H_

#include "../include/PXL/PXL.h"

/*
* Typedefs
*/
#include <stddef.h>
#include <stdint.h>


/*
* Thread Local
*/
#if defined(__cplusplus) &&  __cplusplus >= 201103L
 #define PXL_THREAD_LOCAL thread_local
#elif defined(__GNUC__)
 #define PXL_THREAD_LOCAL __thread
#elif defined(_MSC_VER)
 #define PXL_THREAD_LOCAL __declspec(thread)
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && !defined(__STDC_NO_THREADS__)
 #define PXL_THREAD_LOCAL _Thread_local
#endif


/*
* Memory Allocator
*/
void* _pxlMalloc(size_t size);

void* _pxlRealloc(void* mem, size_t size);

void _pxlFree(void* mem);


/*
* Error Manager
*/
void _pxlInputError(PXLresult result, const char* description);


#endif // _PXL_INTERNALS_H_
