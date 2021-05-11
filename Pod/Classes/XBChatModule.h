//
//  XBChatModule.h
//  Pods
//
//  Created by Binh Nguyen Xuan on 10/26/14.
//
//

#import <Foundation/Foundation.h>

#import <PNXMPPFramework/XMPPReconnect.h>

#import <PNXMPPFramework/XMPPRoster.h>
#import <PNXMPPFramework/XMPPRosterCoreDataStorage.h>

#import <PNXMPPFramework/XMPPvCardTempModule.h>
#import <PNXMPPFramework/XMPPvCardAvatarModule.h>
#import <PNXMPPFramework/XMPPvCardCoreDataStorage.h>

#import <PNXMPPFramework/XMPPCapabilities.h>
#import <PNXMPPFramework/XMPPCapabilitiesCoreDataStorage.h>

#import <PNXMPPFramework/XMPPMUC.h>
#import <PNXMPPFramework/XMPPRoomCoreDataStorage.h>

#import <XMPPMessageArchivingCoreDataStorage.h>

extern NSString *const XBChatEventConnected;
extern NSString *const XBChatEventReceiveMessage;

@interface XBChatModule : NSObject
{
    XMPPStream *xmppStream;
    XMPPReconnect *xmppReconnect;
    XMPPRoster *xmppRoster;
    XMPPRosterCoreDataStorage *xmppRosterStorage;
    XMPPvCardCoreDataStorage *xmppvCardStorage;
    XMPPvCardTempModule *xmppvCardTempModule;
    XMPPvCardAvatarModule *xmppvCardAvatarModule;
    XMPPCapabilities *xmppCapabilities;
    XMPPCapabilitiesCoreDataStorage *xmppCapabilitiesStorage;
    XMPPMessageArchivingCoreDataStorage *xmppMessageArchivingStorage;
    XMPPMessageArchiving *xmppMessageArchivingModule;

    NSString *password;

    BOOL customCertEvaluation;

    BOOL isXmppConnected;
}

@property (nonatomic, retain) NSString *username;
@property (nonatomic, retain) NSString *password;
@property (nonatomic, retain) NSString *host;
@property (nonatomic, retain) NSString *avatarFormat;
@property (nonatomic, retain) UIImage *avatarPlaceHolder;

- (void)loadFromPlist:(NSString *)plistName;
- (void)loadFromDictionary:(NSDictionary *)information;

+ (id)sharedInstance;

- (BOOL)connect;
- (void)disconnect;

- (NSManagedObjectContext *)managedObjectContext_roster;
- (NSManagedObjectContext *)managedObjectContext_capabilities;
- (void)sendMessage:(NSString *)message toID:(NSString *)jid;

@end
