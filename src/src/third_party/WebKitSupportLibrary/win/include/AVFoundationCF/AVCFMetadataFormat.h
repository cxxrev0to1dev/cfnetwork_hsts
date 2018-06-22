/*
	File:		AVCFMetadataFormat.h
	
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

#ifndef AVCFMETADATAFORMAT_H
#define AVCFMETADATAFORMAT_H

#include <AVFoundationCF/AVCFBase.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

AVCF_EXPORT const CFStringRef AVCFMetadataKeySpaceCommon;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyTitle;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyCreator;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeySubject;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyDescription;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyPublisher;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyContributor;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyCreationDate;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyLastModifiedDate;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyType;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyFormat;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyIdentifier;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeySource;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyLanguage;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyRelation;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyLocation;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyCopyrights;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyAlbumName;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyAuthor;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyArtist;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyArtwork;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyMake;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeyModel;
AVCF_EXPORT const CFStringRef AVCFMetadataCommonKeySoftware;

AVCF_EXPORT const CFStringRef AVCFMetadataFormatQuickTimeUserData;
AVCF_EXPORT const CFStringRef AVCFMetadataKeySpaceQuickTimeUserData;

AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyAlbum;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyArranger;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyArtist;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyAuthor;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyChapter;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyComment;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyComposer;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyCopyright;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyCreationDate;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyDescription;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyDirector;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyDisclaimer;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyEncodedBy;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyFullName;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyGenre;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyHostComputer;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyInformation;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyKeywords;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyMake;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyModel;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyOriginalArtist;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyOriginalFormat;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyOriginalSource;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyPerformers;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyProducer;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyPublisher;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyProduct;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeySoftware;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeySpecialPlaybackRequirements;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyTrack;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyWarning;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyWriter;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyURLLink;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyLocationISO6709;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyTrackName;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyCredits;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyPhonogramRights;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyClassicTrackName;
AVCF_EXPORT const CFStringRef AVCFMetadataQuickTimeUserDataKeyTaggedCharacteristic;

AVCF_EXPORT const CFStringRef AVCFMetadataFormatISOUserData;
AVCF_EXPORT const CFStringRef AVCFMetadataKeySpaceISOUserData;

AVCF_EXPORT const CFStringRef AVCFMetadataISOUserDataKeyCopyright;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyCopyright;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyAuthor;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyPerformer;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyGenre;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyRecordingYear;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyLocation;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyTitle;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyDescription;
AVCF_EXPORT const CFStringRef AVCFMetadata3GPUserDataKeyThumbnail;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif  // AVCFMETADATAFORMAT_H
