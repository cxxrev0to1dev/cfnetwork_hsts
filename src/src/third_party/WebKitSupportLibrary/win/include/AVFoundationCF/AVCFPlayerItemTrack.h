/*
	File:		AVCFPlayerItemTrack.h
	
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

#ifndef AVCFPLAYERITEMTRACK_H
#define AVCFPLAYERITEMTRACK_H

#include <AVFoundationCF/AVCFBase.h>
#include <AVFoundationCF/AVCFAssetTrack.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef struct OpaqueAVCFPlayerItemTrack *AVCFPlayerItemTrackRef;

AVCF_EXPORT AVCFAssetTrackRef AVCFPlayerItemTrackCopyAssetTrack(AVCFPlayerItemTrackRef track);

AVCF_EXPORT Boolean AVCFPlayerItemTrackIsEnabled(AVCFPlayerItemTrackRef track);

AVCF_EXPORT void AVCFPlayerItemTrackSetEnabled(AVCFPlayerItemTrackRef track, Boolean enabled);

AVCF_EXPORT AVCFPlayerItemTrackRef AVCFPlayerItemTrackCopyFallbackTrack(AVCFPlayerItemTrackRef track);

AVCF_EXPORT CFDictionaryRef AVCFPlayerItemTrackCopyLoudnessInfo(AVCFPlayerItemTrackRef track);

AVCF_EXPORT void AVCFPlayerItemTrackSetLoudnessInfo(AVCFPlayerItemTrackRef track, CFDictionaryRef loudnessDict);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFPLAYERITEMTRACK_H
