#ifndef _PXL_H_
#define _PXL_H_



#ifdef __cplusplus
extern "C" {
#endif



#if !defined(_WIN32)
 #error "PXL is Windows only"
#endif


#if defined(_PXL_BUILD_DLL) && defined(PXL_DLL)
 #error "Do not define PXL_DLL as a preprocessor for the PXL API"
#endif


#if defined(_PXL_BUILD_DLL)
 #define PXLAPI __declspec(dllexport)
#elif defined(PXL_DLL)
 #define PXLAPI __declspec(dllimport)
#else
 #define PXLAPI
#endif


#define PXL_MAX_ERROR_LENGTH 256


/*
*
*/
typedef enum PXLresult
{
    PXL_ERROR   = 0,
    PXL_SUCCESS = 1,

    PXL_ERROR_ALLOCATOR_OUT_OF_MEMORY = 2,
    PXL_ERROR_INVALID_ARGUMENTS       = 3,
    PXL_ERROR_FILE_OPERATION_FAILURE  = 4

} PXLresult;


/*
*
*/
typedef struct PXLwindow PXLwindow;


/*
*
*/
PXLAPI PXLresult pxlInit(void);


/*
*
*/
PXLAPI void pxlTerminate(void);


/*
*
*/
PXLAPI const char* pxlGetError(void);



#ifdef __cplusplus
}
#endif



#endif // _PXL_H_
