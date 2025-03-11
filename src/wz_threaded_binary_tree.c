/**
 * @file threaded_binary_tree.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement basic data structures threaded binary tree
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */




#include "../include/threaded_binary_tree.h"



#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



extern int errno;

static inline struct tbNode* create_node(elemType data);



static inline struct tbNode* create_node(elemType data)
{
        struct tbNode *ptr = malloc(sizeof(struct tbNode));
        ptr->rlink = ptr->llink = NULL;
        ptr->data = data;
        return ptr;
}



void pre_order_traverse(struct tbNode *tree)
{
        if (NULL == tree)
                return;
        printf("%c ", tree->data);
        pre_order_traverse(tree->llink);
        pre_order_traverse(tree->rlink);
        return;
}



void in_order_traverse(struct tbNode *tree)
{
        if (NULL == tree)
                return;
        in_order_traverse(tree->llink);
        printf("%c ", tree->data);
        in_order_traverse(tree->rlink);
        return;
}



void post_order_traverse(struct tbNode *tree)
{
        if (NULL == tree)
                return;
        post_order_traverse(tree->llink);
        post_order_traverse(tree->rlink);
        printf("%c ", tree->data);
        return;
}



void insert_bt(struct tbNode **root, int data)
{
        struct tbNode *new_node = create_node(data);
        struct tbNode *temp, *prev;
        if (*root == NULL) {
                *root = new_node;
        } else {
                temp = *root;
                prev = NULL;
                while (temp != NULL) {
                        if (new_node->data > temp->data) {
                                prev = temp;
                                temp = temp->rlink;
                        } else if (new_node->data < temp->data) {
                                prev = temp;
                                temp = temp->llink;
                        } else {
                                return;
                        }
                }

                if (new_node->data > prev->data)
                        prev->rlink = new_node;
                else
                        prev->llink = new_node;
        }
}



void search(struct tbNode *root, int ele)
{
        struct tbNode *temp = root;
        while (NULL != temp) {
                if (temp->data == ele)
                        break;
                else if (ele > temp->data)
                        temp = temp->rlink;
                else
                        temp = temp->llink;
        }

        if (NULL == temp)
                printf("%s\n", "Element not found.");
        else
                printf("%s\n", "Element found.");
}



void delete_bt(struct tbNode **root, int ele)
{
        struct tbNode *temp, *prev;
        if (NULL == *root) {
                return;
        } else {
                temp = *root;
                prev = NULL;
                while (NULL != temp) {
                        if (temp->data == ele) {
                                break;
                        } else if (ele > temp->data) {
                                prev = temp;
                                temp = temp->rlink;
                        } else {
                                prev = temp;
                                temp = temp->llink;
                        }
                }
        }

        if (NULL == temp) {
                return;
        } else {
                struct tbNode *replacement, *t;
                if (temp->llink == NULL && temp->rlink == NULL) {
                        replacement = NULL;
                } else if (temp->llink == NULL && temp->rlink != NULL) {
                        replacement = temp->rlink;
                } else if (temp->llink != NULL && temp->rlink == NULL) {
                        replacement = temp->llink;
                } else {
                        replacement = temp->rlink;
                        t = replacement;
                        while (t->llink != NULL)
                                t = t->llink;
                        t->llink = temp->llink; 
                }

                if (temp == *root) {
                        free(*root);
                        *root = replacement;
                } else if (prev->llink == temp) {
                        free(prev->llink);
                        prev->llink = replacement;
                } else if (prev->rlink == temp) {
                        free(prev->rlink);
                        prev->rlink = replacement;
                }
        }
}