/*
 File:		AVCFPlayerItemLegibleOutput.h
 
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

#ifndef AVFoundationCF_AVCFPlayerItemLegibleOutput_h
#define AVFoundationCF_AVCFPlayerItemLegibleOutput_h

#include <AVFoundationCF/AVCFPlayerItemOutput.h>

#ifdef __cplusplus
extern "C" {
#endif
	
#pragma pack(push, 4)
	
typedef AVCFPlayerItemOutputRef AVCFPlayerItemLegibleOutputRef;

AVCF_EXPORT CFTypeID AVCFPlayerItemLegibleOutputGetTypeID(void);
AVCF_EXPORT AVCFPlayerItemLegibleOutputRef AVCFPlayerItemLegibleOutputCreateWithMediaSubtypesForNativeRepresentation(CFAllocatorRef allocator, CFArrayRef subtypes);

typedef void (*AVCFPlayerItemLegibleOutputCallbackPtr)(
				void*		context,
				AVCFPlayerItemLegibleOutputRef legibleOutput,
				CFArrayRef	attributedStrings,
				CFArrayRef	nativeSampleBuffers,
				CMTime		itemTime);
enum
{
	kAVCFPlayerItemLegibleOutput_CallbacksVersion_1 = 1
};

typedef struct _AVCFPlayerItemLegibleOutputCallbacks
{
	uint32_t	version;										// must be kAVCFPlayerItemLegibleOutput_CallbacksVersion_1
	void*		context;										// must be passed back with the callback
	AVCFPlayerItemLegibleOutputCallbackPtr legibleOutputCallback;
	
} AVCFPlayerItemLegibleOutputCallbacks;

AVCF_EXPORT void AVCFPlayerItemLegibleOutputSetCallbacks(AVCFPlayerItemLegibleOutputRef legibleOutput,
						const AVCFPlayerItemLegibleOutputCallbacks *callbacks, dispatch_queue_t callbackQueue);
AVCF_EXPORT CFTimeInterval	AVCFPlayerItemLegibleOutputGetAdvanceIntervalForCallbackInvocation(AVCFPlayerItemLegibleOutputRef legibleOutput);
AVCF_EXPORT void			AVCFPlayerItemLegibleOutputSetAdvanceIntervalForCallbackInvocation(AVCFPlayerItemLegibleOutputRef legibleOutput, CFTimeInterval timeInterval);
	
AVCF_EXPORT const CFStringRef AVCFPlayerItemLegibleOutputTextStylingResolutionDefault;

AVCF_EXPORT const CFStringRef AVCFPlayerItemLegibleOutputTextStylingResolutionSourceAndRulesOnly;
	
AVCF_EXPORT CFStringRef AVCFPlayerItemLegibleOutputCopyTextStylingResolution(AVCFPlayerItemLegibleOutputRef legibleOutput);
AVCF_EXPORT void		AVCFPlayerItemLegibleOutputSetTextStylingResolution	(AVCFPlayerItemLegibleOutputRef legibleOutput, CFStringRef textStylingResolutions);

#pragma pack(pop)
	
#ifdef __cplusplus
}
#endif
#endif //AVFoundationCF_AVCFPlayerItemLegibleOutput_h
