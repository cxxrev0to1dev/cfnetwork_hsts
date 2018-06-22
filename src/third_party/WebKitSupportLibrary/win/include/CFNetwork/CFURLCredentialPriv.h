/*
	 File:	   CFNetwork/CFURLCredentialPriv.h
 
	 Contains:   CFType URL credential header
 
	 Copyright:  Copyright (c) 2001-2008, Apple Inc. All rights reserved.
 
	 Bugs?:	  For bug reports, consult the following page on
				 the World Wide Web:
 
					 http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFURLCREDENTIALPRIV__
#define __CFURLCREDENTIALPRIV__

#ifndef __CFURLCREDENTIAL__
#include <CFNetwork/CFURLCredential.h>
#endif

#include <Availability.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint on
#endif
	
#if TARGET_OS_MAC && (!TARGET_OS_IPHONE && !TARGET_OS_EMBEDDED)
/*
 *  _CFURLCredentialCreateWithInitialAccess()
 *  
 *  Discussion:
 *	Creates a new CFURLCredential object with an initial access setting and
 *  a persistence of kCFURLCredentialPersistencePermanent. This is SPI because
 *  it currently only works on Mac OS X where keychain items have ACLs to restrict
 *  access.
 *  
 *  Parameters:
 *	
 *	allocator:
 *	  The CFAllocator which should be used to allocate memory for the
 *	  CFURLCredential. If this reference is not a valid CFAllocator,
 *	  the behavior is undefined.
 *	
 *	username:
 *	  A CFString containing the username.
 *	
 *	password:
 *	  A CFString containing the password.
 *	
 *	accountDomain:
 *	  Ignored.
 *	
 *	initialAccess:
 *	  A SecAccessRef containing the initial access setting of a CFURLCredential
 *    when it is added to the keychain.
 *  
 *  Result:
 *	A valid CFURLCredentialRef, or NULL if unsuccessful.
 *  
 */
CFN_EXPORT CFURLCredentialRef
_CFURLCredentialCreateWithInitialAccess(
  CFAllocatorRef	allocator,
  CFStringRef		username,
  CFStringRef		password,
  SecAccessRef		initialAccess) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA);


/*
 *  _CFURLCredentialGetInitialAccess()
 *  
 *  Discussion:
 *	Gets the initial access of a CFURLCredential object.
 *  
 *  Parameters:
 *	
 *	credential:
 *	  The CFURLCredential object.
 *  
 *  Result:
 *	A SecAccessRef containing the initial access setting of a CFURLCredential
 *  object, or NULL if there is no initial access setting.
 *  
 */
SecAccessRef _CFURLCredentialGetInitialAccess(CFURLCredentialRef credential);
#endif /* TARGET_OS_MAC && (!TARGET_OS_IPHONE && !TARGET_OS_EMBEDDED) */


/*
 *  _CFURLCredentialCreateWithTicket
 *  
 *  Discussion:
 *	Creates a credential that contains information for obtaining a 
 *  a Kerberos ticket.
 *  
 *  Parameters:
 *  userPrincipalName: [Required] a Kerberos 5 principal name for of the user-credentials.  
 *			Specified in the following format: username[/instance]@REALM (e.g. user@FOO.BAR.COM).
 *  servicePrincipalName: [Required] the Kerberos service-principal.
 *			Specified in the following format: service/@REALM (e.g. HTTP/FOO.BAR.COM).
 *  kerberosFlags: a dictionary of flags that affect Kerberos interaction. 
 *			This parameter can be NULL.  See below for list of acceptable keys.
 * 
 *  Result:
 *  A CFURLCredentialRef when successful or NULL on error.  An error does not 
 *  indicate Kerberos authentication failure.
 */
CFN_EXPORT CFURLCredentialRef
_CFURLCredentialCreateForKerberosTicket(
	CFAllocatorRef allocator,
	CFStringRef userPrincipalName,
	CFStringRef servicePrincipalName,
	CFDictionaryRef kerberosFlags) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA);
	
/*
 *  kCFURLCredentialKerberosTicketAllowDelegation
 *  
 *  Discussion:
 *	This key indicates a value of CFStringRef type which specifies whether
 *	the GSS-API flag of GSS_C_DELEG_POLICY_FLAG will be used or not.  A
 *  value of "TRUE" will cause this flag to be used.  This allows tickets
 *  to be validated with other KDC servers other than the one to which the 
 *  client is bound.  By default, this value will be "FALSE".
 *  
 */
CFN_EXPORT const CFStringRef kCFURLCredentialKerberosTicketAllowDelegation __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA);

/*
 *  _CFURLCredentialCreateXMobileMeAuthToken
 *  
 *  Discussion:
 *	Creates a credential that contains information for obtaining
 *  an XMobileMeAuthToken bag.
 *  
 *  Parameters:
 *  appleID: [Required] a valid AppleID  
 *			Specified in the following format: user@me.com 
 *  realm: [Required] the realm the AppleID corresponds to.
 *			Specified in the following format: typically, this is "MobileMe".
 * 
 *  Result:
 *  A CFURLCredentialRef when successful or NULL on error.  An error does not 
 *  indicate X-MobileMe-AuthToken authentication failure.
 */
CFN_EXPORT CFURLCredentialRef
_CFURLCredentialCreateXMobileMeAuthToken(CFAllocatorRef allocator, 
										 CFStringRef appleID,
										 CFStringRef password,
										 CFStringRef realm) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);
	
/*
 *  kCFURLCredentialKerberosNoUIFlag
 *  
 *  Discussion:
 *	This key indicates a value of CFStringRef type that indicates whether
 *	the GSS-API flag of GSS_C_NO_UI_FLAG will be used or not. A
 *  value of "TRUE" will cause this flag to be used.  This flag will
 *  cause any UI from the Kerberos libraries from appearing for 
 *  re-authentication.  By default, CFURLCredential will specify that
 *  this value be "TRUE".
 *  
 */
CFN_EXPORT const CFStringRef kCFURLCredentialKerberosNoUIFlag __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA);
	

// Some archiving and unarchiving utilities for the AuthBroker.
CFN_EXPORT CFDictionaryRef CFURLCredentialCopyProperties(CFAllocatorRef allocator, CFURLCredentialRef credential) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);
	
CFN_EXPORT CFURLCredentialRef CFURLCredentialCreateWithProperties(CFAllocatorRef allocator, CFDictionaryRef credential) __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_0);


#if PRAGMA_ENUM_ALWAYSINT
	#pragma enumsalwaysint reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CFURLCREDENTIALPRIV__ */

