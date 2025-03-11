/**
 * @file link_queue.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file of link queue
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef LINK_QUEUE_H_
#define LINK_QUEUE_H_


#include "link_queue.h"


#include <stdio.h>
#include <stdbool.h>


typedef int elemType;
/* ADT of link queue */
struct node {
        elemType data;
        struct node *next;      
};

struct linkQue {
        struct node *front;
        struct node *rear;
};


extern struct linkQue *init_queue(void);
extern size_t get_queue_length(struct linkQue LQ);
extern elemType get_front_elem(struct linkQue LQ);
extern elemType get_back_elem(struct linkQue LQ);
extern bool enque(struct linkQue *LQP, elemType elem);
extern bool deque(struct linkQue *LQP, elemType *elem);
extern void clear_queue(struct linkQue **LQPP);


#endif

