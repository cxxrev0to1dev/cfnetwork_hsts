/*
	 File:	   CFNetwork/CFURLResponsePriv.h
 
	 Contains:   CFType URL Response private header
  
	 Copyright:   Copyright (c) 2001-2011, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLRESPONSEPRIV__
#define __CFURLRESPONSEPRIV__

#ifndef __CFURLRESPONSE__
#include <CFNetwork/CFURLResponse.h>
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


/* Private accessors*/

/*
 *  CFURLResponseDataIsEncoded
 *		This returns true if the data associated with this response has NOT been decoded
 *		and would have normally been auto-decoded.
 */
CFN_EXPORT Boolean
CFURLResponseDataIsEncoded(CFURLResponseRef resp)		__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_5_0);

/*
 *  _CFURLResponseMustRevalidate()
 *  
 */
CFN_EXPORT Boolean 
_CFURLResponseMustRevalidate(CFURLResponseRef resp)		   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLResponseGetFreshnessLifetime()
 *  
 */
CFN_EXPORT CFTimeInterval 
_CFURLResponseGetFreshnessLifetime(CFURLResponseRef resp)	 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Mutation - hopefully these do not need to become public?*/
/*
 *  CFURLResponseSetExpectedContentLength()
 *  
 */
CFN_EXPORT void 
CFURLResponseSetExpectedContentLength(
  CFURLResponseRef   response,
  SInt64			 length)								  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseSetMIMEType()
 *  
 */
CFN_EXPORT void 
CFURLResponseSetMIMEType(
  CFURLResponseRef   response,
  CFStringRef		mimeType)								__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseSetExpiration()
 *  
 */
CFN_EXPORT void 
CFURLResponseSetExpiration(
  CFURLResponseRef   response,
  CFAbsoluteTime	 expiration)							  __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  CFURLResponseSetRecommendedCachePolicy()
 *  
 */
CFN_EXPORT void 
CFURLResponseSetRecommendedCachePolicy(
  CFURLResponseRef		  response,
  CFURLCacheStoragePolicy   policy)						   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLResponseSetCreationTime()
 *  
 */
CFN_EXPORT void 
_CFURLResponseSetCreationTime(
  CFURLResponseRef   response,
  CFAbsoluteTime	 creationTime)							__OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Archiving*/
/* Do not use outside of Foundation! */
/*
 *  _CFURLResponseCreateArchiveList()
 *  
 */
CFN_EXPORT void 
_CFURLResponseCreateArchiveList(
  CFAllocatorRef	 alloc,
  CFURLResponseRef   response,
  CFIndex *		  version,
  CFTypeRef **	   objects,
  CFIndex *		  objectCount)							 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
 *  _CFURLResponseCreateFromArchiveList()
 *  
 */
CFN_EXPORT CFURLResponseRef 
_CFURLResponseCreateFromArchiveList(
  CFAllocatorRef   alloc,
  CFIndex		  version,
  CFTypeRef *	  objects,
  CFIndex		  objectCount)							   __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/* Returns a dictionary with keys _kCFStreamPropertySSLClientCertificateState, _kCFStreamPropertySSLClientCertificates and kCFStreamPropertySSLPeerCertificates
 This should be cleaned up at some point; right now, this is just what is most convenient for Foundation.  Also note that currently this context is not
 preserved across archiving and unarchiving; I don't know how it's used by the ultimate consumer (usually Safari), so I don't know if it needs
 to be kept alive in the archive.
 */
/*
 *  _CFURLResponseGetSSLCertificateContext()
 *  
 */
CFN_EXPORT CFDictionaryRef 
_CFURLResponseGetSSLCertificateContext(CFURLResponseRef resp) __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);


/*
// We are eventually going to need something like this
typedef struct {
	CFIndex version;
	void *(*retain)(void *info);
	void (*release)(void *info);
	void *(*copy)(void*);
	CFStringRef (*copyDescription)(void *);
	CFPropertyListRef (*createPlist)(void *info);
} CFURLResponseProtocolSpecificDataCallbacks;

const CFURLResponseProtocolSpecificDataCallbacks kCFPropertyListProtocolSpecificDataCallbacks;

void CFURLResponseSetProtocolSpecificData(CFURLResponseRef response, CFStringRef protocolDescription, void *psd, CFURLResponseProtocolSpecificDataCallbacks *psdCallbacks);
#endif
*/

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLRESPONSEPRIV__ */

