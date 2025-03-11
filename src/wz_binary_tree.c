/**
 * @file binary_tree.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement basic data structures binary tree
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "../include/binary_tree.h"



#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


static size_t bitree_nodes = 0;

extern int errno;

static inline void check_err(void *ptr);



static inline void check_err(void *ptr)
{
        if (NULL == ptr) {
                fprintf(stderr, "Cause by malloc : %s\n", strerror(errno));
                assert(0);
        }
        return;
}



size_t get_bitree_nodes(void)
{
        return bitree_nodes;
}



void init_tree(struct biNode **treep, FILE *fp)
{
        elemType elem = getc(fp);
        if ('#' == elem) {
                (*treep) = NULL;
        } else {
                (*treep) = malloc(sizeof(struct biNode));
                check_err(*treep);
                (*treep)->data = elem;
                bitree_nodes++;
                init_tree(&((*treep)->lchild), fp);
                init_tree(&((*treep)->rchild), fp);
        }
}



void pre_order_traverse(struct biNode *tree)
{
        if (NULL == tree)
                return;
        printf("%c ", tree->data);
        pre_order_traverse(tree->lchild);
        pre_order_traverse(tree->rchild);
        return;
}



void in_order_traverse(struct biNode *tree)
{
        if (NULL == tree)
                return;
        in_order_traverse(tree->lchild);
        printf("%c ", tree->data);
        in_order_traverse(tree->rchild);
        return;
}



void post_order_traverse(struct biNode *tree)
{
        if (NULL == tree)
                return;
        post_order_traverse(tree->lchild);
        post_order_traverse(tree->rchild);
        printf("%c ", tree->data);
        return;
}



size_t get_bitree_depth(struct biNode *tree) {
        if (NULL == tree) {
                return 0;
        } else {
                size_t left = get_bitree_depth(tree->lchild);
                size_t right = get_bitree_depth(tree->rchild);
                if (left > right)
                        return (left + 1);
                else
                        return (right + 1);
        }
}



void clear_tree(struct biNode **treep)
{
        if (NULL == (*treep))
                return;
        if (NULL != (*treep)->lchild)
                clear_tree(&(*treep)->lchild);
        if (NULL != (*treep)->rchild)
                clear_tree(&(*treep)->rchild);
        if (NULL == (*treep)->lchild && NULL == (*treep)->rchild) {
                bitree_nodes--;
                free(*treep);
                (*treep) = NULL;
                return;
        }
}