/*
	File:		AVCFMediaFormat.h
	
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

#ifndef AVCFMEDIAFORMAT_H
#define AVCFMEDIAFORMAT_H

#include <AVFoundationCF/AVCFBase.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

AVCF_EXPORT const CFStringRef AVCFMediaTypeVideo;
AVCF_EXPORT const CFStringRef AVCFMediaTypeAudio;
AVCF_EXPORT const CFStringRef AVCFMediaTypeText;
AVCF_EXPORT const CFStringRef AVCFMediaTypeClosedCaption;
AVCF_EXPORT const CFStringRef AVCFMediaTypeSubtitle;
AVCF_EXPORT const CFStringRef AVCFMediaTypeTimecode;
AVCF_EXPORT const CFStringRef AVCFMediaTypeMetadata;
AVCF_EXPORT const CFStringRef AVCFMediaTypeMuxed;


AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicVisual;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicAudible;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicLegible;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicFrameBased;

AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicContainsOnlyForcedSubtitles;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicIsMainProgramContent;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicIsAuxiliaryContent;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicTranscribesSpokenDialogForAccessibility;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicEasyToRead;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicDescribesMusicAndSoundForAccessibility;
AVCF_EXPORT const CFStringRef AVCFMediaCharacteristicDescribesVideoForAccessibility;

AVCF_EXPORT const CFStringRef AVCFFileTypeQuickTimeMovie;
AVCF_EXPORT const CFStringRef AVCFFileTypeMPEG4;
AVCF_EXPORT const CFStringRef AVCFFileTypeAppleM4V;
AVCF_EXPORT const CFStringRef AVCFFileTypeAppleM4A;
AVCF_EXPORT const CFStringRef AVCFFileType3GPP;
AVCF_EXPORT const CFStringRef AVCFFileTypeCoreAudioFormat;
AVCF_EXPORT const CFStringRef AVCFFileTypeWAVE;
AVCF_EXPORT const CFStringRef AVCFFileTypeAIFF;
AVCF_EXPORT const CFStringRef AVCFFileTypeAIFC;
AVCF_EXPORT const CFStringRef AVCFFileTypeAMR;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFMEDIAFORMAT_H
