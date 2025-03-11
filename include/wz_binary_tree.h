/**
 * @file binary_tree.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file of binary tree
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef BINARY_TREE_
#define BINARY_TREE_


#include "binary_tree.h"


#include <stdio.h>
#include <stdbool.h>


typedef char elemType;
/* ADT of binary tree */
struct biNode {
        elemType data;
        struct biNode *lchild, *rchild;
};


extern void init_tree(struct biNode **treep, FILE* fp);
extern size_t get_bitree_nodes(void);
extern void pre_order_traverse(struct biNode *tree);
extern void in_order_traverse(struct biNode *tree);
extern void post_order_traverse(struct biNode *tree);
extern size_t get_bitree_depth(struct biNode *tree);
extern void clear_tree(struct biNode **treep);


#endif

