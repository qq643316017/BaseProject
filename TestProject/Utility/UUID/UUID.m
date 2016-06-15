//
//  UUID.m
//  YYFocus
//
//  Created by 陈微 on 15/11/2.
//  Copyright All rights reserved.
//

#import "UUID.h"
#import "SSKeychain.h"

@implementation UUID

+ (NSString *)getUUID
{
    NSString *strUUID = [SSKeychain passwordForService:@"com.jztx.YYFocus"account:@"UUID"];
    
    //首次执行该方法时，uuid为空
    if (!strUUID)
    {
        CFUUIDRef uuidRef = CFUUIDCreate(kCFAllocatorDefault);
        
        strUUID = (NSString *)CFBridgingRelease(CFUUIDCreateString (kCFAllocatorDefault,uuidRef));
        strUUID = [strUUID stringByReplacingOccurrencesOfString:@"-" withString:@""];
        
        [SSKeychain setPassword: [NSString stringWithFormat:@"%@", strUUID]
                     forService:@"com.jztx.YYFocus"account:@"UUID"];
        
        CFRelease(uuidRef);
    }
    
    if([strUUID rangeOfString:@"-"].length > 0){
        strUUID = [strUUID stringByReplacingOccurrencesOfString:@"-" withString:@""];
        [SSKeychain setPassword: [NSString stringWithFormat:@"%@", strUUID]
                     forService:@"com.jztx.YYFocus"account:@"UUID"];
    }
    
    return strUUID;
}

@end
