/**
 * @file tools.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TOOLS_H_
#define TOOLS_H_

#include <stdlib.h>
#include <string.h>

#define exit_if(condition, failed_ret, stream, format, args...) \
            if (condition) { \
                fprintf(stream, format, ##args); \
                exit(failed_ret); \
            }
#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

// 把宏字符串化
#define str_temp(x) #x
#define str(x) str_temp(x)

// 获取字符串常量长度
#define STRLEN(CONST_STR) (sizeof(CONST_STR) - 1)

// 计算数组长度
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))


// 强制内存对齐(4K)
#define PG_ALIGN __attribute((aligned(4096)))


// 拼接
#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)
#define concat3(x, y, z) concat(concat(x, y), z)
#define concat4(x, y, z, w) concat3(concat(x, y), z, w)
#define concat5(x, y, z, v, w) concat4(concat(x, y), z, v, w)
// 选择第二项
#define CHOOSE2nd(a, b, ...) b
#define MUX_WITH_COMMA(contain_comma, a, b) CHOOSE2nd(contain_comma a, b)
#define MUX_MACRO_PROPERTY(p, macro, a, b) MUX_WITH_COMMA(concat(p, macro), a, b)

#define __P_DEF_0  X,
#define __P_DEF_1  X,
#define __P_ONE_1  X,
#define __P_ZERO_0 X,

// macro定义则为X
#define MUXDEF(macro, X, Y)  MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)
// macro未定义则为X
#define MUXNDEF(macro, X, Y) MUX_MACRO_PROPERTY(__P_DEF_, macro, Y, X)
// macro定义为1则为X
#define MUXONE(macro, X, Y)  MUX_MACRO_PROPERTY(__P_ONE_, macro, X, Y)
// macro定义为0则为X
#define MUXZERO(macro, X, Y) MUX_MACRO_PROPERTY(__P_ZERO_,macro, X, Y)

// 测试一个宏是否定义
#define ISDEF(macro) MUXDEF(macro, 1, 0)
#define ISNDEF(macro) MUXNDEF(macro, 1, 0)
// 测试一个宏定义为1还是0
#define ISONE(macro) MUXONE(macro, 1, 0)
#define ISZERO(macro) MUXZERO(macro, 1, 0)


#define isdef(macro) (strcmp("" #macro, "" str(macro)) != 0)

#define STRINGIFY(X) "" #X
#define IS_DEFINED(MACRO) ({ \
    _Static_assert(__builtin_constant_p(_builtin_strcmp("" #MACRO, STRINGIFY(MACRO))) == 1, "Not compile-time!"); \
    strcmp("" #MACRO, STRINGIFY(MACRO)); \
    })


#define __IGNORE(...)
#define __KEEP(...) __VA_ARGS__
#define IFDEF(macro, ...) MUXDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
#define IFNDEF(macro, ...) MUXNDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
#define IFONE(macro, ...) MUXONE(macro, __KEEP, __IGNORE)(__VA_ARGS__)
#define IFZERO(macro, ...) MUXZERO(macro, __KEEP, __IGNORE)(__VA_ARGS__)

#endif