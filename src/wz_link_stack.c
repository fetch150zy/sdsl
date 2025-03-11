/**
 * @file wz_link_stack.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 链式栈
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "wz_link_stack.h"
#include "tools.h"

#include <stdlib.h>

#if __STDC_VERSION__ < 201710L
#error "C version must be C17 or higher"
#endif

/**
 * @brief 初始化链式栈
 * 
 * @return struct link_stack* 链式栈结构体指针
 */
struct link_stack *init_linkstack(void)
{
    struct link_stack *ls_ptr = (struct link_stack *)malloc(sizeof(struct link_stack));
    if (NULL == ls_ptr)
        handle_error("malloc");
    ls_ptr->top = init_linklist();

    return ls_ptr;
}

/**
 * @brief 获取链式栈的栈顶元素
 * 
 * @param ls 链式栈
 * @return elem_t 栈顶元素
 */
elem_t get_linkstack_top(struct link_stack ls)
{
    if (is_empty_linkstack(ls)) {
        perror("The link_stack is empty.");
        return ERROR_VAL;
    }
    return ls.top->data;
}

/**
 * @brief 入栈
 * 
 * @param ls_ptr 链式栈指针
 * @param elem 入栈元素
 */
void linkstack_push(struct link_stack *ls_ptr, elem_t elem)
{
    struct link_list *ll_ptr = (struct link_list *)malloc(sizeof(struct link_list));
    if (NULL == ll_ptr)
        handle_error("malloc");
    ll_ptr->data = elem;
    ll_ptr->next = ls_ptr->top;
    ls_ptr->top = ll_ptr;
}

/**
 * @brief 出栈
 * 
 * @param ls_ptr 链式栈指针
 * @return elem_t 出栈元素
 */
elem_t linkstack_pop(struct link_stack *ls_ptr)
{
    if (is_empty_linkstack(*ls_ptr)) {
        perror("The link_stack is empty.");
        return ERROR_VAL;
    }
    struct link_list *ll_ptr = ls_ptr->top;
    elem_t elem = ll_ptr->data;
    ls_ptr->top = ls_ptr->top->next;
    free(ll_ptr);

    return elem;
}

/**
 * @brief 释放链式栈
 * 
 * @param ls_pptr 链式栈的指针的指针
 */
void linkstack_clear(struct link_stack **ls_pptr)
{
    if (NULL == *ls_pptr)
        handle_error("The link_stack is been freed.");
    
    linklist_clear(&(*ls_pptr)->top);
    
    free(*ls_pptr);
    (*ls_pptr) = NULL;
}