//  ----------API Sever-----------
//
//  Support Inbox thenamk3.net & nemg.me
//  Created by Nem'G
//
//  -------Support Project--------

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <zlib.h>

void _NemGLog(NSString *format, ...);
#define ServerLog(...) _NemGLog(__VA_ARGS__)

NS_ASSUME_NONNULL_BEGIN
@interface Menu : NSObject
+ (void)startWithRemoteHTMLURL:(NSString *)url;
+ (id)getValueForKey:(NSString *)key;
+ (NSDictionary *)getAllState;
+ (void)saveState;
+ (void)loadState;
@end
NS_ASSUME_NONNULL_END


#pragma mark - Ví dụ sử dụng

/*
 // Trong AppDelegate.m:
 #import "Menu.h"

 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
     // 1) Nạp config cũ (nếu có)
     [Menu loadState];

     // 2) Khởi Web‐UI, mở tại http://<your-ip>:12222
     [Menu startWithRemoteHTMLURL:@"https://thenamk3.net/filemanager/demo.html"];
     return YES;
 }

 // Một hàm cập nhật logic đơn giản:
 - (void)updateLogic {
     // Đọc các tuỳ chọn đã lưu
     BOOL aimbotEnabled   = [[Menu getValueForKey:@"aimbot"] boolValue];
     int  espRange        = [[Menu getValueForKey:@"esp_range"] intValue];
     float fov            = [[Menu getValueForKey:@"fov_radius"] floatValue];
     NSString *playerName = [Menu getValueForKey:@"player_name"];
     NSString *aimMode    = [Menu getValueForKey:@"aim_mode"];

     NSLog(@"[NemGHook] Aimbot=%d | ESP=%d | FOV=%.2f | Name=%@ | Mode=%@",
           aimbotEnabled, espRange, fov, playerName, aimMode);

     // Áp dụng logic game
     if (aimbotEnabled) {
         // Ví dụ: triggerAim(fov, aimMode);
     }
 }

 // Khi người dùng thay đổi tuỳ chọn qua Web-UI:
 - (void)onUserDidChangeSetting {
     [Menu saveState];
 }

 // Nếu cần khôi phục cấu hình mặc định:
 - (void)onResetSettings {
     [Menu loadState];
     [self updateLogic];
 }
*/