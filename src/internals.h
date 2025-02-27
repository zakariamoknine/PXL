#ifndef _PXL_INTERNALS_H_
#define _PXL_INTERNALS_H_

#include "../include/PXL/PXL.h"

/*
* Thread Local
*/
#if defined(__cplusplus) &&  __cplusplus >= 201103L
 #define PXL_THREAD_LOCAL thread_local
#else
 #define PXL_THREAD_LOCAL __declspec(thread)
#endif


/*
* Error Manager
*/
void _pxlInputError(PXLresult result, const char* description);


#endif // _PXL_INTERNALS_H_
