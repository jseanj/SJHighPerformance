#import "SJTimeUtils.h"
#import <mach/mach_time.h>

@implementation SJTimeUtils
+(mach_timebase_info_data_t *)timeBaseInfoData {
    static mach_timebase_info_data_t info;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        mach_timebase_info(&info);
    });
    return &info;
}

+(uint64_t)timeBlock:(void (^)(void))block {
    uint64_t start = mach_absolute_time ();
    block ();
    uint64_t end = mach_absolute_time ();
    return [self nanosUsingStart:start end:end];
}

+(uint64_t)nanosUsingStart:(uint64_t)start end:(uint64_t)end {
    mach_timebase_info_data_t *info = [self timeBaseInfoData];
    
    uint64_t elapsed = end - start;
    uint64_t nanos = elapsed * info->numer / info->denom;
    return nanos;
}

@end
