/* CoreGraphics - CGBasePrivate.h
   Copyright (c) 2007-2009 Apple Inc.
   All rights reserved. */

#ifndef CGBASEPRIVATE_H_
#define CGBASEPRIVATE_H_

/* Definitions of types used in SPIs. These types are "private", in that
   they should never appear in any API. This file should be
   "platform-neutral" -- that is, the definitions it contains should work on
   any currently supported platform. In this way, we can include SPI which
   relies on these types in a header file, even though on some platforms it
   may not be implemented.

   In time, we expect these types to be defined only where appropriate, but
   that's impossible at present. */

#include <CoreGraphics/CGBase.h>
#include <stdint.h>

/* The identifier of a connection to the Window Server. Always defined, but
   only used when CG_DESKTOP is defined. */
typedef uint32_t CGSConnectionID;

/* The identifier of a window. Always defined, but only used when CG_DESKTOP
   is defined. */
typedef uint32_t CGSWindowID;

/* The identifier of a surface. A surface is an area of a window with
   contents physically separate from the window content but which is
   rendered atomically whenever the window is rendered. Always defined, but
   only used when CG_DESKTOP is defined. */
typedef uint32_t CGSSurfaceID;

/* The identifier of a display. Always defined, but only used when
   CG_DESKTOP is defined. */
typedef int32_t CGSDisplayID;

/* Force inlining of a function, even if the compiler thinks otherwise. This
   is probably the wrong thing to do. */

#if !defined(CG_INLINE_ALWAYS)
# if defined(__GNUC__)
#  define CG_INLINE_ALWAYS static __inline__ __attribute__((always_inline)) 
# elif defined(_MSC_VER)
#  define CG_INLINE_ALWAYS static __forceinline 
# else /* Anything else. */
#  define CG_INLINE_ALWAYS CG_INLINE
# endif
#endif

/* Force a function to never be inlined, even if the compiler thinks
   otherwise. This is probably the wrong thing to do. */

#if !defined(CG_INLINE_NEVER)
# if defined(__GNUC__)
#  define CG_INLINE_NEVER static __attribute__((noinline)) 
# else /* Anything else. */
#  define CG_INLINE_NEVER static
# endif
#endif

#endif /* CGBASEPRIVATE_H_ */
