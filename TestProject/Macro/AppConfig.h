
#ifndef TestProject_AppConfig_h
#define TestProject_AppConfig_h

#ifdef DEBUG  // 调试状态, 打开LOG功能
#define YYLog(format, ...) do {                                                                     \
fprintf(stderr, "<%s : %d> %s\n",                                           \
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],  \
__LINE__, __func__);                                                        \
(NSLog)((format), ##__VA_ARGS__);                                           \
fprintf(stderr, "-------\n");                                               \
} while (0)
#else         // 发布状态, 关闭LOG功能
#define YYLog(...)
#endif

// 颜色值
#define ColorWithRGB(r, g, b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
#define ColorRandom ColorWithRGB(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256),1.0)
#define ColorWithKey(obj) [UIColor colorWithKey:obj]
#define ColorWithHex(obj) [UIColor colorWithHexString:obj]

#endif
