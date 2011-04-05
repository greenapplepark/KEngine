/*******************************
*
*	KEngine
*	KPlatform
*	KPlatform.h
*	Created by Keke Xiang
*	2008/06/15
*
********************************/

#ifndef _KPLATFORM_H_
#define _KPLATFORM_H_

#if defined(WIN32)
#include "KPlatformTypes.h"
#include "KPlatformMemory.h"
#elif defined(UNIX)
#include "KPlatformTypes.h"
#include "KPlatformMemory.h"
#else
#error No Playform selected
#endif //WIN32, UNIX

#include "KPlatformBase.h"

#endif //_K_PLATFORM_H_