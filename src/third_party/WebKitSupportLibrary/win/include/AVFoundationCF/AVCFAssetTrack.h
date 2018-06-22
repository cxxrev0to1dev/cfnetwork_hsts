/*
	File:		AVCFAssetTrack.h
	
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

#ifndef AVCFASSETTRACK_H
#define AVCFASSETTRACK_H

#include <AVFoundationCF/AVCFBase.h>
#include <AVFoundationCF/AVCFAsynchronousPropertyValueLoading.h>

#include <CoreMedia/CMTime.h>
#include <CoreMedia/CMTimeRange.h>

#include <CoreGraphics/CGGeometry.h>
#include <CoreGraphics/CGAffineTransform.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef struct OpaqueAVCFAsset *AVCFAssetRef;
typedef struct OpaqueAVCFAssetTrack *AVCFAssetTrackRef;

AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyAsset;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyTrackID;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyMediaType;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyFormatDescriptions;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyEnabled;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertySelfContained;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyTotalSampleDataLength;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyTimeRange;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyNaturalTimeScale;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyEstimatedDataRate;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyLanguageCode;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyExtendedLanguageTag;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyNaturalSize;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyPreferredTransform;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyNominalFrameRate;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyCommonMetadata;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyAvailableMetadataFormats;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyFrameReorderingRequired;

AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyPlayable;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyFallbackTrack;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyAssociatedSubtitleTrack;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyPairedForcedOnlySubtitlesTrack;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyContainsMixedSubtitles;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyContainsOnlyForcedSubtitles;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyPreferredVolume;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertySegments;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyLayer;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyExcludedFromAutoselectionInTrackGroup;
AVCF_EXPORT const CFStringRef AVCFAssetTrackPropertyLocale;

AVCF_EXPORT AVCFPropertyValueStatus AVCFAssetTrackGetStatusOfValueForProperty(AVCFAssetTrackRef assetTrack, CFStringRef property, CFErrorRef *errorOut);

typedef void (*AVCFAssetTrackLoadValuesCompletionCallback)(AVCFAssetTrackRef assetTrack, void *clientContext);

AVCF_EXPORT void AVCFAssetTrackLoadValuesAsynchronouslyForProperties(AVCFAssetTrackRef assetTrack, CFArrayRef properties, AVCFAssetTrackLoadValuesCompletionCallback callback, void *clientContext);

AVCF_EXPORT AVCFAssetRef AVCFAssetTrackCopyAsset(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT CMPersistentTrackID AVCFAssetTrackGetTrackID(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT CFStringRef AVCFAssetTrackGetMediaType(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT CFArrayRef AVCFAssetTrackCopyFormatDescriptions(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT Boolean AVCFAssetTrackIsEnabled(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT Boolean AVCFAssetTrackIsSelfContained(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT int64_t AVCFAssetTrackGetTotalSampleDataLength(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT Boolean AVCFAssetTrackHasMediaCharacteristic(AVCFAssetTrackRef assetTrack, CFStringRef mediaCharacteristic);

AVCF_EXPORT CMTimeRange AVCFAssetTrackGetTimeRange(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT CMTimeScale AVCFAssetTrackGetNaturalTimeScale(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT Float32 AVCFAssetTrackGetEstimatedDataRate(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT CFStringRef AVCFAssetTrackCopyLanguageCode(AVCFAssetTrackRef assetTrack);
AVCF_EXPORT CFStringRef AVCFAssetTrackCopyExtendedLanguageTag(AVCFAssetTrackRef assetTrack);
AVCF_EXPORT CGSize AVCFAssetTrackGetNaturalSize(AVCFAssetTrackRef assetTrack);
AVCF_EXPORT CGAffineTransform AVCFAssetTrackGetPreferredTransform(AVCFAssetTrackRef assetTrack);
AVCF_EXPORT void AVCFAssetTrackSetPreferredTransform(AVCFAssetTrackRef assetTrack, CGAffineTransform transform);

AVCF_EXPORT Float32 AVCFAssetTrackGetNominalFrameRate(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT CFArrayRef AVCFAssetTrackCopyCommonMetadata(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT CFArrayRef AVCFAssetTrackCopyAvailableMetadataFormats(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT Boolean AVCFAssetTrackIsFrameReorderingRequired(AVCFAssetTrackRef assetTrack);

AVCF_EXPORT CFArrayRef AVCFAssetTrackCopyMetadataForFormat(AVCFAssetTrackRef assetTrack, CFStringRef format);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFASSETTRACK_H
