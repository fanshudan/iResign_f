

#import "IRHelpWindow.h"

@implementation IRHelpWindow

// Move the window by dragging
- (BOOL)isMovableByWindowBackground {
    return YES;
}

// Close the window
- (IBAction)closeOK:(id)sender {
    [self close];
}

@end
