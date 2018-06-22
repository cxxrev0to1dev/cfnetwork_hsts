/*
	File:		AVCFAssetImageGenerator.h
	
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

#ifndef AVCFASSETIMAGEGENERATOR_H
#define AVCFASSETIMAGEGENERATOR_H

#include <AVFoundationCF/AVCFBase.h>

#include <CoreGraphics/CGImage.h>
#include <CoreMedia/CMTime.h>

#include <AVFoundationCF/AVCFBase.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef struct OpaqueAVCFAssetImageGenerator *AVCFAssetImageGeneratorRef;

AVCF_EXPORT const CFStringRef AVCFAssetImageGeneratorApertureModeCleanAperture;

AVCF_EXPORT const CFStringRef AVCFAssetImageGeneratorApertureModeProductionAperture;

AVCF_EXPORT const CFStringRef AVCFAssetImageGeneratorApertureModeEncodedPixels;

enum
{
	AVCFAssetImageGeneratorSucceeded,
	AVCFAssetImageGeneratorFailed,
	AVCFAssetImageGeneratorCancelled,
};
typedef CFIndex AVCFAssetImageGeneratorResult;

AVCF_EXPORT AVCFAssetImageGeneratorRef AVCFAssetImageGeneratorCreateWithAsset(CFAllocatorRef allocator, AVCFAssetRef asset);

AVCF_EXPORT Boolean AVCFAssetImageGeneratorAppliesPreferredTrackTransform(AVCFAssetImageGeneratorRef generator);
AVCF_EXPORT void AVCFAssetImageGeneratorSetAppliesPreferredTrackTransform(AVCFAssetImageGeneratorRef generator, Boolean appliesTransfrom);

AVCF_EXPORT CGSize AVCFAssetImageGeneratorGetMaximumSize(AVCFAssetImageGeneratorRef generator);
AVCF_EXPORT void AVCFAssetImageGeneratorSetMaximumSize(AVCFAssetImageGeneratorRef generator, CGSize maxSize);

AVCF_EXPORT CFStringRef AVCFAssetImageGeneratorGetApertureMode(AVCFAssetImageGeneratorRef generator);
AVCF_EXPORT void AVCFAssetImageGeneratorSetApertureMode(AVCFAssetImageGeneratorRef generator, CFStringRef mode);

AVCF_EXPORT CMTime AVCFAssetImageGeneratorGetRequestedTimeToleranceBefore(AVCFAssetImageGeneratorRef generator);
AVCF_EXPORT void AVCFAssetImageGeneratorSetRequestedTimeToleranceBefore(AVCFAssetImageGeneratorRef generator, CMTime toleranceBefore);
AVCF_EXPORT CMTime AVCFAssetImageGeneratorGetRequestedTimeToleranceAfter(AVCFAssetImageGeneratorRef generator);
AVCF_EXPORT void AVCFAssetImageGeneratorSetRequestedTimeToleranceAfter(AVCFAssetImageGeneratorRef generator, CMTime toleranceAfter);

AVCF_EXPORT CGImageRef AVCFAssetImageGeneratorCopyCGImageAtTime(AVCFAssetImageGeneratorRef generator, CMTime requestedTime, CMTime *actualTimeOut, CFErrorRef *errorOut);

typedef void (*AVCFAssetImageGeneratorCompletionCallback)(AVCFAssetImageGeneratorRef generator, CMTime requestedTime, CGImageRef image, CMTime actualTime, AVCFAssetImageGeneratorResult result, CFErrorRef error, void *context);

AVCF_EXPORT void AVCFAssetImageGeneratorGenerateCGImagesAsynchronouslyForTimes(AVCFAssetImageGeneratorRef generator, CFArrayRef requestedTimes, AVCFAssetImageGeneratorCompletionCallback callback, void *context);

AVCF_EXPORT void AVCFAssetImageGeneratorCancelAllCGImageGeneration(AVCFAssetImageGeneratorRef generator);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFASSETIMAGEGENERATOR_H
