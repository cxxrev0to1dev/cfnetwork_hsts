/*
     File:       CMTimeRange.h
 
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

#ifndef CMTIMERANGE_H
#define CMTIMERANGE_H

#include <CoreMedia/CMBase.h>
#include <CoreMedia/CMTime.h>
#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef struct
{
	CMTime			start;		/*! @field start The start time of the time range. */
	CMTime			duration;	/*! @field duration The duration of the time range. */
} CMTimeRange;

typedef struct 
{
	CMTimeRange source; // eg, media.  source.start is kCMTimeInvalid for empty edits.
	CMTimeRange target; // eg, track.
} CMTimeMapping;

#define CMTIMERANGE_IS_VALID(range) ((Boolean)(CMTIME_IS_VALID(range.start) && CMTIME_IS_VALID(range.duration) && (range.duration.epoch == 0) && (range.duration.value >= 0)))
#define CMTIMERANGE_IS_INVALID(range) (! CMTIMERANGE_IS_VALID(range))
#define CMTIMERANGE_IS_INDEFINITE(range) ((Boolean)(CMTIMERANGE_IS_VALID(range) && (CMTIME_IS_INDEFINITE(range.start) || CMTIME_IS_INDEFINITE(range.duration))))
#define CMTIMERANGE_IS_EMPTY(range) ((Boolean)(CMTIMERANGE_IS_VALID(range) && (CMTIME_COMPARE_INLINE(range.duration, ==, kCMTimeZero))))

CM_EXPORT const CMTimeRange kCMTimeRangeZero __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);		

CM_EXPORT const CMTimeRange kCMTimeRangeInvalid __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CMTimeRange CMTimeRangeMake(CMTime, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
 
CM_EXPORT CMTimeRange CMTimeRangeGetUnion(CMTimeRange, CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CMTimeRange CMTimeRangeGetIntersection(CMTimeRange, CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT Boolean CMTimeRangeEqual(CMTimeRange, CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT Boolean CMTimeRangeContainsTime(CMTimeRange, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT Boolean CMTimeRangeContainsTimeRange(CMTimeRange, CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);


CM_EXPORT CMTime CMTimeRangeGetEnd(CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CMTime CMTimeMapTimeFromRangeToRange(CMTime, CMTimeRange, CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CMTime CMTimeClampToRange(CMTime,  CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CMTime CMTimeMapDurationFromRangeToRange(CMTime, CMTimeRange, CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	
CM_EXPORT CMTimeRange CMTimeRangeFromTimeToTime(CMTime, CMTime) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CFDictionaryRef CMTimeRangeCopyAsDictionary(CMTimeRange, CFAllocatorRef) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CMTimeRange CMTimeRangeMakeFromDictionary(CFDictionaryRef) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT const CFStringRef kCMTimeRangeStartKey __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT const CFStringRef kCMTimeRangeDurationKey __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT CFStringRef CMTimeRangeCopyDescription(CFAllocatorRef, CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

CM_EXPORT void CMTimeRangeShow(CMTimeRange) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif
	
#endif // CMTIMERANGE_H
