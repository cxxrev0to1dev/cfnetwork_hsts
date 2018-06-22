/*
 *  CoreText.h
 *	CoreText
 *
 *  Copyright (c) 2006-2011 Apple Inc. All rights reserved.
 *
 */

/*!
    @header

    Thread Safety Information

    All functions in this header are thread safe unless otherwise specified.
*/

#ifndef __CORETEXT__
#define __CORETEXT__

#include <AvailabilityMacros.h>
#include <CoreText/CTDefines.h>
#include <CoreText/CTFontDescriptor.h>

#if defined(__cplusplus)
extern "C" {
#endif

uint32_t CTGetCoreTextVersion( void ) CT_AVAILABLE_STARTING( __MAC_10_5, __IPHONE_3_2);

#define kCTVersionNumber10_5 0x00020000
#define kCTVersionNumber10_5_2 0x00020001
#define kCTVersionNumber10_5_3 0x00020002
#define kCTVersionNumber10_5_5 0x00020003
#define kCTVersionNumber10_6 0x00030000
#define kCTVersionNumber10_7 0x00040000

#if defined(__cplusplus)
}
#endif

#endif // __CORETEXT__

