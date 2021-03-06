#include <Cocoa/Cocoa.h>
#include <AppKit/NSPasteboard.h>

#include <stdlib.h>
#include <string.h>

char* getPasteboardText()
{
    NSPasteboard* pasteboard = [NSPasteboard generalPasteboard];
    NSString* string = [pasteboard stringForType:NSStringPboardType];
    const char* cstring = [string UTF8String];
    char* ret = (char*)malloc(strlen(cstring));
    strcpy(ret, cstring);
    return ret;
}

void putPasteboardText(const char* text)
{
    NSPasteboard* pasteboard = [NSPasteboard generalPasteboard];
    NSString* string = [NSString stringWithUTF8String:text];
    [pasteboard clearContents];
    [pasteboard setString:string forType:NSStringPboardType];
}
