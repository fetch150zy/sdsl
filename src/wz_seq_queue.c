/**
 * @file wz_seq_queue.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 顺序队列的实现
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "wz_seq_queue.h"
#include "tools.h"

#if __STDC_VERSION__ < 201710L
#error "C version must be C17 or higher"
#endif

/**
 * @brief 初始化顺序队列
 * 
 * @return struct sq_queue* 顺序队列指针
 */
struct sq_queue *init_sqqueue(void)
{
    struct sq_queue *sqq_ptr = (struct sq_queue *)malloc(sizeof(struct sq_queue));
    if (NULL == sqq_ptr)
        handle_error("malloc");
    sqq_ptr->sql_ptr = init_sqlist();
    sqq_ptr->front = 0;
    sqq_ptr->rear = 0;
    return sqq_ptr;
}

/**
 * @brief 获取队首元素
 * 
 * @param sqq 顺序队列
 * @return elem_t 队首元素
 */
elem_t get_sqqueue_front(struct sq_queue sqq)
{
    if (is_empty_sqqueue(sqq)) {
        perror("The sq_queue is empty.");
        return ERROR_VAL;
    }
    return sqlist_at(*sqq.sql_ptr, sqq.front);
}

/**
 * @brief 获取队尾元素
 * 
 * @param sqq 顺序队列
 * @return elem_t 队尾元素
 */
elem_t get_sqqueue_back(struct sq_queue sqq)
{
    if (is_empty_sqqueue(sqq)) {
        perror("The sq_queue is empty.");
        return ERROR_VAL;
    }
    return sqlist_at(*sqq.sql_ptr, sqq.rear - 1);
}

/**
 * @brief 入队
 * 
 * @param sqq_ptr 顺序队列指针
 * @param elem 待入队元素
 */
bool sqqueue_enque(struct sq_queue *sqq_ptr, elem_t elem)
{
    if (is_full_sqqueue(*sqq_ptr)) {
        perror("The sequence queue is full.");
        return false;
    }
    sqlist_insert(sqq_ptr->sql_ptr, sqq_ptr->rear, elem);
    sqq_ptr->rear = (sqq_ptr->rear + 1) % CONTAINER_SIZE;

    return true;
}

/**
 * @brief 出队
 * 
 * @param sqq_ptr 顺序队列指针
 * @return elem_t 待出队元素
 */
bool sqqueue_deque(struct sq_queue *sqq_ptr, elem_t *elem_ptr)
{
    if (is_empty_sqqueue(*sqq_ptr)) {
        perror("The sequence queue is empty.");
        *elem_ptr = ERROR_VAL;
        return false;
    }
    *elem_ptr = sqlist_at(*sqq_ptr->sql_ptr, sqq_ptr->front);
    sqq_ptr->front = (sqq_ptr->front + 1) % CONTAINER_SIZE;

    return true;
}

/**
 * @brief 清空队列（释放队列）
 * 
 * @param sqq_pptr 顺序队列指针的指针
 */
void sqqueue_clear(struct sq_queue **sqq_pptr)
{
    if (NULL == *sqq_pptr)
        handle_error("The sq_queue is been freed.");
    sqlist_clear(&((*sqq_pptr)->sql_ptr));
    free(*sqq_pptr);
    (*sqq_pptr) = NULL;
}