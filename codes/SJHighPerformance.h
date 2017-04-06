#import "SJTimeUtils.h"
#import <sys/kdebug_signpost.h>
#import <mach/mach.h>

#define SJ_AT_LEAST_IOS10  (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_10_0)

#ifndef DBG_MACH_CHUD
#define DBG_MACH_CHUD 0x0A
#define DBG_FUNC_START 1
#define DBG_FUNC_END 2
#define DBG_APPS 33
#define SYS_kdebug_trace 180
#define KDBG_CODE(Class, SubClass, code) (((Class & 0xff) << 24) | ((SubClass & 0xff) << 16) | ((code & 0x3fff)  << 2))
#define APPSDBG_CODE(SubClass,code) KDBG_CODE(DBG_APPS, SubClass, code)
#endif

#define SJProfilingSignpost(x) \
SJ_AT_LEAST_IOS10 ? kdebug_signpost(x, 0, 0, 0, (uint32_t)(x % 4)) \
: syscall(SYS_kdebug_trace, APPSDBG_CODE(DBG_MACH_CHUD, x) | DBG_FUNC_NONE, 0, 0, 0, (uint32_t)(x % 4));

#define SJProfilingSignpostStart(x, y) \
SJ_AT_LEAST_IOS10 ? kdebug_signpost_start((uint32_t)x, (uintptr_t)y, 0, 0, (uint32_t)(x % 4)) \
: syscall(SYS_kdebug_trace, APPSDBG_CODE(DBG_MACH_CHUD, x) | DBG_FUNC_START, (uintptr_t)y, 0, 0, (uint32_t)(x % 4));

#define SJProfilingSignpostEnd(x, y) \
SJ_AT_LEAST_IOS10 ? kdebug_signpost_end((uint32_t)x, (uintptr_t)y, 0, 0, (uint32_t)(x % 4)) \
: syscall(SYS_kdebug_trace, APPSDBG_CODE(DBG_MACH_CHUD, x) | DBG_FUNC_END, (uintptr_t)y, 0, 0, (uint32_t)(x % 4));
