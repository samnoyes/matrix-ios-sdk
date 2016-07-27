/*
 Copyright 2016 OpenMarket Ltd

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>

/**
 Autamatic wrapper enabling.
 The code of this wrapper is enabled only if the Xcode workspace contains the header files
 of libjingle.
 That means that MXJingleCallStack will be automatically built if the application that uses
 MatrixSDK embeds libjingle.

 The application can use the libjingle build pod provided by pristine.io at
 https://github.com/pristineio/webrtc-build-scripts:
     pod 'libjingle_peerconnection'
 */

#if __has_include("RTCPeerConnection.h")
#define MX_CALL_STACK_JINGLE
#endif

#ifdef MX_CALL_STACK_JINGLE

#import "MXCallStack.h"

/**
 `MXJingleCallStack` is the implementation of the `MXCallStack` protocol using
  libjingle.

 @see https://developers.google.com/talk/libjingle/developer_guide
 */
@interface MXJingleCallStack : NSObject <MXCallStack>

@end

#endif // MX_CALL_STACK_JINGLE