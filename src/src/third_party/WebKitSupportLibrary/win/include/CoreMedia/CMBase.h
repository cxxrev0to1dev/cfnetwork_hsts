/*
     File:       CMBase.h
	
	Framework:  CoreMedia

    (C)  Copyright 2013  Apple Inc.  All rights reserved.

    You may only use this file to build WebKit and for no other purpose.

    THIS SOFTWARE IS PROVIDED BY APPLE INC. "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
    INCLUDING, BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. BE LIABLE FOR ANY 
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
    EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
*/

#ifndef CMBASE_H
#define	CMBASE_H

#include <TargetConditionals.h>
#include <Availability.h>
#include <AvailabilityMacros.h>

// Pre-10.10, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_10
	#define __AVAILABILITY_INTERNAL__MAC_10_10 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-10.7, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_7
	#define __AVAILABILITY_INTERNAL__MAC_10_7 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-4.3, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_4_3
	#define __AVAILABILITY_INTERNAL__IPHONE_4_3 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-10.8, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_8
	#define __AVAILABILITY_INTERNAL__MAC_10_8 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
#ifndef AVAILABLE_MAC_OS_X_VERSION_10_8_AND_LATER
	#define AVAILABLE_MAC_OS_X_VERSION_10_8_AND_LATER WEAK_IMPORT_ATTRIBUTE
#endif
// Pre-6.0, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_6_0
	#define __AVAILABILITY_INTERNAL__IPHONE_6_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// Pre-10.9, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_9
	#define __AVAILABILITY_INTERNAL__MAC_10_9 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
#ifndef AVAILABLE_MAC_OS_X_VERSION_10_9_AND_LATER
	#define AVAILABLE_MAC_OS_X_VERSION_10_9_AND_LATER WEAK_IMPORT_ATTRIBUTE
#endif
// Pre-7.0, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_7_0
#define __AVAILABILITY_INTERNAL__IPHONE_7_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-7.1, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_7_1
#define __AVAILABILITY_INTERNAL__IPHONE_7_1 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-10.10, weak import
#ifndef __AVAILABILITY_INTERNAL__MAC_10_10
#define __AVAILABILITY_INTERNAL__MAC_10_10 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Pre-8.0, weak import
#ifndef __AVAILABILITY_INTERNAL__IPHONE_8_0
#define __AVAILABILITY_INTERNAL__IPHONE_8_0 __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif

// Deprecations
#ifndef __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0
#define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0 WEAK_IMPORT_ATTRIBUTE
#endif

#include <stdint.h>						// int32_t, etc.
#include <stddef.h>						// size_t

#include <CoreFoundation/CFBase.h>		// OSStatus, Boolean, Float32, Float64

#ifdef __cplusplus
extern "C" {
#endif
    
#pragma pack(push, 4)

#if TARGET_OS_MAC
	#define CM_EXPORT extern
	#define VT_EXPORT extern
	#define MT_EXPORT extern
#elif TARGET_OS_WIN32
	#define CM_EXPORT __declspec( dllimport ) extern
	#define VT_EXPORT __declspec( dllimport ) extern
	#define MT_EXPORT __declspec( dllimport ) extern
#else
	#error "specify your platform"
#endif

#if TARGET_OS_WINDOWS && TARGET_CPU_X86_64
typedef int64_t CMItemCount;
typedef int64_t CMItemIndex;
#else
typedef signed long	CMItemCount;
typedef signed long	CMItemIndex;
#endif

typedef int32_t CMPersistentTrackID;
enum {
	kCMPersistentTrackID_Invalid = 0
};

#if !defined(CM_INLINE)
	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		#define CM_INLINE static inline
	#elif defined(__MWERKS__) || defined(__cplusplus)
		#define CM_INLINE static inline
	#elif defined(__GNUC__)
		#define CM_INLINE static __inline__
	#elif defined(_MSC_VER)
		#define CM_INLINE static __inline
	#else
		#define CM_INLINE static    
	#endif
#endif

#pragma pack(pop)
    
#ifdef __cplusplus
}
#endif

#endif // CMBASE_H
