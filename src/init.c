#include "internals.h"

#include <windows.h>

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

// static PXL_THREAD_LOCAL char _pxlCurrentThreadError[PXL_MAX_ERROR_LENGTH];
// static PXL_THREAD_LOCAL char* _pxlCurrentThreadErrorPtr = NULL;

void _pxlInputError(PXLresult result, const char* description)
{
	if (result == PXL_ERROR && description)
	{
		// int desciption_length = strnlen(description, PXL_MAX_ERROR_LENGTH - 1);
		// memcpy(_pxlCurrentThreadError, description, desciption_length);
		// _pxlCurrentThreadError[desciption_length] = '\0';
		// _pxlCurrentThreadErrorPtr = _pxlCurrentThreadError;
	}
	else
	{
		// _pxlCurrentThreadErrorPtr = _pxlErrorMessages[result];
	}
}

PXLAPI const char* pxlGetError(void)
{
    // return _pxlCurrentThreadErrorPtr;
	return NULL;
}


/*
*
*/
PXLAPI PXLresult pxlInit(void)
{
    return PXL_SUCCESS;
}


/*
*
*/
PXLAPI void pxlTerminate(void)
{
}
