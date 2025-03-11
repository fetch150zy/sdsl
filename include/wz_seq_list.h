/**
 * @file wz_seq_list.h
 * @author fetcha150zy (Mars_zhewei@outlook.com)
 * @brief 顺序表头文件，包含顺序表数据结构声明和函数外部函数接口声明
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef WZ_SEQ_LIST_H_ // 防止重复包含头文件
#define WZ_SEQ_LIST_H_

#include "wz_seq_list.h"
#include "alias.h"

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/* 查询失败返回的错误值 */
#define ERROR_VAL INT_MAX

/* 查询失败返回的错误索引 */
#define ERROR_POS INT_MAX

/* 顺序表抽象数据结构，使用数组实现 */
/* 从0开始索引 */
struct sq_list
{
    elem_t elems[CONTAINER_SIZE];   // 数据
    lens_t length;                  // 元素个数
};

/* 顺序表初始化 */
extern struct sq_list* init_sqlist(void);
/* 通过索引获取值 */
extern elem_t sqlist_at(struct sq_list sql, index_t pos);
/* 通过值获取索引 */
extern index_t sqlist_find(struct sq_list sql, elem_t elem);
/* 插入元素 */
extern bool sqlist_insert(struct sq_list* sql_ptr, index_t pos, elem_t elem);
/* 删除元素 */
extern bool sqlist_delete(struct sq_list* sql_ptr, index_t pos, elem_t *elem_ptr);
/* 替换元素 */
extern bool sqlist_replace(struct sq_list* sql_ptr, index_t pos, elem_t elem);
/* 清空顺序表 */
extern void sqlist_clear(struct sq_list** sql_pptr);

/**
 * @brief 判断顺序表是否为空，若为空返回true，否则返回false
 * 为内联函数，定义在头文件中
 * @param sql 顺序表结构体
 * @return true 空顺序表
 * @return false 非空顺序表
 */
static inline bool is_empty_sqlist(struct sq_list sql)
{
    return (0 == sql.length);
}

/**
 * @brief 获取顺序表的长度
 * 
 * @param sql 顺序表数据结构
 * @return lens_t 元素个数 
 */
static inline lens_t get_sqlist_length(struct sq_list sql)
{
    return (sql.length);
}

#endif // LIST_H_

