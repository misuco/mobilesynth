//
//  mobilesynthViewController.h
//  mobilesynth
//
//  Created by Allen Porter on 12/7/08.
//  Copyright thebends 2008. All rights reserved.
//
#include <QtGlobal>
#ifdef Q_OS_IOS

#import <UIKit/UIKit.h>
#import "AudioOutput.h"
#import <AudioToolbox/AudioConverter.h>

@interface mobilesynthViewControllerRc1 : UIViewController <SampleGenerator> {
 @private
  // Synthesizer components
  AudioOutput* output;
  synth::Controller* controller_;
  
  AudioStreamBasicDescription outputFormat;
}

- (void)setController:(synth::Controller*)ctl;
- (OSStatus)generateSamples:(AudioBufferList*)buffers;

// For control panel
- (IBAction)changePage:(id)sender;

@end

#endif
