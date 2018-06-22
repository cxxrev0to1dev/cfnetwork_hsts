/*!
 @header
 
 @discussion
 Access to user preferences for media caption rendering.
 */

#ifndef MediaAccessibility_MACaptionAppearance_h
#define MediaAccessibility_MACaptionAppearance_h

#include <MediaAccessibility/MADefinitions.h>
#include <AvailabilityMacros.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFBase.h>
#include <CoreText/CoreText.h>
#include <CoreGraphics/CoreGraphics.h>

MA_EXTERN_C_BEGIN

typedef CF_ENUM(CFIndex, MACaptionAppearanceDomain) {
    kMACaptionAppearanceDomainDefault   = 0,
    kMACaptionAppearanceDomainUser      = 1,
} CF_ENUM_AVAILABLE(10_9, 7_0);

typedef CF_ENUM(CFIndex, MACaptionAppearanceDisplayType) {
    kMACaptionAppearanceDisplayTypeForcedOnly     = 0,
    kMACaptionAppearanceDisplayTypeAutomatic      = 1,
    kMACaptionAppearanceDisplayTypeAlwaysOn       = 2,
} CF_ENUM_AVAILABLE(10_9, 7_0);

typedef CF_ENUM(CFIndex, MACaptionAppearanceBehavior) {
    kMACaptionAppearanceBehaviorUseValue                = 0,
    kMACaptionAppearanceBehaviorUseContentIfAvailable   = 1,
} CF_ENUM_AVAILABLE(10_9, 7_0);

typedef CF_ENUM(CFIndex, MACaptionAppearanceFontStyle) {
    kMACaptionAppearanceFontStyleDefault                    = 0,
    kMACaptionAppearanceFontStyleMonospacedWithSerif        = 1,
    kMACaptionAppearanceFontStyleProportionalWithSerif      = 2,
    kMACaptionAppearanceFontStyleMonospacedWithoutSerif     = 3,
    kMACaptionAppearanceFontStyleProportionalWithoutSerif   = 4,
    kMACaptionAppearanceFontStyleCasual                     = 5,
    kMACaptionAppearanceFontStyleCursive                    = 6,
    kMACaptionAppearanceFontStyleSmallCapital               = 7,
} CF_ENUM_AVAILABLE(10_9, 7_0);

typedef CF_ENUM(CFIndex, MACaptionAppearanceTextEdgeStyle) {
    kMACaptionAppearanceTextEdgeStyleUndefined      = 0,
    kMACaptionAppearanceTextEdgeStyleNone           = 1,
    kMACaptionAppearanceTextEdgeStyleRaised         = 2,
    kMACaptionAppearanceTextEdgeStyleDepressed      = 3,
    kMACaptionAppearanceTextEdgeStyleUniform        = 4,
    kMACaptionAppearanceTextEdgeStyleDropShadow     = 5,
} CF_ENUM_AVAILABLE(10_9, 7_0);

MA_EXPORT CFStringRef const MAMediaCharacteristicDescribesMusicAndSoundForAccessibility CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CFStringRef const MAMediaCharacteristicTranscribesSpokenDialogForAccessibility CF_AVAILABLE(10_9, 7_0);
MA_EXPORT bool MACaptionAppearanceAddSelectedLanguage(MACaptionAppearanceDomain, CFStringRef) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CFArrayRef MACaptionAppearanceCopySelectedLanguages(MACaptionAppearanceDomain) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT MACaptionAppearanceDisplayType MACaptionAppearanceGetDisplayType(MACaptionAppearanceDomain) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT void MACaptionAppearanceSetDisplayType(MACaptionAppearanceDomain, MACaptionAppearanceDisplayType) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CFArrayRef MACaptionAppearanceCopyPreferredCaptioningMediaCharacteristics(MACaptionAppearanceDomain) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CGColorRef MACaptionAppearanceCopyForegroundColor(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CGColorRef MACaptionAppearanceCopyBackgroundColor(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CGColorRef MACaptionAppearanceCopyWindowColor(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CGFloat MACaptionAppearanceGetForegroundOpacity(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CGFloat MACaptionAppearanceGetBackgroundOpacity(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CGFloat MACaptionAppearanceGetWindowOpacity(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CGFloat MACaptionAppearanceGetWindowRoundedCornerRadius(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CTFontDescriptorRef MACaptionAppearanceCopyFontDescriptorForStyle(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*, MACaptionAppearanceFontStyle) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT CGFloat MACaptionAppearanceGetRelativeCharacterSize(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);
MA_EXPORT MACaptionAppearanceTextEdgeStyle MACaptionAppearanceGetTextEdgeStyle(MACaptionAppearanceDomain, MACaptionAppearanceBehavior*) CF_AVAILABLE(10_9, 7_0);

MA_EXTERN_C_END

#endif /* MediaAccessibility_MACaptionAppearance_h */
