//
//  ViewController.m
//  SJHighPerformanceDemo
//
//  Created by knewcloud on 2017/4/6.
//  Copyright © 2017年 jseanj. All rights reserved.
//

#import "ViewController.h"
#import "SJHighPerformance.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    uint64_t start_64;
    uint64_t end_64;
    uint64_t time_64;
    
    start_64 = mach_absolute_time();
    [NSThread sleepForTimeInterval:0.001];
    end_64 = mach_absolute_time();
    
    time_64 = [SJTimeUtils nanosUsingStart:start_64 end:end_64];
    NSLog(@"%llu", time_64);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
