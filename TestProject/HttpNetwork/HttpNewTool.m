//
//  HttpNewTool.m
//  TestProject
//
//  Created by 陈微 on 16/6/16.
//  Copyright © 2016年 九指天下. All rights reserved.
//

#import "HttpNewTool.h"

@implementation HttpNewTool

/**
 *  发送一个POST请求
 */

+ (void)postWithBaseUrl:(NSString *)baseUrl
                 params:(NSDictionary *)params
          finishedBlock:(void (^)(ResponseObject *response))finish
{
    
    if([CoreStatus currentNetWorkStatus] == CoreNetWorkStatusNone){
        ResponseObject *response = [[ResponseObject alloc] init];
        response.code = CodeTypeNoNetWork;
        response.message = @"网络未连接，请查看网络";
        YYLog(@"网络未连接，请查看网络");
        if (finish) {
            finish(response);
        }
        return;
    }
    
    AFSecurityPolicy *securityPolicy = [[AFSecurityPolicy alloc] init];
    [securityPolicy setAllowInvalidCertificates:YES];
    
    // 获得请求管理者
    AFHTTPSessionManager *mgr = [AFHTTPSessionManager manager];
    
    [mgr setSecurityPolicy:securityPolicy];
    
    // 返回的数据格式
    mgr.responseSerializer = [AFJSONResponseSerializer serializer];
    mgr.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json", @"text/json", @"text/javascript", @"text/html",nil];
    [mgr.requestSerializer setTimeoutInterval:30];
    
    // 设置请求头
    NSMutableDictionary *headParams = [self getCommenHeadParams];
    if (headParams.count > 0) {
        NSArray *allkeys = [headParams allKeys];
        for (int i = 0; i<headParams.count; i++) {
            NSString *key = [allkeys objectAtIndex:i];
            id value = [headParams objectForKey:key];
            [mgr.requestSerializer setValue:value forHTTPHeaderField:key];
        }
    }
    
    // 发送POST请求
    [mgr POST:baseUrl parameters:params progress:^(NSProgress * _Nonnull uploadProgress) {
        
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        if([responseObject isKindOfClass:[NSDictionary class]]){
            NSHTTPURLResponse *response = (NSHTTPURLResponse *)task.response;
            YYLog(@"\n <Http-POST请求路径>:-->%@  \n  <请求头>:%@  \n  <请求参数>:%@  \n  <返回的请求头>:%@  \n  <返回的JSON>:%@",baseUrl,mgr.requestSerializer.HTTPRequestHeaders,params,response.allHeaderFields,responseObject);
            
            ResponseObject *responseObj = nil;//[ResponseObject mj_objectWithKeyValues:responseObject];
//            responseObj.jsonDic = responseObject;
            
            if (finish) {
                finish(responseObj);
            }
        }

    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        ResponseObject *response = [[ResponseObject alloc] init];
        response.code = CodeTypeFail;
        response.message = @"请求失败，请重试";
        if (finish) {
            finish(response);
        }
        
        YYLog(@"\n  <Http-POST请求方法method>:-->%@  \n <请求头>:%@  \n  <请求参数>:%@  \n  <返回错误信息>:%@",baseUrl,mgr.requestSerializer.HTTPRequestHeaders,params,error);
    }];
}

// 共同头参数
+ (NSMutableDictionary *)getCommenHeadParams
{
    NSMutableDictionary *headDic = [NSMutableDictionary dictionaryWithCapacity:0];
    return headDic;
}

@end
