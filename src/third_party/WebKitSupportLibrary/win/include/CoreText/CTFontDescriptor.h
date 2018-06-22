/*
 *  CTFontDescriptor.h
 *  CoreText
 *
 *  Copyright (c) 2006-2011 Apple Inc. All rights reserved.
 *
 */

/*!
    @header

    Thread Safety Information

    All functions in this header are thread safe unless otherwise specified.
*/

#ifndef __CTFONTDESCRIPTOR__
#define __CTFONTDESCRIPTOR__

#include <CoreText/CTDefines.h>

#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFCharacterSet.h>
#include <CoreFoundation/CFData.h>
#include <CoreFoundation/CFDictionary.h>
#include <CoreFoundation/CFSet.h>
#include <CoreGraphics/CGAffineTransform.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef const struct __CTFontDescriptor * CTFontDescriptorRef;

CFTypeID CTFontDescriptorGetTypeID( void ) CT_AVAILABLE_STARTING( __MAC_10_5, __IPHONE_3_2);

CT_EXPORT const CFStringRef kCTFontNameAttribute CT_AVAILABLE_STARTING( __MAC_10_5, __IPHONE_3_2);

CFTypeRef CTFontDescriptorCopyAttribute(CTFontDescriptorRef, CFStringRef) CT_AVAILABLE_STARTING( __MAC_10_5, __IPHONE_3_2);

#if defined(__cplusplus)
}
#endif

#endif
