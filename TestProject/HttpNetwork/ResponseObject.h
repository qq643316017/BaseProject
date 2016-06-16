//
//  ResponseObject.h
//  TestProject
//
//  Created by 陈微 on 16/6/16.
//  Copyright © 2016年 九指天下. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, CodeType){
    CodeTypeFail = -911,        // 请求失败
    CodeTypeNoNetWork = -811,   // 没有网络
    CodeTypeSucceed = 0,        // 请求成功
};

@interface ResponseObject : NSObject

/** 整个返回的JSON字典 */
@property (nonatomic, strong) NSDictionary *jsonDic;
/** 已经解析的具体数据 */
@property (nonatomic, strong) id obj;
/** 状态码 0:请求成功 -911:请求失败 其它code码根据具体接口文档定义 */
@property (nonatomic, assign) CodeType code;
/** 客户端展示的提示 */
@property (nonatomic, copy) NSString *message;


@end
