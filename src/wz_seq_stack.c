/**
 * @file wz_seq_stack.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 顺序栈
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "wz_seq_stack.h"
#include "tools.h"

#include <stdlib.h>

#if __STDC_VERSION__ < 201710L
#error "C version must be C17 or higher"
#endif

/**
 * @brief 初始化顺序栈
 * 
 * @return struct sq_stack* 顺序栈指针
 */
struct sq_stack *init_stack(void)
{
    struct sq_stack *sqs_ptr = (struct sq_stack *)malloc(sizeof(struct sq_stack));
    if (NULL == sqs_ptr)
        handle_error("malloc");
    sqs_ptr->sql_ptr = init_sqlist();

    sqs_ptr->top = -1;
    return sqs_ptr;
}

/**
 * @brief 获取栈顶元素
 * 
 * @param sqs 顺序栈
 * @param stack_num 栈编号
 * @return elem_t 栈中元素
 */
elem_t get_sqstack_top(struct sq_stack sqs)
{
    if (is_empty_sqstack(sqs)) {
        perror("The sq_stack is empty.");
        return ERROR_VAL;
    }
    return sqlist_at(*sqs.sql_ptr, sqs.top);
}

/**
 * @brief 入栈
 * 
 * @param sqs_ptr 顺序栈指针
 * @param elem 待入栈元素
 */
bool sqstack_push(struct sq_stack *sqs_ptr, elem_t elem)
{
    if (is_full_sqstack(*sqs_ptr)) {
        perror("The sq_stack is full.");
        return false;
    }
    return sqlist_insert(sqs_ptr->sql_ptr, ++sqs_ptr->top, elem);
}

/**
 * @brief 出栈
 * 
 * @param sqs_ptr 顺序栈指针
 * @return elem_t 出栈元素
 */
bool sqstack_pop(struct sq_stack *sqs_ptr, elem_t *elem_ptr)
{
    if (is_empty_sqstack(*sqs_ptr)) {
        perror("The sq_stack is empty.");
        *elem_ptr = ERROR_VAL;
        return false;
    }
    return sqlist_delete(sqs_ptr->sql_ptr, sqs_ptr->top--, elem_ptr);
}

/**
 * @brief 清空栈（释放栈）
 * 
 * @param sqs_pptr 顺序栈指针的指针
 */
void sqstack_clear(struct sq_stack **sqs_pptr)
{
    if (NULL == *sqs_pptr)
        handle_error("The sq_stack is been freed.");
    sqlist_clear(&((*sqs_pptr)->sql_ptr));
    free(*sqs_pptr);
    (*sqs_pptr) = NULL;
}
