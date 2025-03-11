/**
 * @file string.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement the basic data structure string
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "../include/string.h"



static inline void get_next(struct string t, int *next);



int bf_match(struct string s, struct string t)
{
        int i, j, m = s.length, n = t.length;
        for (i = 0; i < m - n + 1; ++i) {
                for (j = 0; j < n; ++j)
                        if (s.str[i + j] != t.str[j])
                                break;
                if (j == n)
                        return i;
        }
        return -1;
}



static inline void get_next(struct string t, int *next)
{
        int i = 0, j = 0;
        next[0] = 0;
        while (i < t.length - 1) {
                if (0 == j || t.str[i] == t.str[j]) {
                        ++i;
                        ++j;
                        if (t.str[i] != t.str[j])
                                next[i] = j;
                        else
                                next[i] = next[j];
                } else {
                        j = next[j];
                }
        }
}



#define NEXT_ARR_SZIE 256

int kmp(struct string s, struct string t, int pos)
{
        int i = pos - 1, j = 0;
        int next[NEXT_ARR_SZIE] = {0};
        get_next(t, next);
        while (i < s.length && j < t.length) {
                if (0 == j || s.str[i] == t.str[j]) {
                        ++i;
                        ++j;
                } else {
                        j = next[j];
                }
        }
        return (j >= t.length ? i - t.length : -1);
}