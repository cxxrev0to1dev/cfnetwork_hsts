/*
	File:		AVCFBase.h
	
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

#ifndef AVCFBASE_H
#define AVCFBASE_H

#include <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)
	
#ifndef BUILDING_AVCF_DLL
#define BUILDING_AVCF_DLL 0
#endif // BUILDING_AVCF_DLL
	
#if TARGET_OS_MAC
	#define AVCF_EXPORT extern
#elif TARGET_OS_WIN32
	#if BUILDING_AVCF_DLL
		#define AVCF_EXPORT __declspec( dllexport ) extern
	#else // ! BUILDING_AVCF_DLL
		#define AVCF_EXPORT __declspec( dllimport ) extern
	#endif // ! BUILDING_AVCF_DLL
#else
	#error "specify your platform"
#endif
	
#if !defined(AVCF_INLINE)
	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		#define AVCF_INLINE static inline
	#elif defined(__MWERKS__) || defined(__cplusplus)
		#define AVCF_INLINE static inline
	#elif defined(__GNUC__)
		#define AVCF_INLINE static __inline__
	#elif defined(_MSC_VER)
		#define AVCF_INLINE static __inline
	#else
		#define AVCF_INLINE static    
	#endif
#endif

#ifndef AVCF_SUPPORT_CF_COREANIMATION
#define AVCF_SUPPORT_CF_COREANIMATION TARGET_OS_WIN32
#endif // AVCF_SUPPORT_CF_COREANIMATION

#ifndef AVCF_SUPPORT_AUDIOMIX
#define AVCF_SUPPORT_AUDIOMIX ( ( TARGET_OS_MAC && MAC_OS_X_VERSION_MAX_ALLOWED >= 1070 ) || TARGET_OS_WIN32 )
#endif // AVCF_SUPPORT_AUDIOMIX

#ifndef AVCF_SUPPORT_HLS_METADATA
#define AVCF_SUPPORT_HLS_METADATA ( ( TARGET_OS_MAC && MAC_OS_X_VERSION_MAX_ALLOWED >= 101000 ) || TARGET_OS_WIN32 )
#endif // AVCF_SUPPORT_HLS_METADATA

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // AVCFBASE_H
