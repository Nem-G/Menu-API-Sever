#import "Esp/MBProgressHUD.h"
#import "Menu/NemG/BeautyListModel.h"
#include <sqlite3.h>
#define kWidth  [UIScreen mainScreen].bounds.size.width
#define kHeight [UIScreen mainScreen].bounds.size.height 
#import <UIKit/UIKit.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIAlertView.h>
#import <Foundation/Foundation.h>
#import <NemG/NemG.h>

NemG* API;
@implementation  BeautyListModel

NSString * __updateAppURL   = FBEncrypt("https://thenamk3.net/sever/update.html");
NSString * __welcomePageURL = FBEncrypt("https://thenamk3.net/sever/welcome.html");
NSString * __loginPageURL   = FBEncrypt("https://thenamk3.net/sever/key.html");
NSString * __errorPageURL   = FBEncrypt("https://thenamk3.net/sever/error.html");
NSString * __freePageURL    = FBEncrypt("https://thenamk3.net/sever/free.html");
NSString *  __blockPageURL   = FBEncrypt("https://thenamk3.net/sever/free.html");

NSString * const __NextDNS        = FBEncrypt("7274c6");
+(void)load {
    API = [NemG listen:FBEncrypt("AOV-QWM6IUZCRN9J5FH1")];
    [API Package_token:@"e5b02bdb5fd4d9b962e6cfb3cde753f4"];

    [API version:@"3.0" paid:^{

     dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
           [ViewController openmenu];  
    });

           NSLog(@"Key Your: %@",[API loginKey]);
           NSLog(@"UDID Your: %@",[API loginUUID]);
           NSLog(@"Text Sever: %@",[API loginTextServer]);
           NSLog(@"Text Sever: %@",[API loginIP]);
       }];
    
}
//---------------------Main Menu---------------------//

NSURL *iconURL = [NSURL URLWithString:@"https://github.com/ntnamk3/data-by-nemg/blob/thenamk3/image/menu.jpeg?raw=true"];
NSString *HeaderName = @"NemG VN";
NSString *autoLabeltext = @"Honor of kings - Copyrigjt Nem'G / 2025 , All right reserved";
NSArray *configs = @[
        @{@"title": @"Hack Map", @"style": @1},//1 = switch, 2 = slider, 3 = segment, 4 = button, 5 = input
        @{@"title": @"Cam Xa 30", @"style": @1},
        @{@"title": @"Cam Xa 50", @"style": @1},
        @{@"title": @"Cam Xa", @"style": @2, @"slider": @5, @"minValue": @1, @"maxValue": @15},
        @{@"title": @"Chế độ chơi", @"style": @3, @"segmentTitles": @[@"Đơn", @"Đội", @"Rank"]},
        @{@"title": @"Kích hoạt", @"style": @4, @"buttonTitle": @"Bắt đầu"},
        @{@"title": @"Nhập mã truy cập", @"style": @5, @"inputPlaceholder": @"Imput"}
    ];
 
+ (void)handleSliderEvent:(NSString *)title value:(NSInteger)value {
    dispatch_queue_t queue = dispatch_queue_create("com.garena.game.kgvn", DISPATCH_QUEUE_SERIAL);

    if ([title isEqualToString:@"Cam Xa"]) {
        dispatch_async(queue, ^{
           
        });
    }
}
+ (void)handleEvent:(NSString *)title open:(BOOL)open {
    dispatch_queue_t queue = dispatch_queue_create("com.garena.game.kgvn", DISPATCH_QUEUE_SERIAL);
    
    if ([title isEqualToString:@"Hack Map"]) {
        dispatch_async(queue, ^{


            if (open) {

        
                  

            } else {
                
            }
        });
    } 
    else if ([title isEqualToString:@"Cam Xa 30"]) {
        dispatch_async(queue, ^{
            if (open) {
                // Xử lý khi mở Cam Xa 30
            } else {
                // Xử lý khi tắt Cam Xa 30
            }
        });
    } 
    else if ([title isEqualToString:@"Cam Xa 50"]) {
        dispatch_async(queue, ^{
            if (open) {
                // Xử lý khi mở Cam Xa 50
            } else {
                // Xử lý khi tắt Cam Xa 50
            }
        });
    }
}

+ (void)handleSegmentEvent:(NSString *)title selectedIndex:(NSInteger)index {
    dispatch_queue_t queue = dispatch_queue_create("com.garena.game.kgvn", DISPATCH_QUEUE_SERIAL);
    dispatch_async(queue, ^{
        if ([title isEqualToString:@"Chế độ chơi"]) {
            switch (index) {
                case 0:
                    NSLog(@"Chế độ: Đơn");
                    break;
                case 1:
                    NSLog(@"Chế độ: Đội");
                    break;
                case 2:
                    NSLog(@"Chế độ: Rank");
                    break;
                default:
                    break;
            }
        }
    });
}

+ (void)handleButtonEvent:(NSString *)title {
    dispatch_async(dispatch_get_main_queue(), ^{
        if ([title isEqualToString:@"Kích hoạt"]) {
            MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
            hud.label.text = @"Đang xử lý...";
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [hud hideAnimated:YES];
                NSLog(@"Đã kích hoạt: %@", title);
            });
        }
    });
}

+ (void)handleInputText:(NSString *)title content:(NSString *)text {
    if ([title isEqualToString:@"Nhập mã truy cập"]) {
        if ([text isEqualToString:@"vipcode123"]) {
            NSLog(@"🎉 Kích hoạt thành công mã: %@", text);
        } else {
            NSLog(@"⛔️ Mã không hợp lệ: %@", text);
        }
    }
}

@end
    
