/**
 * @file wz_link_list.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 链式存储结构-链表
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef WZ_LINK_LIST_H_
#define WZ_LINK_LIST_H_

#include "wz_link_list.h"
#include "alias.h"

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/* 索引错误返回的错误值 */
#define ERROR_VAL INT_MAX
/* 未查找到返回的错误索引值 */
#define ERROR_POS INT_MAX

/* 链表抽象数据结构 */
struct link_list 
{
    elem_t data;            // 头节点数据域存储链表长度
    struct link_list *next;
};

/* 链表初始化 */
extern struct link_list *init_linklist(void);
/* 通过索引获取链表节点值 */
extern elem_t linklist_at(struct link_list ll, index_t pos);
/* 通过值查找节点位置 */
extern index_t linklist_find(struct link_list ll, elem_t elem);
/* 指定位置插入新节点 */
extern void linklist_insert(struct link_list *ll_ptr, index_t pos, elem_t elem);
/* 指定位置删除节点 */
extern void linklist_delete(struct link_list *ll_ptr, index_t pos);
/* 替换元素 */
extern void linklist_replace(struct link_list *ll_ptr, index_t pos, elem_t elem);
/* 清空释放链表 */
extern void linklist_clear(struct link_list **ll_pptr);

/**
 * @brief 判断链表是否为空，若为空返回true，否则返回false
 * 
 * @param ll 链表结构体
 * @return true 链表为空（仅有头节点）
 * @return false 链表非空
 */
static inline bool is_empty_linklist(struct link_list ll)
{
    return (NULL == ll.next);
}

/**
 * @brief 获取链表长度
 * 
 * @param ll 链表结构体
 * @return lens_t 链表长度
 */
static inline lens_t get_linklist_length(struct link_list ll)
{
    return ll.data;
}

#endif // WZ_LINK_LIST_H_

