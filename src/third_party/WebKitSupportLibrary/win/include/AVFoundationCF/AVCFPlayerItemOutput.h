/*
 File:		AVCFPlayerItemOutput.h
 
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

#ifndef AVFoundationCF_AVCFPlayerItemOutput_h
#define AVFoundationCF_AVCFPlayerItemOutput_h

#include <CoreMedia/CMTime.h>

#ifdef __cplusplus
extern "C" {
#endif
	
#pragma pack(push, 4)

typedef struct OpaqueAVCFPlayerItemOutput *AVCFPlayerItemOutputRef;


AVCF_EXPORT CMTime AVCFPlayerItemOutputItemTimeForHostTime(AVCFPlayerItemOutputRef output, CFTimeInterval hostTimeInSeconds);

AVCF_EXPORT CMTime AVCFPlayerItemOutputItemTimeForHostUpTime(AVCFPlayerItemOutputRef output, int64_t hostUpTime);

AVCF_EXPORT void	AVCFPlayerItemOutputSetSuppressPlayerRendering	(AVCFPlayerItemOutputRef output, Boolean suppressed);
AVCF_EXPORT Boolean	AVCFPlayerItemOutputGetSuppressPlayerRendering	(AVCFPlayerItemOutputRef output);

#pragma pack(pop)	
	
#ifdef __cplusplus
}
#endif

#endif
