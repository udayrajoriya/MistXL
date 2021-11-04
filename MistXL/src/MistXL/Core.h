#pragma once

#ifdef MXL_PLATFORM_WINDOWS
	#ifdef MXL_BUILD_DLL
		#define MISTXL_API __declspec(dllexport)
	#else
		#define MISTXL_API __declspec(dllimport)
	#endif
#else
	#error MistXL only supports Windows.
#endif