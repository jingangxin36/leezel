#pragma once

#ifdef LZ_PLATFORM_WINDOWS
	#ifdef LZ_BUILD_DLL
		#define LEEZEL_CORE_API __declspec(dllexport)
	#else
		#define LEEZEL_CORE_API __declspec(dllimport)
	#endif
#else
	#error "can only support windows"
#endif