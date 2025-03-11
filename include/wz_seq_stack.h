/**
 * @file wz_seq_stack.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 顺序栈的头文件，包含了顺序栈的结构体定义，以及顺序栈的基本操作
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef WZ_SEQ_STACK_H_
#define WZ_SEQ_STACK_H_

#include "wz_seq_stack.h"
#include "wz_seq_list.h"

/* 顺序栈的抽象数据结构 */
struct sq_stack
{
    struct sq_list *sql_ptr;    // 基于顺序表
    index_t top;                // 栈顶
};

/* 初始化顺序栈 */
extern struct sq_stack *init_stack(void);
/* 获取栈顶元素 */
extern elem_t get_sqstack_top(struct sq_stack sqs);
/* 入栈 */
extern bool sqstack_push(struct sq_stack *sqs_ptr, elem_t elem);
/* 出栈 */
extern bool sqstack_pop(struct sq_stack *sqs_ptr, elem_t *elem_ptr);
/* 清空栈（释放栈） */
extern void sqstack_clear(struct sq_stack **sqs_pptr);

/**
 * @brief 判断栈是否为空
 * 
 * @param sqs 顺序栈
 * @return true 栈空
 * @return false 栈非空
 */
static inline bool is_empty_sqstack(struct sq_stack sqs)
{
    // return is_empty_sqlist(*sqs.sql_ptr);
    return (-1 == sqs.top);
}

/**
 * @brief 判断栈是否已满
 * 
 * @param sqs 顺序栈
 * @return true 栈满
 * @return false 栈未满
 */
static inline bool is_full_sqstack(struct sq_stack sqs)
{
    return (sqs.top == CONTAINER_SIZE - 1);
}

/**
 * @brief 获取栈中元素个数
 * 
 * @param sqs 顺序栈
 * @return lens_t 个数
 */
static inline lens_t get_sqstack_length(struct sq_stack sqs)
{
    return sqs.top + 1;
}

#endif // WZ_SEQ_STACK_H_
