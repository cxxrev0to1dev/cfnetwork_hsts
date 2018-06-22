/* CoreGraphics - CGFloat.h
 * Copyright (c) 2005-2006 Apple Computer, Inc. (unpublished)
 * All rights reserved.
 */

#ifndef CGFLOAT_H_
#define CGFLOAT_H_

#include <CoreGraphics/CGBase.h>
#include <math.h>
#include <stdlib.h>
#include <xlocale.h>

#define kCGFloatCFNumberType						\
    (sizeof(CGFloat) == sizeof(float) ?					\
	kCFNumberFloatType : kCFNumberDoubleType)

CG_INLINE CGFloat
CGFAbs(CGFloat value)
{
    if (sizeof(value) == sizeof(float)) {
	return (CGFloat)fabsf((float)value);
    } else {
	return (CGFloat)fabs((double)value);
    }
}

CG_INLINE CGFloat
CGFloor(CGFloat value)
{
    if (sizeof(value) == sizeof(float)) {
	return (CGFloat)floorf((float)value);
    } else {
	return (CGFloat)floor((double)value);
    }
}

CG_INLINE CGFloat
CGCeiling(CGFloat value)
{
    if (sizeof(value) == sizeof(float)) {
	return (CGFloat)ceilf((float)value);
    } else {
	return (CGFloat)ceil((double)value);
    }
}

CG_INLINE CGFloat
CGRound(CGFloat value)
{
    if (sizeof(value) == sizeof(float)) {
	return (CGFloat)roundf((float)value);
    } else {
	return (CGFloat)round((double)value);
    }
}

/* Return the minimum of `x' and `y'. */

CG_INLINE CGFloat
CGFloatMin(CGFloat a, CGFloat b)
{
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    if (sizeof(a) == sizeof(float)) {
	return (CGFloat)fminf((float)a, (float)b);
    } else {
	return (CGFloat)fmin((double)a, (double)b);
    }
#else 
    return isnan(a) ? b : ((isnan(b) || a < b) ? a : b);
#endif
}

/* Return the maximum of `x' and `y'. */

CG_INLINE CGFloat
CGFloatMax(CGFloat a, CGFloat b)
{
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    if (sizeof(a) == sizeof(float)) {
	return (CGFloat)fmaxf((float)a, (float)b);
    } else {
	return (CGFloat)fmax((double)a, (double)b);
    }
#else 
    return isnan(a) ? b : ((isnan(b) || a > b) ? a : b);
#endif
}

CG_INLINE CGFloat
CGFloatFromCString(const char *ptr, char **endptr)
{
    if (sizeof(CGFloat) == sizeof(float)) {
	return (CGFloat)strtof_l(ptr, endptr, NULL);
    } else {
	return (CGFloat)strtod_l(ptr, endptr, NULL);
    }
}

#endif	/* CGFLOAT_H_ */
