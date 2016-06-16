//
//  HttpNewTool.h
//  TestProject
//
//  Created by 陈微 on 16/6/16.
//  Copyright © 2016年 九指天下. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ResponseObject.h"

@interface HttpNewTool : NSObject

/**
 *  发送一个POST请求
 *  @param baseUrl 路径
 *  @param params  请求参数
 *  @param finish  请求成功后的回调
 */
+ (void)postWithBaseUrl:(NSString *)baseUrl
                 params:(NSDictionary *)params
          finishedBlock:(void (^)(ResponseObject *response))finish;


@end
