/*
     File:       CMTime.h
 
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

#ifndef CMTIME_H
#define CMTIME_H

#include <CoreMedia/CMBase.h>
#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef int64_t CMTimeValue;
typedef int32_t CMTimeScale;
#define kCMTimeMaxTimescale 0x7fffffffL
typedef int64_t CMTimeEpoch;

typedef CF_OPTIONS( uint32_t, CMTimeFlags ) {
	kCMTimeFlags_Valid = 1UL<<0,
	kCMTimeFlags_HasBeenRounded = 1UL<<1,
	kCMTimeFlags_PositiveInfinity = 1UL<<2,
	kCMTimeFlags_NegativeInfinity = 1UL<<3,
	kCMTimeFlags_Indefinite = 1UL<<4,
	kCMTimeFlags_ImpliedValueFlagsMask = kCMTimeFlags_PositiveInfinity | kCMTimeFlags_NegativeInfinity | kCMTimeFlags_Indefinite
};

typedef struct
{
	CMTimeValue	value;
	CMTimeScale	timescale;
	CMTimeFlags	flags;
	CMTimeEpoch	epoch;
} CMTime;

#define CMTIME_IS_VALID(time) ((Boolean)(((time).flags & kCMTimeFlags_Valid) != 0))
#define CMTIME_IS_INVALID(time) (! CMTIME_IS_VALID(time))
#define CMTIME_IS_POSITIVE_INFINITY(time) ((Boolean)(CMTIME_IS_VALID(time) && (((time).flags & kCMTimeFlags_PositiveInfinity) != 0)))
#define CMTIME_IS_NEGATIVE_INFINITY(time) ((Boolean)(CMTIME_IS_VALID(time) && (((time).flags & kCMTimeFlags_NegativeInfinity) != 0)))
#define CMTIME_IS_INDEFINITE(time) ((Boolean)(CMTIME_IS_VALID(time) && (((time).flags & kCMTimeFlags_Indefinite) != 0)))
#define CMTIME_IS_NUMERIC(time) ((Boolean)(((time).flags & (kCMTimeFlags_Valid | kCMTimeFlags_ImpliedValueFlagsMask)) == kCMTimeFlags_Valid))
#define CMTIME_HAS_BEEN_ROUNDED(time) ((Boolean)(CMTIME_IS_NUMERIC(time) && (((time).flags & kCMTimeFlags_HasBeenRounded) != 0)))

CM_EXPORT const CMTime kCMTimeInvalid __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT const CMTime kCMTimeIndefinite __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT const CMTime kCMTimePositiveInfinity __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT const CMTime kCMTimeNegativeInfinity __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT const CMTime kCMTimeZero __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeMake(int64_t, int32_t) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeMakeWithEpoch(int64_t, int32_t, int64_t) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeMakeWithSeconds(Float64, int32_t) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT Float64 CMTimeGetSeconds(CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

typedef CF_ENUM( uint32_t, CMTimeRoundingMethod ) {
	kCMTimeRoundingMethod_RoundHalfAwayFromZero = 1,
	kCMTimeRoundingMethod_RoundTowardZero = 2,
	kCMTimeRoundingMethod_RoundAwayFromZero = 3,
	kCMTimeRoundingMethod_QuickTime = 4,
	kCMTimeRoundingMethod_RoundTowardPositiveInfinity = 5,
	kCMTimeRoundingMethod_RoundTowardNegativeInfinity = 6,
	
	kCMTimeRoundingMethod_Default = kCMTimeRoundingMethod_RoundHalfAwayFromZero
};

CM_EXPORT CMTime CMTimeConvertScale(CMTime, int32_t, CMTimeRoundingMethod) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CMTime CMTimeAdd(CMTime, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeSubtract(CMTime, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);CM_EXPORT int32_t CMTimeCompare(CMTime, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeMultiply(CMTime, int32_t) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeMultiplyByFloat64(CMTime, Float64) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeMultiplyByRatio(CMTime, int32_t, int32_t) __OSX_AVAILABLE_STARTING(__MAC_10_10,__IPHONE_7_1);
CM_EXPORT int32_t CMTimeCompare(CMTime, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
#define CMTIME_COMPARE_INLINE(time1, comparator, time2) ((Boolean)(CMTimeCompare(time1, time2) comparator 0))

CM_EXPORT CMTime CMTimeMinimum(CMTime, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeMaximum(CMTime, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeAbsoluteValue(CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CFDictionaryRef CMTimeCopyAsDictionary(CMTime, CFAllocatorRef) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT CMTime CMTimeMakeFromDictionary(CFDictionaryRef) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT const CFStringRef kCMTimeValueKey __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT const CFStringRef kCMTimeScaleKey __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT const CFStringRef kCMTimeEpochKey __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
CM_EXPORT const CFStringRef kCMTimeFlagsKey __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CFStringRef CMTimeCopyDescription(CFAllocatorRef, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT void CMTimeShow(CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif
	
#endif // CMTIME_H
