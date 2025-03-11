/**
 * @file link_list_test.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 单向链表测试
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <check.h>
#include <stdlib.h>

#if __STDC_VERSION__ < 201710L
#error "C version must be C17 or higher"
#endif

#ifdef WZ_LINK_LIST_
#include "wz_link_list.h"
#endif

#ifdef WZ_LINK_LIST_
START_TEST(test_linklist)
{
    struct link_list *ll_ptr = init_linklist();
    ck_assert_int_eq(is_empty_linklist(*ll_ptr), true);
    ck_assert_int_eq(get_linklist_length(*ll_ptr), 0);

    linklist_insert(ll_ptr, 1, 1);
    linklist_insert(ll_ptr, 2, 2);
    linklist_insert(ll_ptr, 3, 3);
    linklist_insert(ll_ptr, 4, 4);

    ck_assert_int_eq(linklist_at(*ll_ptr, 1), 1);
    ck_assert_int_eq(linklist_at(*ll_ptr, 2), 2);
    ck_assert_int_eq(linklist_at(*ll_ptr, 3), 3);
    ck_assert_int_eq(linklist_at(*ll_ptr, 4), 4);
    ck_assert_int_eq(linklist_at(*ll_ptr, 5), ERROR_VAL);

    ck_assert_int_eq(get_linklist_length(*ll_ptr), 4);

    linklist_insert(ll_ptr, 1, 5);

    ck_assert_int_eq(linklist_at(*ll_ptr, 1), 5);

    ck_assert_int_eq(linklist_find(*ll_ptr, 1), 2);
    ck_assert_int_eq(linklist_find(*ll_ptr, 2), 3);
    ck_assert_int_eq(linklist_find(*ll_ptr, 3), 4);
    ck_assert_int_eq(linklist_find(*ll_ptr, 4), 5);
    ck_assert_int_eq(linklist_find(*ll_ptr, 6), ERROR_POS);

    ck_assert_int_eq(get_linklist_length(*ll_ptr), 5);

    linklist_delete(ll_ptr, 1);
    linklist_delete(ll_ptr, 3);

    linklist_insert(ll_ptr, 0, 5);

    ck_assert_int_eq(linklist_at(*ll_ptr, 1), 1);
    ck_assert_int_eq(linklist_at(*ll_ptr, 2), 2);
    ck_assert_int_eq(linklist_at(*ll_ptr, 3), 4);
    ck_assert_int_eq(linklist_at(*ll_ptr, 4), ERROR_VAL);

    linklist_replace(ll_ptr, 2, 6);
    ck_assert_int_eq(linklist_at(*ll_ptr, 2), 6);

    ck_assert_int_eq(get_linklist_length(*ll_ptr), 3);

    linklist_clear(&ll_ptr);
    ck_assert_ptr_eq(ll_ptr, NULL);
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
    #ifdef WZ_LINK_LIST_
    tcase_add_test(tc_core, test_linklist);
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