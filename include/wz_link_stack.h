/**
 * @file wz_link_stack.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 链式栈头文件，包含链式栈的定义和函数声明
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef WZ_LINK_STACK_
#define WZ_LINK_STACK_

#include "wz_link_stack.h"
#include "wz_link_list.h"

struct link_stack
{
    struct link_list *top;
};

/* 初始化链栈 */
extern struct link_stack *init_linkstack(void);
/* 获取栈顶元素 */
extern elem_t get_linkstack_top(struct link_stack ls);
/* 入栈 */
extern void linkstack_push(struct link_stack *ls_ptr, elem_t elem);
/* 出栈 */
extern elem_t linkstack_pop(struct link_stack *ls_ptr);
/* 清空栈（释放栈） */
extern void linkstack_clear(struct link_stack **ls_pptr);

/**
 * @brief 判断链栈是否为空
 * 
 * @param ls 链栈
 * @return true 栈空
 * @return false 栈非空
 */
static inline bool is_empty_linkstack(struct link_stack ls)
{
    // return is_empty_linklist(*ls.top);
    return (NULL == ls.top->next);
}

#endif // WZ_LINK_STACK_

