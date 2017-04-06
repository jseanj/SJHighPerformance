#import <Foundation/Foundation.h>

@interface SJTimeUtils : NSObject
+(uint64_t)timeBlock:(void (^)(void))block;
+(uint64_t)nanosUsingStart:(uint64_t)start end:(uint64_t)end;
@end
