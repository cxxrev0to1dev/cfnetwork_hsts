/*
	File:  AVFoundationCF.h

	Framework:  AVFoundationCF
 
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

#include <AVFoundationCF/AVCFBase.h>

#include <AVFoundationCF/AVCFAsynchronousPropertyValueLoading.h>
#include <AVFoundationCF/AVCFAsset.h>
#include <AVFoundationCF/AVCFAssetImageGenerator.h>
#include <AVFoundationCF/AVCFAssetTrack.h>
#include <AVFoundationCF/AVCFMediaFormat.h>
#include <AVFoundationCF/AVCFMetadataFormat.h>
#include <AVFoundationCF/AVCFMetadataItem.h>
#include <AVFoundationCF/AVCFPlayer.h>
#include <AVFoundationCF/AVCFPlayerItem.h>
#include <AVFoundationCF/AVCFPlayerItemTrack.h>

#if AVCF_SUPPORT_CF_COREANIMATION || defined(__OBJC__)
#include <AVFoundationCF/AVCFPlayerLayer.h>
#endif // AVCF_SUPPORT_CF_COREANIMATION || defined(__OBJC__)
