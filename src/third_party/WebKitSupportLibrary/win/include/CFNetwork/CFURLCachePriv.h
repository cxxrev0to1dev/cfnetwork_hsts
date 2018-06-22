/*
	 File:	   CFNetwork/CFURLCachePriv.h
 
	 Contains:   CFType URL Cache header
 
	 Copyright:  Copyright (c) 2001-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCACHEPRIV__
#define __CFURLCACHEPRIV__

#ifndef __CFNETWORKCORETYPES__
#include <CFNetwork/CFNetworkCoreTypesPriv.h>
#endif

#ifndef __CFURLCACHE__
#include <CFNetwork/CFURLCache.h>
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


/*  True SPI*/
/*
 *  _CFURLCacheCopyCacheDirectory()
 *  
 */
CFN_EXPORT CFStringRef 
_CFURLCacheCopyCacheDirectory(CFURLCacheRef cacheRef)		 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 *  _CFURLCacheLoadMemoryFromDiskNow()
 *  
 */
CFN_EXPORT void 
_CFURLCacheLoadMemoryFromDiskNow(CFURLCacheRef cacheRef)		 __OSX_AVAILABLE_STARTING(__MAC_10_5,__IPHONE_2_0);

/*
 *  _CFURLCachePersistMemoryToDiskNow()
 *  
 */	
CFN_EXPORT void 
_CFURLCachePersistMemoryToDiskNow(CFURLCacheRef cacheRef)		 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_3_2);

/*
 *  _CFURLCachePurgeMemoryCache()
 *  
 */
CFN_EXPORT void 
_CFURLCachePurgeMemoryCache(CFURLCacheRef cacheRef)		 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_3_2);

/*
 *  _CFURLCacheGetSharedCache()
 *  
 */
CFN_EXPORT CFURLCacheRef 
_CFURLCacheGetSharedCache(void)								__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_2_0);	
	
/*
 *  _CFURLCacheDeletePersistentCacheStore()
 *  bundleID - required
 *	fileID - optional
 */
CFN_EXPORT void 
_CFURLCacheDeletePersistentCacheStore(CFStringRef bundleID, CFStringRef fileID)	__OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);	


CFN_EXPORT CFArrayRef 
_CFURLCacheCopyAllHostNamesInPersistentStore(CFURLCacheRef cacheRef);	

CFN_EXPORT void 
_CFURLCacheDeleteHostNamesInPersistentStore(CFURLCacheRef cacheRef, CFArrayRef hosts);	
	
CFN_EXPORT void
_CFURLCacheSetMaxNumOfTasksForProcessing(CFURLCacheRef cacheRef, CFIndex maxNumOfTasks);
	
#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCACHEPRIV__ */

