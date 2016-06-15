//
//  UIColor+Extension.h
//  YYFocus
//
//  Created by 陈微 on 16/6/15.
//  Copyright © 2016年 九指天下. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (Extension)

/**
 *  根据颜色字符串得到颜色
 */
+ (UIColor *)colorWithHexString:(NSString *)color;

+ (UIColor*)colorWithKey:(NSUInteger)key;

- (CGFloat)red;
- (CGFloat)green;
- (CGFloat)blue;
- (CGFloat)alpha;

- (UIColor *)darkerColor;
- (UIColor *)lighterColor;
- (BOOL)isLighterColor;
- (BOOL)isClearColor;

@end
