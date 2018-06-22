/*
	File:		AVCFPlayerItem.h
	
	Framework:	AVFoundationCF
	
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
#ifndef AVCFPLAYERITEM_H
#define AVCFPLAYERITEM_H

#include <AVFoundationCF/AVCFBase.h>

#include <CoreMedia/CMTime.h>
#include <CoreMedia/CMTimeRange.h>

#include <AVFoundationCF/AVCFAsset.h>
#include <AVFoundationCF/AVCFMediaSelectionGroup.h>
#include <AVFoundationCF/AVCFPlayerItemOutput.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

enum {
	AVCFPlayerItemStatusUnknown,
	AVCFPlayerItemStatusReadyToPlay,
	AVCFPlayerItemStatusFailed,
};
typedef CFIndex AVCFPlayerItemStatus;

typedef struct OpaqueAVCFPlayerItem *AVCFPlayerItemRef;

AVCF_EXPORT const CFStringRef AVCFPlayerItemDidPlayToEndTimeNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemStatusChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemTracksChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemIsPlaybackLikelyToKeepUpChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemIsPlaybackBufferFullChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemIsPlaybackBufferEmptyChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemSeekableTimeRangesChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemLoadedTimeRangesChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemPresentationSizeChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemTimedMetadataChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerItemDurationChangedNotification;

AVCF_EXPORT AVCFPlayerItemRef AVCFPlayerItemCreateWithURL(CFAllocatorRef allocator, CFURLRef URL, dispatch_queue_t notificationQueue);
AVCF_EXPORT AVCFPlayerItemRef AVCFPlayerItemCreateWithAsset(CFAllocatorRef allocator, AVCFAssetRef asset, dispatch_queue_t notificationQueue);
AVCF_EXPORT AVCFPlayerItemStatus AVCFPlayerItemGetStatus(AVCFPlayerItemRef playerItem, CFErrorRef *errorOut);
AVCF_EXPORT CMTime AVCFPlayerItemGetCurrentTime(AVCFPlayerItemRef playerItem);
AVCF_EXPORT CMTime AVCFPlayerItemGetDuration(AVCFPlayerItemRef playerItem);
AVCF_EXPORT void AVCFPlayerItemSeekToTime(AVCFPlayerItemRef playerItem, CMTime time);

typedef void (*AVCFPlayerItemSeekCompletionCallback)(AVCFPlayerItemRef playerItem, Boolean finished, void *context);

AVCF_EXPORT void AVCFPlayerItemSeekToTimeWithCompletionCallback(AVCFPlayerItemRef playerItem, CMTime time, AVCFPlayerItemSeekCompletionCallback completionCallback,  void *context);

AVCF_EXPORT void AVCFPlayerItemSeekToTimeWithTolerance(AVCFPlayerItemRef playerItem, CMTime time, CMTime toleranceBefore, CMTime toleranceAfter);

AVCF_EXPORT void AVCFPlayerItemSeekToTimeWithToleranceAndCompletionCallback(AVCFPlayerItemRef playerItem, CMTime time, CMTime toleranceBefore, CMTime toleranceAfter, AVCFPlayerItemSeekCompletionCallback completionCallback, void *context);

AVCF_EXPORT void AVCFPlayerItemCancelPendingSeeks(AVCFPlayerItemRef playerItem);

AVCF_EXPORT Boolean AVCFPlayerItemSeekToDate(AVCFPlayerItemRef playerItem, CFDateRef date);

AVCF_EXPORT void AVCFPlayerItemStepByCount(AVCFPlayerItemRef playerItem, CFIndex stepCount);

AVCF_EXPORT AVCFAssetRef AVCFPlayerItemGetAsset(AVCFPlayerItemRef playerItem);
AVCF_EXPORT CFArrayRef AVCFPlayerItemCopyTracks(AVCFPlayerItemRef playerItem);
AVCF_EXPORT CGSize AVCFPlayerItemGetPresentationSize(AVCFPlayerItemRef playerItem);
AVCF_EXPORT CMTime AVCFPlayerItemGetForwardPlaybackEndTime(AVCFPlayerItemRef playerItem);
AVCF_EXPORT void AVCFPlayerItemSetForwardPlaybackEndTime(AVCFPlayerItemRef playerItem, CMTime time);
AVCF_EXPORT CMTime AVCFPlayerItemGetReversePlaybackEndTime(AVCFPlayerItemRef playerItem);
AVCF_EXPORT void AVCFPlayerItemSetReversePlaybackEndTime(AVCFPlayerItemRef playerItem, CMTime time);
AVCF_EXPORT Boolean AVCFPlayerItemIsPlaybackLikelyToKeepUp(AVCFPlayerItemRef playerItem);
AVCF_EXPORT Boolean AVCFPlayerItemIsPlaybackBufferFull(AVCFPlayerItemRef playerItem);
AVCF_EXPORT Boolean AVCFPlayerItemIsPlaybackBufferEmpty(AVCFPlayerItemRef playerItem);
AVCF_EXPORT CFArrayRef AVCFPlayerItemCopySeekableTimeRanges(AVCFPlayerItemRef playerItem);
AVCF_EXPORT CFArrayRef AVCFPlayerItemCopyLoadedTimeRanges(AVCFPlayerItemRef playerItem);
AVCF_EXPORT void AVCFPlayerItemSelectMediaOptionInMediaSelectionGroup(AVCFPlayerItemRef playerItem, AVCFMediaSelectionOptionRef selectionOption, AVCFMediaSelectionGroupRef selectionGroup);
AVCF_EXPORT void AVCFPlayerItemSelectMediaOptionAutomaticallyInMediaSelectionGroup(AVCFPlayerItemRef playerItem, AVCFMediaSelectionGroupRef selectionGroup);
AVCF_EXPORT AVCFMediaSelectionOptionRef AVCFPlayerItemGetSelectedMediaOptionInMediaSelectionGroup(AVCFPlayerItemRef playerItem, AVCFMediaSelectionGroupRef selectionGroup);
AVCF_EXPORT void AVCFPlayerItemAddOutput	(AVCFPlayerItemRef playerItem, AVCFPlayerItemOutputRef output);
AVCF_EXPORT void AVCFPlayerItemRemoveOutput	(AVCFPlayerItemRef playerItem, AVCFPlayerItemOutputRef output);
AVCF_EXPORT CFArrayRef AVCFPlayerItemCopyOutputs	(AVCFPlayerItemRef playerItem);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFPLAYERITEM_H
