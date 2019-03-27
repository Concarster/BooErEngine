#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/* LOG */
#include "BooErEngine\Utils\Log.h"

/* BOOST */

/* Window */
#ifdef BOO_WINDOW

#include <Windows.h>

#endif // BOO_WINDOW

/* To detect Memory Leak */
//#ifdef BOO_DEBUG
//
//#define _CRTDBG_ALLOC_MEM_DF        0x01  // Turn on debug allocation
//#define _CRTDBG_MAP_ALLOC
//
//#include <stdlib.h>                       // Need to be Include
//#include <crtdbg.h>
//
//#endif // BOO_DEBUG