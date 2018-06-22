/*
	File:		AVCFAsset.h
	
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

#ifndef AVCFASSET_H
#define AVCFASSET_H

#include <AVFoundationCF/AVCFBase.h>
#include <AVFoundationCF/AVCFAsynchronousPropertyValueLoading.h>
#include <AVFoundationCF/AVCFMediaSelectionGroup.h>

#include <CoreGraphics/CGAffineTransform.h>

#include <CoreMedia/CMTime.h>

#include <AVFoundationCF/AVCFAssetResourceLoader.h>
#include <AVFoundationCF/AVCFAssetTrack.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

AVCF_EXPORT CMTime AVCFAssetGetDuration(AVCFAssetRef asset);
AVCF_EXPORT CGAffineTransform AVCFAssetGetPreferredTransform(AVCFAssetRef asset);
AVCF_EXPORT CGSize AVCFAssetGetNaturalSize(AVCFAssetRef asset);
AVCF_EXPORT Boolean AVCFAssetProvidesPreciseDurationAndTiming(AVCFAssetRef asset);

AVCF_EXPORT const CFStringRef AVCFAssetPropertyDuration;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyPreferredRate;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyPreferredTransform;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyNaturalSize;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyTracks;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyLyrics;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyPlayable;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyCommonMetadata;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyAvailableMetadataFormats;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyAvailableChapterLocales; 
AVCF_EXPORT const CFStringRef AVCFAssetPropertyHasCompressedMovieAtom;
AVCF_EXPORT const CFStringRef AVCFAssetPropertyAvailableMediaCharacteristicsWithMediaSelectionOptions;
	
AVCF_EXPORT AVCFPropertyValueStatus AVCFAssetGetStatusOfValueForProperty(AVCFAssetRef asset, CFStringRef property, CFErrorRef *errorOut);

typedef void (*AVCFAssetLoadValuesCompletionCallback)(AVCFAssetRef asset, void *clientContext);
AVCF_EXPORT void AVCFAssetLoadValuesAsynchronouslyForProperties(AVCFAssetRef asset, CFArrayRef properties, AVCFAssetLoadValuesCompletionCallback callback, void *clientContext);
AVCF_EXPORT void AVCFAssetCancelLoading(AVCFAssetRef asset);

AVCF_EXPORT Boolean AVCFAssetIsPlayable(AVCFAssetRef asset);
AVCF_EXPORT Boolean AVCFAssetIsReadable(AVCFAssetRef asset);
AVCF_EXPORT CFArrayRef AVCFAssetCopyAssetTracks(AVCFAssetRef asset);
AVCF_EXPORT CFArrayRef AVCFAssetCopyTracksWithMediaType(AVCFAssetRef asset, CFStringRef mediaType);
AVCF_EXPORT CFArrayRef AVCFAssetCopyTracksWithMediaCharacteristic(AVCFAssetRef asset, CFStringRef mediaCharacteristic);
AVCF_EXPORT CFArrayRef AVCFAssetCopyAvailableMediaCharacteristicsWithMediaSelectionOptions(AVCFAssetRef asset);
AVCF_EXPORT AVCFMediaSelectionGroupRef AVCFAssetGetSelectionGroupForMediaCharacteristic(AVCFAssetRef asset, CFStringRef mediaCharacteristic);

AVCF_EXPORT CFStringRef const AVCFURLAssetPreferPreciseDurationAndTimingKey;

typedef struct OpaqueAVCFAsset *AVCFURLAssetRef;
AVCF_EXPORT AVCFURLAssetRef AVCFURLAssetCreateWithURLAndOptions(CFAllocatorRef allocator, CFURLRef URL, CFDictionaryRef options, dispatch_queue_t notificationQueue);

AVCF_EXPORT CFURLRef AVCFURLAssetCopyURL(AVCFURLAssetRef asset);

AVCF_EXPORT CFArrayRef AVCFURLAssetCopyAudiovisualMIMETypes(void);

AVCF_EXPORT AVCFAssetResourceLoaderRef AVCFURLAssetGetResourceLoader(AVCFURLAssetRef asset);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFASSET_H
