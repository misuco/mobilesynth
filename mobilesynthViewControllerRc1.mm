//
//  mobilesynthViewController.m
//  mobilesynth
//
//  Created by Allen Porter on 12/7/08.
//  Modified by Claudio Zopfi 2009-2018
//  Copyright thebends 2008. All rights reserved.
//

#include <QtGlobal>

#ifdef Q_OS_IOS

#include "mobilesynthviewcontrollerrc1.hpp"
#import "mobilesynthViewControllerRc1.h"
#import "AudioOutput.h"
#include "synth/controller.h"

namespace mobilesynthview
{
    struct WidgetImpl
    {
        mobilesynthViewControllerRc1* wrapped;
    };
    Widget::Widget() :
    impl(new WidgetImpl)
    {
        impl->wrapped = [[mobilesynthViewControllerRc1 alloc] init];
    }
    Widget::~Widget()
    {
        if (impl) {
            [impl->wrapped dealloc];
        }
        delete impl;
    }

    void Widget::setController(synth::Controller * ctl)
    {
        [impl->wrapped setController:ctl];
    }
}

@implementation mobilesynthViewControllerRc1

- (id)init {
    self = [super init];
    return self;
}

- (void)setController:(synth::Controller*)ctl {
    controller_=ctl;
    ctl->set_sample_rate(44100.0);
    // Format preferred by the iphone (Fixed 8.24)
    outputFormat.mSampleRate = 44100.0;

    outputFormat.mFormatID = kAudioFormatLinearPCM;
    //outputFormat.mFormatFlags  = kAudioFormatFlagsAudioUnitCanonical;
    //outputFormat.mFormatFlags  = kAudioFormatFlagIsFloat | kAudioFormatFlagsNativeEndian | kAudioFormatFlagIsPacked | kAudioFormatFlagIsNonInterleaved;

    outputFormat.mFormatFlags  = kAudioFormatFlagIsSignedInteger;

#if  __IPHONE_OS_VERSION_MAX_ALLOWED >= 8000
    outputFormat.mBytesPerPacket = sizeof(SInt32);
    outputFormat.mBytesPerFrame = sizeof(SInt32);
    outputFormat.mBitsPerChannel = 8 * sizeof(SInt32);
#else
    outputFormat.mBytesPerPacket = sizeof(AudioUnitSampleType);
    outputFormat.mBytesPerFrame = sizeof(AudioUnitSampleType);
    outputFormat.mBitsPerChannel = 8 * sizeof(AudioUnitSampleType);
#endif
    outputFormat.mFramesPerPacket = 1;
    outputFormat.mChannelsPerFrame = 1;
    outputFormat.mReserved = 0;
    
    output = [[AudioOutput alloc] initWithAudioFormat:&outputFormat];
    [output setSampleDelegate:self];
    [output start];  // immediately invokes our callback to generate samples
}

- (void)syncControls {
    @synchronized(self) {
    }
}

- (OSStatus)generateSamples:(AudioBufferList*)buffers {
    assert(controller_);
    //NSLog(@"generateSamples num buffers %u" , buffers->mNumberBuffers);
    assert(buffers->mNumberBuffers == 1);  // mono output
    AudioBuffer* outputBuffer = &buffers->mBuffers[0];
    int* data = (int*)outputBuffer->mData;
    if (controller_->released()) {
        memset(data, 0, outputBuffer->mDataByteSize);
        return noErr;
    }
    int samples = outputBuffer->mDataByteSize / sizeof(SInt32);
    //NSLog(@"generateSamples %u" , samples);
    controller_->GetInt32Sapmles(data, samples);
    return noErr;
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return (interfaceOrientation == UIInterfaceOrientationLandscapeRight);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning]; // Releases the view if it doesn't have a superview
    // Release anything that's not essential, such as cached data
}

- (void)dealloc {
    [output dealloc];
    [super dealloc];
}

@end

#endif
