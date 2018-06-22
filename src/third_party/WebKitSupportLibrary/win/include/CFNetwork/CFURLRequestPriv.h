/*
	 File:	   CFNetwork/CFURLRequestPriv.h
 
	 Contains:   CFType URL Request private header
 
	 Copyright:  Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLREQUESTPRIV__
#define __CFURLREQUESTPRIV__

#ifndef __CFURLREQUEST__
#include <CFNetwork/CFURLRequest.h>
#endif

#include <Availability.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif



/* SPI - do not migrate to public API */
/*
 *  _CFURLRequestCreateCopyReplacingURL()
 *  
 */
CFN_EXPORT CFURLRequestRef 
_CFURLRequestCreateCopyReplacingURL(
  CFAllocatorRef	alloc,
  CFURLRequestRef   req,
  CFURLRef		  newURL,
  Boolean		   isMutable)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLRequestCopyProtocolPropertyForKey()
 *  
 */
CFN_EXPORT CFTypeRef 
_CFURLRequestCopyProtocolPropertyForKey(
  CFURLRequestRef   req,
  CFStringRef	   key)									  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLRequestSetProtocolProperty()
 *  
 */
CFN_EXPORT void 
_CFURLRequestSetProtocolProperty(
  CFURLRequestRef   req,
  CFStringRef	   key,
  CFTypeRef		 value)									__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

// kCFURLRequestDoNotDecodeData is a key for use with _CFURLRequestSetProtocolProperty.
// setting its value to kCFBooleanTrue will prevent CFNetwork from automatically decoding
// the data in the response for the given request.  The data will be returned in its encoded state.
CFN_EXPORT const CFStringRef kCFURLRequestDoNotDecodeData	__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);

CFN_EXPORT const CFStringRef kCFURLRequestPreAuthXMMeAuthToken	__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);	
/*
 *  _CFURLRequestCreateArchiveList()
 *  
 */
CFN_EXPORT void 
_CFURLRequestCreateArchiveList(
  CFAllocatorRef	 alloc,
  CFURLRequestRef	req,
  CFIndex *		  version,
  CFTypeRef **	   objects,
  CFIndex *		  objectCount,
  CFDictionaryRef *  protocolProperties)					  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLRequestCreateFromArchiveList()
 *  
 */
CFN_EXPORT CFMutableURLRequestRef 
_CFURLRequestCreateFromArchiveList(
  CFAllocatorRef	alloc,
  CFIndex		   version,
  CFTypeRef *	   objects,
  CFIndex		   objectCount,
  CFDictionaryRef   protocolProperties)					   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLRequestGetProtocolProperties()
 *  
 */
CFN_EXPORT CFDictionaryRef 
_CFURLRequestGetProtocolProperties(CFURLRequestRef req)	   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLRequestGetHTTPMessage()
 *  
 */
CFN_EXPORT CFHTTPMessageRef 
_CFURLRequestGetHTTPMessage(CFURLRequestRef req)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLRequestCopyContentDispositionEncodingFallbackArray()
 *		Returns a copy of the content disposition encoding fallback array
 *		associated with the given request.
 */
CFN_EXPORT CFArrayRef 
_CFURLRequestCopyContentDispositionEncodingFallbackArray(CFURLRequestRef req)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_3_0);

/*
 *  _CFURLRequestSetContentDispositionEncodingFallbackArray()
 *		Sets the provided content disposition encoding fallback array on the
 *		provided mutable request.  This array is consulted when attempting to decode
 *		the content disposition header bytes - the values in the array will be used in
 *		order until the bytes successfully decode into a valid CFString.  If none of the
 *		encodings result in a valid CFString then the original ISOLatin1 string is used.
 *
 *		The array is a CFArray of CFStringEncodiong values (as raw values, not CFNumbers).
 *	
 */
CFN_EXPORT void 
_CFURLRequestSetContentDispositionEncodingFallbackArray(CFMutableURLRequestRef req, CFArrayRef encodingFallbackArray)			  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_3_0);

/*
 * SPI to allow internal clients (such as captive network support for macos) to force a request to be bound to the
 * specified interface (the identifier is the interface name - such as en0
 *
*/
CFN_EXPORT CFStringRef _CFURLRequestCopyBoundInterfaceIdentifier(CFURLRequestRef request) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);
CFN_EXPORT void _CFURLRequestSetBoundInterfaceIdentifier(CFMutableURLRequestRef request, CFStringRef identifier) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);

CFN_EXPORT CFURLStorageSessionRef _CFURLRequestCopyStorageSession(CFURLRequestRef request)	__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);
CFN_EXPORT void _CFURLRequestSetStorageSession(CFMutableURLRequestRef request, CFURLStorageSessionRef session)	__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLREQUESTPRIV__ */

