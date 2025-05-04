#import <Foundation/Foundation.h>
#import "ViewController.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BeautyControlStyle) {
    BeautyControlStyleSwitch = 1,       // Công tắc bật tắt
    BeautyControlStyleSlider = 2,       // Thanh trượt
    BeautyControlStyleSegment = 3,      // Chọn mục (nhiều lựa chọn)
    BeautyControlStyleButton  = 4,      // Nút bấm
    BeautyControlStyleInputText = 5     // Ô nhập văn bản
};
extern NSArray *configs;
extern NSString *autoLabeltext;
extern NSString *HeaderName;
@interface BeautyListModel : NSObject

@property (nonatomic, copy) NSString *title;

/// Điều khiển loại nào (Switch, Slider, Segment, Button)
@property (nonatomic, assign) NSInteger Style;

/// Trạng thái bật/tắt cho UISwitch
@property (nonatomic, assign) BOOL open;

/// Giá trị cho UISlider
@property (nonatomic, assign) NSInteger slider;

/// Tiêu đề các segment (nếu là segmentedControl)
@property (nonatomic, copy, nullable) NSArray<NSString *> *segmentTitles;

/// Tiêu đề nút (nếu là button)
@property (nonatomic, copy, nullable) NSString *buttonTitle;

@property (nonatomic, assign) float minValue;
@property (nonatomic, assign) float maxValue;

/// Placeholder cho ô nhập liệu nếu là UITextField
@property (nonatomic, copy, nullable) NSString *inputPlaceholder;

+ (void)handleSliderEvent:(NSString *)title value:(NSInteger)value;
+ (void)handleEvent:(NSString *)title open:(BOOL)open;
+ (void)handleSegmentEvent:(NSString *)title selectedIndex:(NSInteger)index;
+ (void)handleButtonEvent:(NSString *)title;
+ (void)handleInputText:(NSString *)title content:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
