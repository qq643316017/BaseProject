//
//  UIView+Frame.h
//  TestProject
//
//  Created by 陈微 on 16/6/15.
//  Copyright © 2016年 九指天下. All rights reserved.
//

#import <UIKit/UIKit.h>

CGPoint CGRectGetCenter(CGRect rect);
CGRect  CGRectMoveToCenter(CGRect rect, CGPoint center);

@interface UIView (Frame)

@property (nonatomic, assign) CGFloat xv;
@property (nonatomic, assign) CGFloat yv;
@property (nonatomic, assign) CGFloat centerXv;
@property (nonatomic, assign) CGFloat centerYv;
@property (nonatomic, assign) CGFloat widthv;
@property (nonatomic, assign) CGFloat heightv;

@property (nonatomic, assign) CGSize sizev;
@property (nonatomic, assign) CGPoint originv;

@property (nonatomic, assign) CGFloat topv;
@property (nonatomic, assign) CGFloat leftv;
@property (nonatomic, assign) CGFloat bottomv;
@property (nonatomic, assign) CGFloat rightv;

@property (readonly) CGPoint bottomLeftv;
@property (readonly) CGPoint bottomRightv;
@property (readonly) CGPoint topRightv;


-(UIViewController *)viewController;

@end
