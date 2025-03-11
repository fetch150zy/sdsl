/**
 * @file string.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file of string
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef STRING_H_
#define STRING_H_


#include "string.h"


#include <stdio.h>
#include <stdlib.h>


struct string {
        char *str;
        int length;
};


extern int bf_match(struct string s, struct string t);
extern int kmp(struct string s, struct string t, int pos);


#endif

