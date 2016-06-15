

#ifndef TestProject_DefineMacro_h
#define TestProject_DefineMacro_h

/**
 * 强弱引用转换，用于解决代码块（block）与强引用self之间的循环引用问题
 * 调用方式: `@weakify_self`实现弱引用转换，`@strongify_self`实现强引用转换
 *
 * 示例：
 * @weakify_self
 * [obj block:^{
 * @strongify_self
 * self.property = something;
 * }];
 */
#ifndef    weakify_self
#if __has_feature(objc_arc)
#define weakify_self autoreleasepool{} __weak __typeof__(self) weakSelf = self;
#else
#define weakify_self autoreleasepool{} __block __typeof__(self) blockSelf = self;
#endif
#endif
#ifndef    strongify_self
#if __has_feature(objc_arc)
#define strongify_self try{} @finally{} __typeof__(weakSelf) self = weakSelf;
#else
#define strongify_self try{} @finally{} __typeof__(blockSelf) self = blockSelf;
#endif
#endif

/**------------------------快速宏定义相关-----------------*/
// 是否为iOS7
#define iOS7 ([[UIDevice currentDevice].systemVersion doubleValue] >= 7.0)
// 是否为iOS8
#define iOS8 ([[UIDevice currentDevice].systemVersion doubleValue] >= 8.0)

#define iOS(version) ([[UIDevice currentDevice].systemVersion doubleValue] >= version)

// 字符串拼接
#define StringWithFormat(FORMAT, ...) [NSString stringWithFormat:FORMAT, ##__VA_ARGS__]
#define StringWithFloat(A) [NSString stringWithFormat:@"%f", A]
#define StringWithInt(A) [NSString stringWithFormat:@"%i", A]
#define StringWithStr(A) (A == nil) ? @"" : A

// 字体设置
#define FontWithSize(f) [UIFont systemFontOfSize:(f)]
// 系统文字大小宏定义;不同分辨率下的字段大小适配
#define AutoFontWithSize(s) FontWithSize(getFontSize(s))

// 屏幕尺寸

#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define iPhone4 (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define iPhone5 (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define iPhone6 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define iPhone6Plus (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

// 常用对象简写
#define kAppDelegate        (AppDelegate *)[[UIApplication sharedApplication] delegate]
#define kWindow             [[[UIApplication sharedApplication] windows] lastObject]
#define kKeyWindow          [[UIApplication sharedApplication] keyWindow]
#define kUserDefaults       [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]
#define kDocuments  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]
#define kImageByName(name)        [UIImage imageNamed:name]
#define kImageByPath(name, ext)   [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:name ofType:ext]]

// 检查系统版本
// 等于
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
// 大于
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
// 大于或等于
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
// 小于
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
// 小于或等于
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define IS_OS_5_OR_LATER                            SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")
#define IS_OS_6_OR_LATER                            SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")
#define IS_OS_7_OR_LATER                            SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")

//字典取值
#define GetObjectFromDicWithKey(dictonary, key , Class) [[dictonary objectForKey:key] isKindOfClass:[Class class]] ? [dictonary objectForKey:key] : nil
//对象取值
#define GetObject(id) (id == nil) ? @"" : id

// 上线用版本信息
#define IosAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
// 测试用版本信息
#define IOSTestVersion [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"]


#endif
