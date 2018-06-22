/*
	File:  CMBaseObject.h
	
	Framework:  CoreMedia
 
    Copyright 2006-2012 Apple Inc. All rights reserved.

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

#ifndef CMBASEOBJECT_H
#define	CMBASEOBJECT_H

#include <CoreMedia/CMBase.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 4)

typedef struct OpaqueCMBaseObject *CMBaseObjectRef;		// a CF type

typedef struct OpaqueCMBaseClass *CMBaseClassID;		// NOT a CF type

enum {
	kCMBaseObject_ClassVersion_1 = 1,
	kCMBaseObject_ClassVersion_2 = 2
};

enum {
	kCMBaseObjectError_ParamErr						= -12780,
	kCMBaseObjectError_UnsupportedVersion			= -12781,
	kCMBaseObjectError_UnsupportedOperation			= -12782,
	kCMBaseObjectError_ValueNotAvailable			= -12783,
	kCMBaseObjectError_PropertyNotFound				= -12784,
	kCMBaseObjectError_Invalidated					= -12785,
	kCMBaseObjectError_AllocationFailed				= -12786,
	kCMBaseObjectError_PropertyNotSupported			= -12787,
};


typedef struct {
	uint32_t version; 			// must be kCMBaseObject_ClassVersion_1 or _2
	size_t derivedStorageSize;	// size of entire instance, defined by concrete implementation.

	Boolean (*equal)( CMBaseObjectRef o, CMBaseObjectRef compareTo );
	OSStatus (*invalidate)( CMBaseObjectRef o);
	void (*finalize)( CMBaseObjectRef o );
	CFStringRef (*copyDebugDescription)( CMBaseObjectRef o );	// optional; defines CFShow() output

	OSStatus (*copyProperty)( CMBaseObjectRef o, CFStringRef propertyKey,
								CFAllocatorRef allocator, void *propertyValueOut);
	OSStatus (*setProperty)( CMBaseObjectRef o, CFStringRef propertyKey, CFTypeRef propertyValue);
	OSStatus (*notificationBarrier)( CMBaseObjectRef o);	// optional: only available if version is kCMBaseObject_ClassVersion_2 and later
} 
CMBaseClass;

typedef struct {
	// CMBaseClass has no base class itself, so no base vTable here.
	const struct OpaqueCMBaseVTableReserved *reserved;			// Must be NULL
	const CMBaseClass *baseClass;
} 
CMBaseVTable;


CM_EXPORT OSStatus CMDerivedObjectCreate( CFAllocatorRef allocator, const CMBaseVTable *v, 
									CMBaseClassID classID, CMBaseObjectRef *objectOut);

CM_EXPORT const CMBaseVTable	*CMBaseObjectGetVTable( CMBaseObjectRef o);

CM_EXPORT void	*CMBaseObjectGetDerivedStorage( CMBaseObjectRef o);

CM_EXPORT CMBaseClassID	CMBaseObjectGetClassID( CMBaseObjectRef o);

CM_EXPORT CFTypeID	CMBaseClassGetCFTypeID( CMBaseClassID classID);

CM_EXPORT Boolean	CMBaseObjectIsMemberOfClass( CMBaseObjectRef o, CMBaseClassID classID);

CM_EXPORT CMBaseClassID	CMBaseGetClassID( void);



CM_INLINE OSStatus CMBaseObjectInvalidate(	CMBaseObjectRef o);

CM_INLINE OSStatus CMBaseObjectCopyProperty(	CMBaseObjectRef o,
												CFStringRef propertyKey,
												CFAllocatorRef allocator,
												void *propertyValueOut);

CM_INLINE OSStatus CMBaseObjectSetProperty(	CMBaseObjectRef o,
												CFStringRef propertyKey,
												CFTypeRef propertyValue);

CM_INLINE OSStatus	CMBaseObjectNotificationBarrier(	CMBaseObjectRef o);


CM_INLINE const CMBaseClass *getCMBaseObjectVTable( CMBaseObjectRef o)
{
	return ((const CMBaseVTable*) CMBaseObjectGetVTable( (CMBaseObjectRef) o))->baseClass;
}

CM_INLINE OSStatus	CMBaseObjectInvalidate(	CMBaseObjectRef o)
{
	const CMBaseClass *vTable;

	if ( o == NULL)
		return kCMBaseObjectError_ParamErr;
	vTable = getCMBaseObjectVTable( o);
	if ( vTable->invalidate != NULL)
		return vTable->invalidate( o);
	else
		return kCMBaseObjectError_UnsupportedOperation;
}

CM_INLINE OSStatus	CMBaseObjectCopyProperty(	CMBaseObjectRef o,
												CFStringRef propertyKey,
												CFAllocatorRef allocator,
												void *propertyValueOut)
{
	const CMBaseClass *vTable = getCMBaseObjectVTable( o);

	if ( vTable->copyProperty != NULL)
		return vTable->copyProperty( o, propertyKey, allocator, propertyValueOut);
	else
		return kCMBaseObjectError_UnsupportedOperation;
}

CM_INLINE OSStatus	CMBaseObjectSetProperty(	CMBaseObjectRef o,
												CFStringRef propertyKey,
												CFTypeRef propertyValue)
{
	const CMBaseClass *vTable = getCMBaseObjectVTable( o);

	if ( vTable->setProperty != NULL)
		return vTable->setProperty( o, propertyKey, propertyValue);
	else
		return kCMBaseObjectError_UnsupportedOperation;
}

CM_INLINE OSStatus	CMBaseObjectNotificationBarrier(	CMBaseObjectRef o)
{
	const CMBaseClass *vTable = getCMBaseObjectVTable( o);

	if ( vTable->version >= kCMBaseObject_ClassVersion_2 && vTable->notificationBarrier != NULL)
		return vTable->notificationBarrier( o);
	else
		return kCMBaseObjectError_UnsupportedOperation;
}

#pragma pack(pop)
    
#ifdef __cplusplus
}
#endif

#endif // CMBASEOBJECT_H
