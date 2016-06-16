//
//  ViewController.m
//  TestProject
//
//  Created by 陈微 on 16/6/1.
//  Copyright © 2016年 九指天下. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor =  ColorRandom;
    
    [HttpNewTool postWithBaseUrl:@"http://www.weather.com.cn/data/sk/101010100.html" params:@{@"cityId":@"111111"} finishedBlock:^(ResponseObject *response) {
        
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
