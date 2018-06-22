/*
	File:		AVCFMetadataItem.h
	
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

#ifndef AVCFMETADATAITEM_H
#define AVCFMETADATAITEM_H

#include <AVFoundationCF/AVCFBase.h>
#include <AVFoundationCF/AVCFAsynchronousPropertyValueLoading.h>

#include <CoreMedia/CMTime.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef const struct OpaqueAVCFMetadataItem *AVCFMetadataItemRef;
typedef const struct OpaqueAVCFMetadataItemFilter *AVCFMetadataItemFilterRef;

AVCF_EXPORT const CFStringRef AVCFMetadataItemPropertyValue;
AVCF_EXPORT const CFStringRef AVCFMetadataItemPropertyStringValue;
AVCF_EXPORT const CFStringRef AVCFMetadataItemPropertyNumberValue;
AVCF_EXPORT const CFStringRef AVCFMetadataItemPropertyDateValue;
AVCF_EXPORT const CFStringRef AVCFMetadataItemPropertyDataValue;
AVCF_EXPORT const CFStringRef AVCFMetadataItemPropertyExtraAttributes;
AVCF_EXPORT AVCFPropertyValueStatus AVCFMetadataItemGetStatusOfValueForProperty(AVCFMetadataItemRef item, CFStringRef property, CFErrorRef *errorOut);

typedef void (*AVCFMetadataItemLoadValuesCompletionCallback)(AVCFMetadataItemRef item, void *clientContext);

AVCF_EXPORT void AVCFMetadataItemLoadValuesAsynchronouslyForProperties(AVCFMetadataItemRef item, CFArrayRef properties, AVCFMetadataItemLoadValuesCompletionCallback callback, void *clientContext);
AVCF_EXPORT void AVCFMetadataItemCancelLoading(AVCFMetadataItemRef item);
AVCF_EXPORT CFTypeRef AVCFMetadataItemCopyKey(AVCFMetadataItemRef item);
AVCF_EXPORT CFStringRef AVCFMetadataItemCopyCommonKey(AVCFMetadataItemRef item);
AVCF_EXPORT CFStringRef AVCFMetadataItemCopyKeySpace(AVCFMetadataItemRef item);
AVCF_EXPORT CFLocaleRef AVCFMetadataItemCopyLocale(AVCFMetadataItemRef item);
AVCF_EXPORT CMTime AVCFMetadataItemGetTime(AVCFMetadataItemRef item);
AVCF_EXPORT CFTypeRef AVCFMetadataItemCopyValue(AVCFMetadataItemRef item);
AVCF_EXPORT CFDictionaryRef AVCFMetadataItemCopyExtraAttributes(AVCFMetadataItemRef item);
AVCF_EXPORT CMTime AVCFMetadataItemGetDuration(AVCFMetadataItemRef item);

AVCF_EXPORT CFStringRef AVCFMetadataItemCopyStringValue(AVCFMetadataItemRef item);
AVCF_EXPORT CFNumberRef AVCFMetadataItemCopyNumberValue(AVCFMetadataItemRef item);
AVCF_EXPORT CFDateRef AVCFMetadataItemCopyDateValue(AVCFMetadataItemRef item);
AVCF_EXPORT CFDataRef AVCFMetadataItemCopyDataValue(AVCFMetadataItemRef item);
AVCF_EXPORT CFArrayRef AVCFMetadataItemCopyItemsWithLocale(CFArrayRef array, CFLocaleRef locale);
AVCF_EXPORT CFArrayRef AVCFMetadataItemCopyItemsWithKeyAndKeySpace(CFArrayRef array, CFTypeRef key, CFStringRef keySpace); 
AVCF_EXPORT CFArrayRef AVCFMetadataItemCopyItemsFilteredByMetadataItemFilter(CFArrayRef array, AVCFMetadataItemFilterRef metadataItemFilter);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif  // AVCFMETADATAITEM_H
