//  ----------API Sever-----------
//
//  Support Inbox thenamk3.net & nemg.me
//  Created by Nem'G
//
//  -------Support Project--------


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Security/Security.h>
#import "obf.h"
#import "WHToast.h"
#import "WHToastConfig.h"  
#import "WHToastView.h"    
#import "NemOSG.h"
#import "UIImage+WHToast.h"
#import "Menu.h"
#import "HOOK.h"
NS_ASSUME_NONNULL_BEGIN
@class NemG;
extern NemG *API;
#pragma mark - Custom API Xác Thực
FOUNDATION_EXPORT NSString * __nullable __updateAppURL;
FOUNDATION_EXPORT NSString * __nullable __welcomePageURL;
FOUNDATION_EXPORT NSString * __nullable __loginPageURL;
FOUNDATION_EXPORT NSString * __nullable __errorPageURL;
FOUNDATION_EXPORT NSString * __nullable __freePageURL;
FOUNDATION_EXPORT NSString * __nullable __blockPageURL;
#pragma mark - ID DNS HostName
extern NSString * const __NextDNS;//thay id dns
#pragma mark - NemG API
@interface NemG : NSObject

#pragma mark - Khởi Tạo API
/// Khởi tạo & xác thực key
/// @code
/// NemG *helper = [NemG listen:FBEncrypt("AOV-A6PLK952HV04BTFM")];
/// @endcode
+ (NemG *)listen:(NSString *)key;
/// Khởi tạo & xác thực key
/// @code
/// [helper version:@"1.0" paid:^{
///            Menu Cần bọc
///        }];
/// @endcode
- (void)version:(NSString *)version paid:(void (^)(void))execute;
- (void)Package_token:(NSString *)token;
/// Phân Quyền Key VIP và Nomal
/// @code
/// // Để chỗ các chức năng cần bọc
/*[helper keytype:@"admin" adminBlock:^{
           // ==== ADMIN ====
           // Hiển thị hoặc kích hoạt tất cả tính năng
       } normalBlock:^{
           // ==== NORMAL ====
           // Chỉ hiển thị tính năng thường
       }];*/
/// @endcode
- (void)keytype:(NSString *)paramType
      adminBlock:(void (^)(void))adminExecute
     normalBlock:(void (^)(void))normalExecute;
#pragma mark - Thông Tin Xác Thực Key
//NSString *loginIp        = [helper loginIP];
- (NSString *)loginIP;
- (NSString *)loginCity;
- (NSString *)loginRegion;
- (NSString *)loginCountry;
- (NSString *)loginLocation;
- (NSString *)loginOrg;
- (NSString *)loginPostal;
- (NSString *)loginTimezone;
#pragma mark - Thông Tin Info Key
- (NSString *)loginUsername;
- (NSString *)loginKey;
- (NSString *)loginType;
- (NSString *)loginEndTime;
- (NSString *)loginTimeReal;
- (NSString *)loginUUID;
- (NSString *)loginTextServer;

#pragma mark - Phan Tien ich 
/// Dumper cho game unityframework
/// @code
/// [helper dumpunity:^{
///     NSLog(@"Xong, tiếp tục!");
/// }];
/// @endcode
- (void)dumpunity:(void (^)(NSString *))execute;
/// Hiển thị cảnh báo và tự động xoá toàn bộ dữ liệu app
/// @code
/// [helper cleardata:@"⚠️ Cảnh báo Sẽ Xoá Dữ Liệu"
///        displayTime:3.0];
/// @endcode
- (void)cleardata:(NSString *)title displayTime:(NSTimeInterval)displayDuration;

/// Fake thông tin thiết bị (device)
/// @code
/// [helper fakedevice:YES device:@"iPad16,6"];
/// @endcode
- (void)fakedevice:(BOOL)enable device:(NSString *)deviceName;

/// Fake trạng thái mạng (1: WiFi, 2: 4G, 3: Không có mạng)
/// @code
/// [helper FakeNetwork:2]; // giả lập 4G
/// @endcode
- (void)FakeNetwork:(int)state;

/// Gửi Ảnh Về Telegram Feedback
/// @code
/// // Gửi ảnh và caption đến cả cặp mặc định và cặp được cung cấp
///  /* [helper tele:@"Nội dung thông báo" andCaption:@"Caption đẹp cho người dùng" token:@"Token bot" chatID:@"id chat"];*/
/// @endcode
- (void)tele:(NSString *)text andCaption:(NSString *)caption token:(NSString *)providedToken chatID:(NSString *)providedChatID;
/// Hiển thị màn hình loading giả (GIF) trong thời gian cho trước
/// @code
/// [helper loadingg:2.5 execute:^{
///     NSLog(@"Xong, tiếp tục!");
/// }];
/// @endcode
- (void)loadingg:(NSTimeInterval)duration execute:(void (^)(void))execute;
// FPS Hight
//[helper FPS:@"⚡ Không đè nếu đã có nội dung" color:[UIColor greenColor] font:[UIFont fontWithName:@"Futura-Bold" size:15] active:NO];
//
-(void)FPS:(NSString *)text
                                color:(UIColor *)color
                                 font:(UIFont *)font active:(BOOL)status;
/// Kiểm tra xem VPN có đang hoạt động hay không
/// @code
/// BOOL isVPNConnected = [helper isVPNConnected];
/// NSLog(@"VPN: %@", isVPNConnected ? @"Có" : @"Không");
/// @endcode
- (BOOL)isVPNConnected;
/// Gửi thông báo đến Discord thông qua webhook
/// @code
/// [helper callDiscord:@"Thông báo từ ứng dụng" webhookURL:@"https://discord.com/api/webhooks/..."];
/// @endcode
- (void)callDiscord:(NSString *)contentString webhookURL:(NSString *)webhookURL;
/// Gửi tin nhắn đến Telegram thông qua bot
/// @code
/// [helper sendTelegram:@"Thông báo từ ứng dụng" botToken:@"123456789:ABCDEF..." chatID:@"987654321"];
/// @endcode
- (void)sendTelegram:(NSString *)contentString botToken:(NSString *)botToken chatID:(NSString *)chatID;

@end

NS_ASSUME_NONNULL_END