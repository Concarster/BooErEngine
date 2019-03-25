#pragma once

#ifdef BOO_ENGINE
#ifdef BOO_WINDOW
#ifdef BOO_BUILD_DLL

#define BOO_API __declspec(dllexport)
#else
#define BOO_API __declspec(dllimport)

#endif // BOO_BUILD_DLL

#else
#error BooErEngine only support Windows!

#endif // BOO_WINDOW
#endif // BOO_ENGINE


#ifdef BOO_DEBUG
#define BOO_ENABLE_ASSERTS
#endif

#ifdef BOO_ENABLE_ASSERTS
#define BOO_CLIENT_ASSERT(x, ...) { if(!(x)) { ON_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define BOO_ENGINE_ASSERT(x, ...) { if(!(x)) { ON_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define BOO_ASSERT(x, ...)
#define BOO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BOO_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

//#define _CRTDBG_ALLOC_MEM_DF        0x01  // Turn on debug allocation
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>


