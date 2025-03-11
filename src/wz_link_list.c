/**
 * @file wz_link_list.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 链式存储结构-链表
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "wz_link_list.h"
#include "tools.h"

#include <stdlib.h>

#if __STDC_VERSION__ < 201710L
#error "C version must be C17 or higher"
#endif

/**
 * @brief 索引转节点指针
 * 
 * @param ll 链表结构体
 * @param pos 索引
 * @return struct link_list* 索引所在节点的指针
 */
static struct link_list *get_node_ptr_by_pos(struct link_list ll, index_t pos)
{
    struct link_list *p = ll.next;
    index_t cnt = 1;
    while (NULL != p && cnt < pos) {
        p = p->next;
        cnt++;
    }
    if (NULL == p || cnt > pos)
        return NULL;
    return p;
}

/**
 * @brief 创建头结点
 * 
 * @return struct link_list* 链表头结点
 */
struct link_list *init_linklist(void)
{
    struct link_list *head_ptr = (struct link_list *)malloc(sizeof(struct link_list));
    if (NULL == head_ptr)
        handle_error("malloc");
    
    head_ptr->next = NULL;
    head_ptr->data = 0;
    return head_ptr;
}

/**
 * @brief 通过索引获取指定节点的值
 * 
 * @param ll 链表结构体
 * @param pos 索引
 * @return elem_t 该索引节点的值
 */
elem_t linklist_at(struct link_list ll, index_t pos)
{
    struct link_list *p = get_node_ptr_by_pos(ll, pos);
    if (NULL == p) {
        perror("Index is out of range.");
        return ERROR_VAL;
    }
    return p->data;
}

/**
 * @brief 链表查找，返回索引值
 * 
 * @param ll 链表结构体
 * @param elem 值
 * @return index_t 索引 
 */
index_t linklist_find(struct link_list ll, elem_t elem)
{
    struct link_list *p = ll.next;
    index_t cnt = 1;
    while (NULL != p && p->data != elem) {
        p = p->next;
        cnt++;
    }
    if (NULL == p) {
        perror("Element not found.");
        return ERROR_POS;
    }
    return cnt;
}

/**
 * @brief 链表插入元素（节点）
 * 
 * @param ll_ptr 链表结构体指针
 * @param pos 索引
 * @param elem 待插入的值
 */
void linklist_insert(struct link_list *ll_ptr, index_t pos, elem_t elem)
{
    struct link_list *p = ll_ptr;
    index_t cnt = 1;
    while (NULL != p && cnt < pos) {
        p = p->next;
        cnt++;
    }
    if (NULL == p || cnt > pos) {
        perror("Insert element failed.");
        return;
    }
    struct link_list *temp = (struct link_list *)malloc(sizeof(struct link_list));
    if (NULL == temp)
        handle_error("malloc");
    temp->data = elem;
    temp->next = p->next;
    p->next = temp;
    ll_ptr->data += 1;
}

/**
 * @brief 链表删除元素（节点）
 * 
 * @param ll_ptr 链表结构体指针
 * @param pos 索引
 */
void linklist_delete(struct link_list *ll_ptr, index_t pos)
{
    struct link_list *p = ll_ptr;
    index_t cnt = 1;
    while (NULL != p->next && cnt < pos) {
        p = p->next;
        cnt++;
    }
    if (NULL == p->next || cnt > pos) {
        perror("Delete element failed.");
        return;
    }
    struct link_list *temp = p->next;
    p->next = temp->next;
    free(temp);
    temp = NULL;
    ll_ptr->data -= 1;
}

/**
 * @brief 链表替换元素（节点）
 * 
 * @param ll_ptr 链表结构体指针
 * @param pos 索引
 * @param elem 待替换的元素
 */
void linklist_replace(struct link_list *ll_ptr, index_t pos, elem_t elem)
{
    struct link_list *p = get_node_ptr_by_pos(*ll_ptr, pos);
    if (NULL == p) {
        perror("Index is out of range.");
        return;
    }
    p->data = elem;
}

/**
 * @brief 释放整个列表
 * 
 * @param ll_pptr 链表结构体指针的指针
 */
void linklist_clear(struct link_list **ll_pptr)
{
    if (NULL == ll_pptr)
        handle_error("The link_list is been freed.");
    struct link_list *p = (*ll_pptr)->next, *q;
    while (NULL != p) {
        q = p->next;
        free(p);
        p = q;
    }
    p = NULL;
    q = NULL;
    free(*ll_pptr);
    (*ll_pptr) = NULL;      
}


