/**
 * @file seq_list_test.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 顺序表测试
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <check.h>
#include <stdlib.h>

#if __STDC_VERSION__ < 201710L
#error "C version must be C17 or higher"
#endif

#ifdef WZ_SEQ_LIST_
#include "wz_seq_list.h"
#endif

#ifdef WZ_SEQ_LIST_
START_TEST(test_sqlist)
{
    /* 测试创建顺序存储线性表 */
    struct sq_list *sql_ptr = init_sqlist();
    ck_assert_int_eq(is_empty_sqlist(*sql_ptr), true);
    for (index_t i = 0; i < CONTAINER_SIZE; i++)
        ck_assert_int_eq(sql_ptr->elems[i], 0);

    /* 测试插入元素 */
    ck_assert_int_eq(sqlist_insert(sql_ptr, 0, 1), true);
    ck_assert_int_eq(sqlist_insert(sql_ptr, 1, 3), true);
    ck_assert_int_eq(sqlist_insert(sql_ptr, 1, 2), true);
    ck_assert_int_eq(sqlist_insert(sql_ptr, 3, 4), true);

    /* 测试插入是否成功 */
    ck_assert_int_eq(sqlist_at(*sql_ptr, 0), 1);
    ck_assert_int_eq(sqlist_at(*sql_ptr, 1), 2);
    ck_assert_int_eq(sqlist_at(*sql_ptr, 2), 3);
    ck_assert_int_eq(sqlist_at(*sql_ptr, 3), 4);
    ck_assert_int_eq(sqlist_at(*sql_ptr, 4), ERROR_VAL);

    ck_assert_int_eq(get_sqlist_length(*sql_ptr), 4);

    ck_assert_int_eq(sqlist_insert(sql_ptr, 0, 5), true);

    ck_assert_int_eq(sqlist_at(*sql_ptr, 0), 5);

    /* 测试查找元素 */
    ck_assert_int_eq(sqlist_find(*sql_ptr, 1), 1);
    ck_assert_int_eq(sqlist_find(*sql_ptr, 2), 2);
    ck_assert_int_eq(sqlist_find(*sql_ptr, 3), 3);
    ck_assert_int_eq(sqlist_find(*sql_ptr, 4), 4);
    ck_assert_int_eq(sqlist_find(*sql_ptr, 6), ERROR_POS);

    ck_assert_int_eq(get_sqlist_length(*sql_ptr), 5);

    /* 测试删除元素 */
    elem_t elem;
    ck_assert_int_eq(sqlist_delete(sql_ptr, 0, &elem), true);
    ck_assert_int_eq(elem, 5);
    ck_assert_int_eq(sqlist_delete(sql_ptr, 2, &elem), true);

    ck_assert_int_eq(sqlist_insert(sql_ptr, -1, 5), false);

    ck_assert_int_eq(sqlist_at(*sql_ptr, 0), 1);
    ck_assert_int_eq(sqlist_at(*sql_ptr, 1), 2);
    ck_assert_int_eq(sqlist_at(*sql_ptr, 2), 4);

    ck_assert_int_eq(get_sqlist_length(*sql_ptr), 3);

    ck_assert_int_eq(sqlist_delete(sql_ptr, 10, &elem), false);

    ck_assert_int_eq(sqlist_replace(sql_ptr, 0, 3), true);
    ck_assert_int_eq(sqlist_replace(sql_ptr, 2, 1), true);
    ck_assert_int_eq(sqlist_replace(sql_ptr, -1, 1), false);

    ck_assert_int_eq(sqlist_at(*sql_ptr, 0), 3);
    ck_assert_int_eq(sqlist_at(*sql_ptr, 1), 2);
    ck_assert_int_eq(sqlist_at(*sql_ptr, 2), 1);

    ck_assert_int_eq(get_sqlist_length(*sql_ptr), 3);

    ck_assert_int_eq(sqlist_delete(sql_ptr, 2, &elem), true);
    ck_assert_int_eq(sqlist_delete(sql_ptr, 1, &elem), true);
    ck_assert_int_eq(sqlist_delete(sql_ptr, 0, &elem), true);
    ck_assert_int_eq(sqlist_delete(sql_ptr, 0, &elem), false);

    /* 测试越界情况 */
    for (index_t i = 0; i < CONTAINER_SIZE; i++)
        ck_assert_int_eq(sqlist_insert(sql_ptr, i, i), true);
    
    ck_assert_int_eq(sqlist_insert(sql_ptr, 0, 5), false);
    
    sqlist_clear(&sql_ptr);
    ck_assert_ptr_eq(sql_ptr, NULL);
}
END_TEST
#endif

Suite *test_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Test");

    /* Core test case */
    tc_core = tcase_create("Core");
    #ifdef WZ_SEQ_LIST_
    tcase_add_test(tc_core, test_sqlist);
    #endif
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = test_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

