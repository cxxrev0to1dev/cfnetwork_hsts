/*
	File:  AVCFMediaSelectionGroup.h

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

#ifndef AVCFMEDIASELECTIONGROUP_H
#define AVCFMEDIASELECTIONGROUP_H

#include <AVFoundationCF/AVCFBase.h>

#ifdef __cplusplus
extern "C" {
#endif
	
#pragma pack(push, 4)
	
typedef const struct OpaqueAVCFMediaSelectionGroup* AVCFMediaSelectionGroupRef;
typedef const struct OpaqueAVCFMediaSelectionOption* AVCFMediaSelectionOptionRef;

AVCF_EXPORT CFArrayRef AVCFMediaSelectionGroupGetOptions(AVCFMediaSelectionGroupRef selectionGroup);
AVCF_EXPORT Boolean AVCFMediaSelectionGroupAllowsEmptySelection(AVCFMediaSelectionGroupRef selectionGroup);
AVCF_EXPORT AVCFMediaSelectionOptionRef AVCFMediaSelectionGroupGetOptionWithPropertyList(AVCFMediaSelectionGroupRef selectionGroup, CFPropertyListRef plist);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionCopyPlayableOptionsFromArray(CFArrayRef selectionOptions);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionCopyOptionsFromArrayWithLocale(CFArrayRef selectionOptions, CFLocaleRef locale);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionCopyOptionsFromArrayWithMediaCharacteristics(CFArrayRef selectionOptions, CFArrayRef mediaCharacteristics);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionCopyOptionsFromArrayWithoutMediaCharacteristics(CFArrayRef selectionOptions, CFArrayRef mediaCharacteristics);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionCopyOptionsFromArrayFilteredAndSortedAccordingToPreferredLanguages(CFArrayRef selectionOptions, CFArrayRef preferredLanguages);
AVCF_EXPORT CFStringRef AVCFMediaSelectionOptionGetMediaType(AVCFMediaSelectionOptionRef selectionOption);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionOptionCopyMediaSubTypes(AVCFMediaSelectionOptionRef selectionOption);
AVCF_EXPORT Boolean AVCFMediaSelectionOptionHasMediaCharacteristic(AVCFMediaSelectionOptionRef selectionOption, CFStringRef mediaCharacteristic);
AVCF_EXPORT Boolean AVCFMediaSelectionOptionIsPlayable(AVCFMediaSelectionOptionRef selectionOption);
AVCF_EXPORT CFLocaleRef AVCFMediaSelectionOptionCopyLocale(AVCFMediaSelectionOptionRef selectionOption);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionOptionCopyCommonMetadata(AVCFMediaSelectionOptionRef selectionOption);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionOptionCopyAvailableMetadataFormats(AVCFMediaSelectionOptionRef selectionOption);
AVCF_EXPORT CFArrayRef AVCFMediaSelectionOptionCopyMetadataForFormat(AVCFMediaSelectionOptionRef selectionOption, CFStringRef format);
AVCF_EXPORT AVCFMediaSelectionOptionRef AVCFMediaSelectionOptionGetAssociatedOptionInGroup(AVCFMediaSelectionOptionRef selectionOption, AVCFMediaSelectionGroupRef selectionGroup);
AVCF_EXPORT CFPropertyListRef AVCFMediaSelectionOptionCopyPropertyList(AVCFMediaSelectionOptionRef selectionOption);
AVCF_EXPORT CFStringRef AVCFMediaSelectionOptionCopyDisplayNameWithLocale(AVCFMediaSelectionOptionRef selectionOption, CFLocaleRef locale);

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif  // AVCFMEDIASELECTIONGROUP_H

