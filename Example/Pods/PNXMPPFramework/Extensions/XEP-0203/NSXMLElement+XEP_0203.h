#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <KissXML/DDXML.h>
#endif


@interface NSXMLElement (XEP_0203)

- (BOOL)wasDelayed;
- (NSDate *)delayedDeliveryDate;

@end
