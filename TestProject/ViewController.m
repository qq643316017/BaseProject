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
    // FIXME:hehe
    UIButton* button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:@"hehe" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [self.view addSubview:button];
    button.frame = CGRectMake(40, 40, 100, 30);
    [button addTarget:self action:@selector(buttonPress) forControlEvents:UIControlEventTouchUpInside];
}

- (void)buttonPress
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"hehe" message:@"haha" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:nil];
    [alert show];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
