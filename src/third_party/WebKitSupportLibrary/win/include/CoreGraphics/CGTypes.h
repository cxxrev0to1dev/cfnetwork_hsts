/* CoreGraphics - CGTypes.h
 * Copyright (c) 2004-2006 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGTYPES_H_
#define CGTYPES_H_

typedef struct CGRuntimeClass CGRuntimeClass;

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFRuntime.h>
#include <stdint.h>

/* This is version 0 of this structure. We have our own struct since CF has
   mucked up theirs with non-versioned additions for garbage collection. */

struct CGRuntimeClass {
    unsigned int version;
    const char *class_name;
    void (*init)(CFTypeRef type);
    CFTypeRef (*copy)(CFAllocatorRef allocator, CFTypeRef type);
    void (*finalize)(CFTypeRef type);
    Boolean (*equal)(CFTypeRef type1, CFTypeRef type2);
    CFHashCode (*hash)(CFTypeRef type);
    CFStringRef (*copy_description)(CFTypeRef type, CFDictionaryRef options);
    CFStringRef (*copy_debug_description)(CFTypeRef type);
    void (*reclaim)(CFTypeRef type);
};

/* Register a type with the CFRuntime, using CG callbacks. */

CG_LOCAL CFTypeID CGTypeRegisterWithCallbacks(CFTypeID *type,
    const CGRuntimeClass *class);

/* Create an instance of a CG type. */

CG_LOCAL void *CGTypeCreateInstance(CFTypeID typeID, CFIndex extra);

/* Create an instance of a CG type. */

CG_LOCAL void *CGTypeCreateInstanceWithAllocator(CFAllocatorRef allocator,
    CFTypeID typeID, CFIndex extra);

/* Create a singleton of a CG type. */

CG_LOCAL void *CGTypeCreateSingleton(CFTypeID typeID, void *data,
    CFIndex extra);

#endif	/* CGTYPES_H_ */
