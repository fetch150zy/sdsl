/**
 * @file link_queue.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement basic data structures link queue
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "../include/link_queue.h"



#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



extern int errno;

static inline bool is_empty_queue(struct linkQue LQ);
static inline void check_error(const void *ptr);



static inline void check_error(const void *ptr)
{
        if (NULL == ptr) {
                fprintf(stderr, "Cause by malloc : %s\n", strerror(errno));
                assert(0);
        }
        return;
}



static inline bool is_empty_queue(struct linkQue LQ)
{
        return (LQ.rear == LQ.front);
}



struct linkQue *init_queue(void)
{
        struct linkQue *LQP = malloc(sizeof(struct linkQue));
        check_error(LQP);
        struct node *nd = malloc(sizeof(struct node));
        check_error(nd);
        nd->next = NULL;
        nd->data = 0;
        LQP->rear = nd;
        LQP->front = nd;
        return LQP;
}



size_t get_queue_length(struct linkQue LQ)
{
        return LQ.front->data;
}



elemType get_front_elem(struct linkQue LQ)
{
        return (LQ.front->next->data);
}



elemType get_back_elem(struct linkQue LQ)
{ 
        return (LQ.rear->data);
}



bool enque(struct linkQue *LQP, elemType elem)
{
        struct node *nd = malloc(sizeof(struct node));
        check_error(nd);
        nd->data = elem;
        nd->next = NULL;
        LQP->rear->next = nd;
        LQP->rear = nd;
        LQP->front->data++;
        return true;
}



bool deque(struct linkQue *LQP, elemType *elem)
{
        if (is_empty_queue(*LQP)) {
                puts("*** The link queue is empty, you can't delete anymore.");
                goto err;
        }

        struct node *temp = LQP->front->next;
        *elem = temp->data;
        LQP->front->next = temp->next;
        if (LQP->rear == temp)
                LQP->rear = LQP->front;
        free(temp);
        temp = NULL;
        LQP->front->data--;
        goto exit_safely;

exit_safely:
        return true;
err:
        return false;
}



void clear_queue(struct linkQue **LQPP)
{
        if (NULL == *LQPP) {
                puts("*** It has been free.");
                return;
        }
        struct node *temp = (*LQPP)->front->next, *p;
        while (NULL != temp) {
                p = temp->next;
                free(temp);
                temp = p;
        }
        temp = NULL, p = NULL;
        (*LQPP) = NULL;
        return;
}