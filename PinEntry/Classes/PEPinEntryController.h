/********************************************************************************
*                                                                               *
* Copyright (c) 2010 Vladimir "Farcaller" Pouzanov <farcaller@gmail.com>        *
*                                                                               *
* Permission is hereby granted, free of charge, to any person obtaining a copy  *
* of this software and associated documentation files (the "Software"), to deal *
* in the Software without restriction, including without limitation the rights  *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell     *
* copies of the Software, and to permit persons to whom the Software is         *
* furnished to do so, subject to the following conditions:                      *
*                                                                               *
* The above copyright notice and this permission notice shall be included in    *
* all copies or substantial portions of the Software.                           *
*                                                                               *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,      *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE   *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER        *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN     *
* THE SOFTWARE.                                                                 *
*                                                                               *
********************************************************************************/

#import <UIKit/UIKit.h>
#import "PEViewController.h"

@class PEPinEntryController;

@protocol PEPinEntryControllerDelegate

@required
- (void)pinEntryController:(PEPinEntryController *)c shouldAcceptPin:(NSUInteger)pin callback:(void(^)(BOOL))callback;
- (void)pinEntryController:(PEPinEntryController *)c changedPin:(NSUInteger)pin;
- (void)pinEntryControllerDidCancel:(PEPinEntryController *)c;

@end


@class PEViewController;


@interface PEPinEntryController : UINavigationController <PEViewControllerDelegate>
{
	BOOL verifyOnly;
	NSUInteger pinStage;
	NSUInteger pinEntry1;
	PEViewController *pinController;
	id <PEPinEntryControllerDelegate> __weak pinDelegate;
}
@property (nonatomic, readwrite, weak) id <PEPinEntryControllerDelegate> pinDelegate;
@property (nonatomic, readonly) BOOL verifyOnly;

-(void)setActivityIndicatorAnimated:(BOOL)animated;
-(void)reset;

+ (PEPinEntryController *)pinVerifyController;
+ (PEPinEntryController *)pinChangeController;
+ (PEPinEntryController *)pinCreateController;

@end
