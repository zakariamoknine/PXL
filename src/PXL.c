
#include <windows.h>

#if defined(_PXL_BUILD_DLL)

BOOL APIENTRY _DllMainCRTStartup(HANDLE hModule, DWORD hReason, LPVOID lpReserved)
{
    switch (hReason) 
	{
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

#endif
