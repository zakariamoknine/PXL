
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
#elif __linux__
 #define PXL_PLATFORM_LINUX
#elif __APPLE__
 #define PXL_PLATFORM_APPLE
#else
 #error "unknown/unsupported platform"
#endif


/*
* Allocators
*/
void* _pxlMalloc(size_t size);

void* _pxlRealloc(void* mem, size_t size);

void _pxlFree(void* mem);


/*
* Error handler
*/
typedef enum PXLresult
{
    PXL_ERROR   = 0,
    PXL_SUCCESS = 1,

    PXL_ERROR_ALLOCATOR_OUT_OF_MEMORY  = 2,
    PXL_ERROR_INVALID_ARGUMENTS        = 3,
    PXL_ERROR_FILE_OPERATION_FAILURE   = 4

} PXLresult;

void _pxlInputError(const char* description);

const char* pxlGetError();

#endif // _PXL_INTERNALS_H_
