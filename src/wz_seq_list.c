/**
 * @file wz_seq_list.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 基础数据结构-线性表，通过数组实现 
 * @version 0.2
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "wz_seq_list.h"
#include "tools.h"

#include <stdlib.h>
#include <string.h>

#if __STDC_VERSION__ < 201710L
#error "C version must be C17 or higher"
#endif

/**
 * @brief 初始化顺序表，将顺序表的长度置为0，将顺序表的元素置为0
 * 
 * @return struct sq_list* 初始化之后的顺序表指针
 */
struct sq_list* init_sqlist(void)
{
    struct sq_list *sql_ptr = (struct sq_list *)malloc(sizeof(struct sq_list));

    if (NULL == sql_ptr)
        handle_error("malloc");

    memset(sql_ptr->elems, 0, sizeof(sql_ptr->elems));
    sql_ptr->length = 0;
    return sql_ptr;
}

/**
 * @brief 通过索引获取顺序表中的元素
 * 
 * @param sql 顺序表数据结构
 * @param pos 索引
 * @return elem_t 元素值
 */
elem_t sqlist_at(struct sq_list sql, index_t pos)
{
    if (is_empty_sqlist(sql)) {
        perror("The sq_list is empty.");
        goto bad_ret;
    }
    if (pos < 0 || pos >= get_sqlist_length(sql)) {
        perror("The pos is out of bounds");
        goto bad_ret;
    }
    return sql.elems[pos];

bad_ret:
    return ERROR_VAL;
}

/**
 * @brief 查找元素索引
 * 
 * @param sql 顺序表数据结构
 * @param elem 元素值
 * @return index_t 元素索引 
 */
index_t sqlist_find(struct sq_list sql, elem_t elem)
{
    if (is_empty_sqlist(sql)) {
        perror("The sq_list is empty.");
        goto bad_ret;
    }
    lens_t lens = get_sqlist_length(sql);
    for (index_t i = 0; i < lens; ++i)
        if (elem == sql.elems[i])
            return i;
            
bad_ret:
    return ERROR_POS; // 查询失败
}

/**
 * @brief 在顺序表中插入元素
 * 
 * @param sql_ptr 顺序表指针
 * @param pos 索引
 * @param elem 插入元素
 */
bool sqlist_insert(struct sq_list* sql_ptr, index_t pos, elem_t elem)
{
    lens_t lens = get_sqlist_length(*sql_ptr);
    if (CONTAINER_SIZE == lens) {
        perror("The sq_list is full. Insert failed.");
        goto bad_ret;
    } else {
        if (pos < 0 || pos > lens) {
            perror("The pos is out of bounds. Insert failed.");
            goto bad_ret;
        } else {
            for (index_t i = lens - 1; i >= pos; --i)
                sql_ptr->elems[i + 1] = sql_ptr->elems[i];
            sql_ptr->elems[pos] = elem;
            sql_ptr->length += 1;

            return true;
        }
    }
bad_ret:
    return false;
}

/**
 * @brief 删除顺序表中的元素
 * 
 * @param sql_ptr 顺序表指针
 * @param pos 索引
 */
bool sqlist_delete(struct sq_list* sql_ptr, index_t pos, elem_t *elem_ptr)
{
    if (is_empty_sqlist(*sql_ptr)) {
        perror("The sq_list is empty. Delete failed.");
        goto bad_ret;
    } else {
        lens_t lens = get_sqlist_length(*sql_ptr);
        if (pos < 0 || pos >= lens) {
            perror("The pos is out of bounds. Delete failed.");
            goto bad_ret;
        } else {
            *elem_ptr = sql_ptr->elems[pos];
            for (index_t i = pos; i < lens - 1; ++i)
                sql_ptr->elems[i] = sql_ptr->elems[i + 1];
            sql_ptr->length -= 1;

            return true;
        }
    }
bad_ret:
    return false;
}

/**
 * @brief 替换顺序表中的元素
 * 
 * @param sql_ptr 顺序表指针
 * @param pos 索引
 * @param elem 替换元素
 */
bool sqlist_replace(struct sq_list* sql_ptr, index_t pos, elem_t elem)
{
    if (is_empty_sqlist(*sql_ptr)) {
        perror("The sq_list is empty. Replace failed.");
        goto bad_ret;
    } else {
        if (pos < 0 || pos >= get_sqlist_length(*sql_ptr)) {
            perror("The pos is out of bounds. Replace failed.");
            goto bad_ret;
        } else {
            sql_ptr->elems[pos] = elem;

            return true;
        }
    }
bad_ret:
    return false;
}

/**
 * @brief 释放顺序表
 * 
 * @param sql_pptr 顺序表双重指针
 */
void sqlist_clear(struct sq_list** sql_pptr)
{
    if (NULL == *sql_pptr)
        handle_error("The sq_list is been freed.");

    free(*sql_pptr);
    *sql_pptr = NULL;
}

