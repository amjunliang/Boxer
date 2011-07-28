/* 
 Boxer is copyright 2011 Alun Bestor and contributors.
 Boxer is released under the GNU General Public License 2.0. A full copy of this license can be
 found in this XCode project at Resources/English.lproj/BoxerHelp/pages/legalese.html, or read
 online at [http://www.gnu.org/licenses/gpl-2.0.txt].
 */

//BXDOSWindowControllerPrivate defines the private interface and constants
//for BXDOSWindowController and its subclasses.

#import "BXDOSWindowController.h"


#pragma mark -
#pragma mark Constants

#define BXFullscreenFadeOutDuration	0.2f
#define BXFullscreenFadeInDuration	0.4f
#define BXWindowSnapThreshold		64


#pragma mark Private method declarations

@interface BXDOSWindowController ()
@property (retain, nonatomic) BXDOSFullScreenWindow *fullScreenWindow;

//A wrapper for the input view, to aid window-sizing behaviour.
@property (retain, nonatomic) NSView *viewContainer;

//Returns YES if the window is in the process of resizing itself.
@property (readonly, nonatomic) BOOL isResizing;

//Returns the size that the rendering view would currently be *if it were in windowed mode.*
//This will differ from the actual render view size if in fullscreen mode.
@property (readonly, nonatomic) NSSize windowedRenderingViewSize;



//Add/remove notification observers for everything we care about. Called from windowDidLoad.
- (void) _addObservers;
- (void) _removeObservers;

//Resizes the window in anticipation of sliding out the specified view. This will ensure
//there is enough room on screen to accomodate the new window size.
- (void) _resizeToAccommodateSlidingView: (NSView *)view;

//Performs the slide animation used to toggle the status bar and program panel on or off
- (void) _slideView: (NSView *)view shown: (BOOL)show;

//Apply the switch to fullscreen mode. Used internally by setFullScreen: and setFullScreenWithZoom:
- (void) _applyFullScreenState: (BOOL)fullScreen;

//Resize the window if needed to accomodate the specified frame.
//Returns YES if the window was actually resized, NO otherwise.
- (BOOL) _resizeToAccommodateFrame: (BXFrameBuffer *)frame;

//Returns the view size that should be used for rendering the specified frame.
- (NSSize) _renderingViewSizeForFrame: (BXFrameBuffer *)frame minSize: (NSSize)minViewSize;

//Forces the emulator's video handler to recalculate its filter settings at the end of a resize event.
- (void) _cleanUpAfterResize;

//Returns whether we are actually in fullscreen mode, and not transitioning to or from it.
- (BOOL) _isReallyInFullScreen;

@end

