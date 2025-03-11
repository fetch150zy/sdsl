/**
 * @file link_stack_test.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 测试链式栈
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <check.h>
#include <stdlib.h>

#if __STDC_VERSION__ < 201710L
#error "C version must be C17 or higher"
#endif

#ifdef WZ_LINK_STACK_
#include "wz_link_stack.h"
#endif

#ifdef WZ_LINK_STACK_
START_TEST(test_linkstack)
{
    struct link_stack *ls_ptr = init_linkstack();
    ck_assert_int_eq(is_empty_linkstack(*ls_ptr), true);

    linkstack_push(ls_ptr, 1);
    linkstack_push(ls_ptr, 2);
    linkstack_push(ls_ptr, 3);
    linkstack_push(ls_ptr, 4);

    ck_assert_int_eq(get_linkstack_top(*ls_ptr), 4);

    ck_assert_int_eq(linkstack_pop(ls_ptr), 4);
    ck_assert_int_eq(linkstack_pop(ls_ptr), 3);
    ck_assert_int_eq(linkstack_pop(ls_ptr), 2);
    ck_assert_int_eq(linkstack_pop(ls_ptr), 1);

    ck_assert_int_eq(linkstack_pop(ls_ptr), ERROR_VAL);

    linkstack_push(ls_ptr, 1);

    ck_assert_int_eq(linkstack_pop(ls_ptr), 1);

    ck_assert_int_eq(linkstack_pop(ls_ptr), ERROR_VAL);

    ck_assert_int_eq(is_empty_linkstack(*ls_ptr), true);
    linkstack_clear(&ls_ptr);
    ck_assert_ptr_eq(ls_ptr, NULL);
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
    #ifdef WZ_LINK_STACK_
    tcase_add_test(tc_core, test_linkstack);
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
