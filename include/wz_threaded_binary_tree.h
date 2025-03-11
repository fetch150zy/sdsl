/**
 * @file threaded_binary_tree.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file of threaded binary tree
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef THREADED_BINARY_H_
#define THREADED_BINARY_H_


#include "threaded_binary_tree.h"


#include <stdio.h>
#include <stdbool.h>


typedef char elemType;
/* ADT of threaded binary tree */
struct tbNode {
        elemType data;
        struct tbNode *llink;
        struct tbNode *rlink;
};





#endif

