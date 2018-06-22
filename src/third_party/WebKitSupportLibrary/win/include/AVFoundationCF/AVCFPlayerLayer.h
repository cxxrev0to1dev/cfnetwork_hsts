/*
	File:		AVCFPlayerLayer.h
	
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

#ifndef AVCFPLAYERLAYER_H
#define AVCFPLAYERLAYER_H

#include <AVFoundationCF/AVCFBase.h>
#include <QuartzCore/CoreAnimationCF.h>
#include <AVFoundationCF/AVCFPlayer.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef struct OpaqueAVCFPlayerLayer *AVCFPlayerLayerRef;

#ifndef DEFINED_AVCF_PLAYER_REF
#define DEFINED_AVCF_PLAYER_REF
typedef struct OpaqueAVCFPlayer *AVCFPlayerRef;
#endif // DEFINED_AVCF_PLAYER_REF

AVCF_EXPORT const CFStringRef AVCFPlayerLayerIsReadyForDisplayChangedNotification;

AVCF_EXPORT AVCFPlayerLayerRef AVCFPlayerLayerCreateWithAVCFPlayer(CFAllocatorRef allocator, AVCFPlayerRef player, dispatch_queue_t notificationQueue);
AVCF_EXPORT Boolean AVCFPlayerLayerIsReadyForDisplay(AVCFPlayerLayerRef playerLayer);

#if AVCF_SUPPORT_CF_COREANIMATION
AVCF_EXPORT CACFLayerRef AVCFPlayerLayerCopyCACFLayer(AVCFPlayerLayerRef playerLayer);
#endif // ! AVCF_SUPPORT_CF_COREANIMATION

AVCF_EXPORT void AVCFPlayerLayerSetFrame(AVCFPlayerLayerRef playerLayer, CGRect frame);
AVCF_EXPORT void AVCFPlayerLayerSetPlayer(AVCFPlayerLayerRef playerLayer, AVCFPlayerRef player);
AVCF_EXPORT AVCFPlayerRef AVCFPlayerLayerCopyPlayer(AVCFPlayerLayerRef playerLayer);

#if AVCF_SUPPORT_CF_COREANIMATION
AVCF_EXPORT void AVCFPlayerLayerSetShouldFlushContext(Boolean shouldFlushContext);
#endif // AVCF_SUPPORT_CF_COREANIMATION

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFPLAYERLAYER_H
