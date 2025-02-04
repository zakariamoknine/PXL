
#ifndef _PXL_INTERNALS_H_
#define _PXL_INTERNALS_H_


/*
* Typedefs
*/
#include <stddef.h>
#include <stdint.h>


/*
* Platform
*/
#if defined(_WIN32)
    #define PXL_PLATFORM_WIN32
#elif defined(__linux__)
    #define PXL_PLATFORM_LINUX
#elif defined(__APPLE__)
    #define PXL_PLATFORM_APPLE
#else
    #error "unknown/unsupported platform"
#endif


/*
* Thread local definition
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
typedef enum PXLresult
{
    PXL_ERROR   = 0,
    PXL_SUCCESS = 1,

    PXL_ERROR_ALLOCATOR_OUT_OF_MEMORY,
    PXL_ERROR_INVALID_ARGUMENTS, 
    PXL_ERROR_FILE_OPERATION_FAILURE

} PXLresult;

void _pxlInputError(const char* description);

const char* pxlGetError();


#endif // _PXL_INTERNALS_H_
