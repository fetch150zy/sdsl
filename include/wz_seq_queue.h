/**
 * @file wz_seq_queue.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 顺序队列头文件，包含顺序队列的ADT
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef WZ_SEQ_QUEUE_H_
#define WZ_SEQ_QUEUE_H_

#include "wz_seq_queue.h"
#include "wz_seq_list.h"

/* 顺序队列的抽象数据结构 */
struct sq_queue
{
    struct sq_list *sql_ptr;    // 基于顺序表
    index_t front, rear;        // 队首，队尾
};

/* 初始化队列 */
extern struct sq_queue *init_sqqueue(void);
/* 获取队首元素 */
extern elem_t get_sqqueue_front(struct sq_queue sqq);
/* 获取队尾元素 */
extern elem_t get_sqqueue_back(struct sq_queue sqq);
/* 入队 */
extern bool sqqueue_enque(struct sq_queue *sqq_ptr, elem_t elem);
/* 出队 */
extern bool sqqueue_deque(struct sq_queue *sqq_ptr, elem_t *elem_ptr);
/* 清空队列（释放队列） */
extern void sqqueue_clear(struct sq_queue **sqq_pptr);

/**
 * @brief 判断队列是否为空
 * 
 * @param sqq 顺序队列
 * @return true 队列为空
 * @return false 队列非空
 */
static inline bool is_empty_sqqueue(struct sq_queue sqq)
{
    return (sqq.front == sqq.rear);
}

/**
 * @brief 判断队列是否已满
 * 
 * @param sqq 顺序队列
 * @return true 队列已满
 * @return false 队列未满
 */
static inline bool is_full_sqqueue(struct sq_queue sqq)
{
    return ((sqq.rear + 1) % CONTAINER_SIZE == sqq.front);
}

/**
 * @brief 获取队列的长度
 * 
 * @param sqq 顺序队列
 * @return lens_t 队列长度
 */
static inline lens_t get_sqqueue_length(struct sq_queue sqq)
{
    return (sqq.rear - sqq.front + CONTAINER_SIZE) % CONTAINER_SIZE;
}

#endif // WZ_SEQ_QUEUE_H_

