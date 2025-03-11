/**
 * @file seq_stack_test.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 顺序栈测试
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

#ifdef WZ_SEQ_STACK_
#include "wz_seq_stack.h"
#endif

#ifdef WZ_SEQ_STACK_
START_TEST(test_sqstack)
{
    struct sq_stack *sqs_ptr = init_stack();
    ck_assert_int_eq(is_empty_sqstack(*sqs_ptr), true);

    ck_assert_int_eq(sqstack_push(sqs_ptr, 1), 1);
    ck_assert_int_eq(sqstack_push(sqs_ptr, 2), 1);
    ck_assert_int_eq(sqstack_push(sqs_ptr, 3), 1);
    ck_assert_int_eq(sqstack_push(sqs_ptr, 4), 1);

    ck_assert_int_eq(get_sqstack_length(*sqs_ptr), 4);

    ck_assert_int_eq(get_sqstack_top(*sqs_ptr), 4);

    elem_t elem;
    ck_assert_int_eq(sqstack_pop(sqs_ptr, &elem), true);
    ck_assert_int_eq(elem, 4);
    ck_assert_int_eq(sqstack_pop(sqs_ptr, &elem), true);
    ck_assert_int_eq(elem, 3);
    ck_assert_int_eq(sqstack_pop(sqs_ptr, &elem), true);
    ck_assert_int_eq(elem, 2);

    ck_assert_int_eq(get_sqstack_length(*sqs_ptr), 1);

    ck_assert_int_eq(sqstack_pop(sqs_ptr, &elem), true);
    ck_assert_int_eq(elem, 1);

    ck_assert_int_eq(sqstack_pop(sqs_ptr, &elem), false);
    ck_assert_int_eq(elem, ERROR_VAL);

    ck_assert_int_eq(is_empty_sqstack(*sqs_ptr), true);

    for (index_t i = 0; i < CONTAINER_SIZE; i++)
        ck_assert_int_eq(sqstack_push(sqs_ptr, i), true);

    ck_assert_int_eq(sqstack_pop(sqs_ptr, &elem), true);
    ck_assert_int_eq(elem, CONTAINER_SIZE - 1);

    ck_assert_int_eq(sqstack_push(sqs_ptr, 1), true);
    ck_assert_int_eq(sqstack_push(sqs_ptr, 1), false);
    
    sqstack_clear(&sqs_ptr);
    ck_assert_ptr_eq(sqs_ptr, NULL);
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
    #ifdef WZ_SEQ_STACK_
    tcase_add_test(tc_core, test_sqstack);
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

