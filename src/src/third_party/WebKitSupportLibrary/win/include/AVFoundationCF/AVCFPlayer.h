/*
	File:		AVCFPlayer.h
	
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

#ifndef AVCFPLAYER_H
#define AVCFPLAYER_H

#include <AVFoundationCF/AVCFBase.h>
#include <AVFoundationCF/AVCFPlayerItem.h>

#include <CoreMedia/CMTime.h>
#include <CoreMedia/CMTimeRange.h>

#include <CoreFoundation/CFURL.h>
#include <CoreFoundation/CFError.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef struct OpaqueAVCFPlayer *AVCFPlayerRef;

enum {
	AVCFPlayerStatusUnknown,
	AVCFPlayerStatusReadyToPlay,
	AVCFPlayerStatusFailed
};
typedef CFIndex AVCFPlayerStatus;

enum
{
	AVCFPlayerActionAtItemEndPause = 1,
	AVCFPlayerActionAtItemEndNone  = 2,
};
typedef CFIndex AVCFPlayerActionAtItemEnd;

AVCF_EXPORT const CFStringRef AVCFPlayerStatusChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerRateChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerVolumeChangedNotification;
AVCF_EXPORT const CFStringRef AVCFPlayerIsMutedChangedNotification;

AVCF_EXPORT const CFStringRef AVCFPlayerAppliesMediaSelectionCriteriaAutomaticallyKey;

AVCF_EXPORT const CFStringRef AVCFPlayerMediaSelectionCriteriaKey;
AVCF_EXPORT const CFStringRef AVCFPlayerMediaSelectionCriteriaPreferredLanguagesKey;
AVCF_EXPORT const CFStringRef AVCFPlayerMediaSelectionCriteriaPreferredCharacteristicsKey;

AVCF_EXPORT AVCFPlayerRef AVCFPlayerCreateWithURLAndOptions(CFAllocatorRef allocator, CFURLRef URL, CFDictionaryRef options, dispatch_queue_t notificationQueue);

AVCF_EXPORT AVCFPlayerRef AVCFPlayerCreateWithPlayerItemAndOptions(CFAllocatorRef allocator, AVCFPlayerItemRef playerItem, CFDictionaryRef options, dispatch_queue_t notificationQueue);

AVCF_EXPORT dispatch_queue_t AVCFPlayerGetNotificationQueue(AVCFPlayerRef player);	

AVCF_EXPORT AVCFPlayerStatus AVCFPlayerGetStatus(AVCFPlayerRef player, CFErrorRef *errorOut);

AVCF_EXPORT Float32 AVCFPlayerGetRate(AVCFPlayerRef player);
AVCF_EXPORT void AVCFPlayerSetRate(AVCFPlayerRef player, Float32 rate);

AVCF_EXPORT AVCFPlayerActionAtItemEnd AVCFPlayerGetActionAtItemEnd(AVCFPlayerRef player);
AVCF_EXPORT OSStatus AVCFPlayerSetActionAtItemEnd(AVCFPlayerRef player, AVCFPlayerActionAtItemEnd action);

AVCF_EXPORT Float32 AVCFPlayerGetVolume(AVCFPlayerRef player);
AVCF_EXPORT void AVCFPlayerSetVolume(AVCFPlayerRef player, Float32 volume);

AVCF_EXPORT Boolean AVCFPlayerIsMuted(AVCFPlayerRef player);
AVCF_EXPORT void AVCFPlayerSetMuted(AVCFPlayerRef player, Boolean muted);

AVCF_EXPORT Boolean AVCFPlayerIsClosedCaptionDisplayEnabled(AVCFPlayerRef player);
AVCF_EXPORT void AVCFPlayerSetClosedCaptionDisplayEnabled(AVCFPlayerRef player, Boolean enabled);

AVCF_EXPORT CFStringRef AVCFPlayerCopyAudioDeviceUID(AVCFPlayerRef player);
AVCF_EXPORT void AVCFPlayerSetAudioDeviceUID(AVCFPlayerRef player, CFStringRef audioDeviceUID);

AVCF_EXPORT CMTime AVCFPlayerGetCurrentTime(AVCFPlayerRef player);

AVCF_EXPORT void AVCFPlayerSeekToTime(AVCFPlayerRef player, CMTime time);

AVCF_EXPORT void AVCFPlayerSeekToTimeWithTolerance(AVCFPlayerRef player, CMTime time, CMTime toleranceBefore, CMTime toleranceAfter);

typedef void (*AVCFPlayerSeekCompletionCallback)(AVCFPlayerRef player, Boolean finished, void *context);

AVCF_EXPORT void AVCFPlayerSeekToTimeWithCompletionCallback(AVCFPlayerRef player, CMTime time, AVCFPlayerSeekCompletionCallback completionCallback,  void *context);

AVCF_EXPORT void AVCFPlayerSeekToTimeWithToleranceAndCompletionCallback(AVCFPlayerRef player, CMTime time, CMTime toleranceBefore, CMTime toleranceAfter, AVCFPlayerSeekCompletionCallback completionCallback, void *context);

AVCF_EXPORT AVCFPlayerItemRef AVCFPlayerCopyCurrentItem(AVCFPlayerRef player);

AVCF_EXPORT void AVCFPlayerPlay(AVCFPlayerRef player);

AVCF_EXPORT void AVCFPlayerPause(AVCFPlayerRef player);

typedef struct OpaqueAVCFPlayerObserver *AVCFPlayerObserverRef;

typedef void (*AVCFPlayerPeriodicTimeObserverCallback)(AVCFPlayerRef player, CMTime time, void *clientContext);
AVCF_EXPORT AVCFPlayerObserverRef AVCFPlayerCreatePeriodicTimeObserverForInterval(AVCFPlayerRef player, CMTime interval, dispatch_queue_t queue, AVCFPlayerPeriodicTimeObserverCallback callback, void *clientContext);

typedef void (*AVCFPlayerBoundaryTimeObserverCallback)(AVCFPlayerRef player, void *clientContext);

AVCF_EXPORT AVCFPlayerObserverRef AVCFPlayerCreateBoundaryTimeObserverForTimes(AVCFPlayerRef player, CFArrayRef times, dispatch_queue_t queue, AVCFPlayerBoundaryTimeObserverCallback callback, void *clientContext);

AVCF_EXPORT OSStatus AVCFPlayerRemoveObserver(AVCFPlayerRef player, AVCFPlayerObserverRef observer);

AVCF_EXPORT CFDictionaryRef AVCFPlayerCopyMediaSelectionCriteriaForMediaCharacteristic(AVCFPlayerRef player, CFStringRef mediaCharacteristic);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFPLAYER_H
