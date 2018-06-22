/*
 *  CTDefines.h
 *  CoreText
 *
 *  Copyright (c) 2010-2011 Apple Inc. All rights reserved.
 *
 */

#ifndef __CTDEFINES__
#define __CTDEFINES__


#if defined(CT_BUILDING_CoreText)
# define CT_AVAILABLE_STARTING(_mac,_iphone)
# define CT_AVAILABLE_BUT_DEPRECATED(_mac,_macDep,_iphone,_iphoneDep)
#else /* defined(CT_BUILDING_CoreText) */
# include <Availability.h>
# define CT_AVAILABLE_STARTING __OSX_AVAILABLE_STARTING
# define CT_AVAILABLE_BUT_DEPRECATED __OSX_AVAILABLE_BUT_DEPRECATED
#endif /* defined(CT_BUILDING_CoreText) */

#if TARGET_OS_WIN32
// @@@@ Maybe we should use __declspec(dllexport) instead of adding symbols to the .def file?
#if !CT_BUILDING_CoreText
#define CT_EXPORT __declspec(dllimport) extern
#else
#define CT_EXPORT extern
#endif
#else
#define CT_EXPORT extern
#endif

#endif // __CTDEFINES__
