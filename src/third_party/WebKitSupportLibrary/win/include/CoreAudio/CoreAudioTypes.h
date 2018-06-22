/*==================================================================================================
    File:       CoreAudio/CoreAudioTypes.h

    Contains:   Definitions types common to the Core Audio APIs

    Copyright:  (c) 1985-2010 by Apple, Inc., all rights reserved.

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

==================================================================================================*/
#if !defined(__CoreAudioTypes_h__)
#define __CoreAudioTypes_h__

#define COREAUDIOTYPES_VERSION 1051

#include <TargetConditionals.h>
    #include <CoreFoundation/CFBase.h>

#if !defined(CA_PREFER_FIXED_POINT)
        #define CA_PREFER_FIXED_POINT 0
    #endif

#if defined(__cplusplus)
    #include <string.h>
#endif

#if PRAGMA_ENUM_ALWAYSINT
    #pragma enumsalwaysint off
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

enum 
{
    kAudio_UnimplementedError   = -4,
    kAudio_FileNotFoundError    = -43,
    kAudio_ParamError           = -50,
    kAudio_MemFullError         = -108
};
      
struct AudioBuffer
{
    UInt32  mNumberChannels;
    UInt32  mDataByteSize;
    void*   mData;
};
typedef struct AudioBuffer  AudioBuffer;

struct AudioBufferList
{
    UInt32      mNumberBuffers;
    AudioBuffer mBuffers[1]; // this is a variable length array of mNumberBuffers elements
    
#if defined(__cplusplus) && CA_STRICT
public:
    AudioBufferList() {}
private:
    AudioBufferList(const AudioBufferList&);
    AudioBufferList&    operator=(const AudioBufferList&);
#endif

};
typedef struct AudioBufferList  AudioBufferList;

#if !CA_PREFER_FIXED_POINT
typedef Float32     AudioSampleType;
typedef Float32     AudioUnitSampleType;
#else
typedef SInt16      AudioSampleType;
typedef SInt32      AudioUnitSampleType;
#define kAudioUnitSampleFractionBits 24
#endif

struct AudioStreamBasicDescription
{
    Float64 mSampleRate;
    UInt32  mFormatID;
    UInt32  mFormatFlags;
    UInt32  mBytesPerPacket;
    UInt32  mFramesPerPacket;
    UInt32  mBytesPerFrame;
    UInt32  mChannelsPerFrame;
    UInt32  mBitsPerChannel;
    UInt32  mReserved;
};
typedef struct AudioStreamBasicDescription  AudioStreamBasicDescription;

struct  AudioStreamPacketDescription
{
    SInt64  mStartOffset;
    UInt32  mVariableFramesInPacket;
    UInt32  mDataByteSize;
};
typedef struct AudioStreamPacketDescription AudioStreamPacketDescription;

#if !defined(__SMPTETime__)
#define __SMPTETime__

struct SMPTETime
{
    SInt16  mSubframes;
    SInt16  mSubframeDivisor;
    UInt32  mCounter;
    UInt32  mType;
    UInt32  mFlags;
    SInt16  mHours;
    SInt16  mMinutes;
    SInt16  mSeconds;
    SInt16  mFrames;
};
typedef struct SMPTETime    SMPTETime;

enum
{
    kSMPTETimeType24        = 0,
    kSMPTETimeType25        = 1,
    kSMPTETimeType30Drop    = 2,
    kSMPTETimeType30        = 3,
    kSMPTETimeType2997      = 4,
    kSMPTETimeType2997Drop  = 5,
    kSMPTETimeType60        = 6,
    kSMPTETimeType5994      = 7,
    kSMPTETimeType60Drop    = 8,
    kSMPTETimeType5994Drop  = 9,
    kSMPTETimeType50        = 10,
    kSMPTETimeType2398      = 11
};

enum
{
    kSMPTETimeValid     = (1 << 0),
    kSMPTETimeRunning   = (1 << 1)
};

#endif


#if defined(__cplusplus)
}
#endif

#if PRAGMA_ENUM_ALWAYSINT
    #pragma enumsalwaysint reset
#endif

#endif  //  __CoreAudioTypes_h__
