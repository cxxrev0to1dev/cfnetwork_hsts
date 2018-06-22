/*
	File:		AVCFAssetResourceLoader.h

	Framework:	AVFoundationCF

	Copyright 2010-2012 Apple Inc. All rights reserved.

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

#ifndef AVCFASSETRESOURCELOADER_H
#define AVCFASSETRESOURCELOADER_H

#include <AVFoundationCF/AVCFBase.h>
#include <CFNetwork/CFURLRequest.h>
#include <CoreMedia/CMBaseObject.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef struct OpaqueAVCFAssetResourceLoader *AVCFAssetResourceLoaderRef;
typedef struct OpaqueAVCFAssetResourceLoadingRequest *AVCFAssetResourceLoadingRequestRef;

enum
{
	kAVCFAssetResourceLoader_CallbacksVersion_1 = 1,
};

typedef struct
{
	uint32_t version;
	void *context;
	Boolean (*resourceLoaderShouldWaitForLoadingOfRequestedResource)(AVCFAssetResourceLoaderRef resourceLoader, AVCFAssetResourceLoadingRequestRef loadingRequest, void *context);
} AVCFAssetResourceLoaderCallbacks;

AVCF_EXPORT void AVCFAssetResourceLoaderSetCallbacks(AVCFAssetResourceLoaderRef resourceLoader, const AVCFAssetResourceLoaderCallbacks *callbacks, dispatch_queue_t callbackQueue);

AVCF_EXPORT dispatch_queue_t AVCFAssetResourceLoaderGetCallbackQueue(AVCFAssetResourceLoaderRef resourceLoader);

AVCF_EXPORT CFURLRequestRef AVCFAssetResourceLoadingRequestGetURLRequest(AVCFAssetResourceLoadingRequestRef loadingRequest);

AVCF_EXPORT Boolean AVCFAssetResourceLoadingRequestIsFinished(AVCFAssetResourceLoadingRequestRef loadingRequest);

AVCF_EXPORT void AVCFAssetResourceLoadingRequestFinishLoadingWithResponse(AVCFAssetResourceLoadingRequestRef loadingRequest, CFURLResponseRef response, CFDataRef data, CFURLRequestRef redirect);

AVCF_EXPORT void AVCFAssetResourceLoadingRequestFinishLoadingWithError(AVCFAssetResourceLoadingRequestRef loadingRequest, CFErrorRef error);

AVCF_EXPORT CFDataRef AVCFAssetResourceLoadingRequestCreateStreamingContentKeyRequestDataForApp(AVCFAssetResourceLoadingRequestRef loadingRequest, CFDataRef appIdentifier, CFDataRef contentIdentifier, CFDictionaryRef options, CFErrorRef *outError);
    
#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif  // AVCFASSETRESOURCELOADER_H
