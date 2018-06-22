/*
 MADefinitionsInternal.h
 MediaAccessibility
 
 Copyright (c) 2012 Apple Inc. All rights reserved.
 */

#ifndef MediaAccessibility_Definitions_Windows_h
#define MediaAccessibility_Definitions_Windows_h

#include <CoreFoundation/CFBase.h>

#if TARGET_OS_WIN32
#    ifndef CF_ENUM
#        define CF_ENUM(_type, _name) _type _name; enum
#    endif
#    ifndef CF_OPTIONS
#        define CF_OPTIONS(_type, _name) _type _name; enum
#    endif
#    ifndef CF_ENUM_DEPRECATED
#        define CF_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep)
#    endif
#    ifndef CF_ENUM_AVAILABLE
#        define CF_ENUM_AVAILABLE(_mac, _ios)
#    endif
#endif

#endif
