//
//  Created by Morris on 11-12-17.
//  Copyright (c) 2011年 http://warwithinme.com . All rights reserved.
//


// ====================
// Switches:
#define VIM_KEYMAP_TIMEOUT 220
#define SCROLL_STEP        100  // Define how smooth will the textview scroll
                                // for commands like 'zb' / 'zt'...
                                // The smaller the smoother and slower.
#define UNDERSCORE_IS_WORD      // If defined, "a_word" is consider a word,
                                // otherwise, it's consider three words.
#define U_AS_REDO               // If defined, bind 'U' to redo, otherwise
                                // bind 'ctrl + r' to redo.
// #define MAKE_0_AS_CARET      // If defined, 0 acts as ^
// #define VIM_COOPERATIVE      // Define this if someone dont want to compile it as SIMBL plugin.
// #define CMDLINE_HAS_FOCUSRING   // If defined, the cmdline will show a focus ring when it enters ex mode.
// --------------------


#ifdef DEBUG
#   define DLog(fmt, ...) NSLog(fmt, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

#define XVimTag 1990


// How xVim works:
// 1.In the entry point of this bundle (defined as XVimPlugin in XGlobal.m),
//   we hijack the application's NSTextView class or possibly its subclass,
//   by calling hijack method of the subclass of XTextViewBridge.
// 2.Subclass of XTextViewBridge can ask XTextViewBridge to get the XVimController,
//   which is used to handle every key input.


// ====================
// Hidden API
@interface NSText(xVim)
// TODO: This method will include wrapped lines.
-(NSRange)    accessibilityCharacterRangeForLineNumber:(NSUInteger) lineNumber;
@end
// --------------------

// ====================
// Internal for XVim
@class XTextViewBridge;
void configureInsertionPointRect(XTextViewBridge* bridge, NSTextView* view, NSRect* rect);
// This is really really bad, but I don't know where to place them.
typedef void (*O_KeyDown) (void*, SEL, NSEvent*);
O_KeyDown orig_keyDown;
// --------------------

// CommandLine Background Colors
#define kCommandLineMainBackgroudColor NSColorFromRGB(0x9ABD00)
#define kCommandLineInsertBackgroudColor NSColorFromRGB(0x0087AF)