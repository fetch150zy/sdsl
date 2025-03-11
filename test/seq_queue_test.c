/**
 * @file seq_queue_test.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 测试顺序队列
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

#ifdef WZ_SEQ_QUEUE_
#include "wz_seq_queue.h"
#endif

#ifdef WZ_SEQ_QUEUE_
START_TEST(test_sqqueue)
{
    struct sq_queue *sqq_ptr = init_sqqueue();
    ck_assert_int_eq(is_empty_sqqueue(*sqq_ptr), true);

    ck_assert_int_eq(sqqueue_enque(sqq_ptr, 1), true);
    ck_assert_int_eq(sqqueue_enque(sqq_ptr, 2), true);
    ck_assert_int_eq(sqqueue_enque(sqq_ptr, 3), true);
    ck_assert_int_eq(sqqueue_enque(sqq_ptr, 4), true);

    ck_assert_int_eq(sqq_ptr->sql_ptr->elems[0], 1);
    ck_assert_int_eq(sqq_ptr->sql_ptr->elems[1], 2);
    ck_assert_int_eq(sqq_ptr->sql_ptr->elems[2], 3);
    ck_assert_int_eq(sqq_ptr->sql_ptr->elems[3], 4);

    ck_assert_int_eq(get_sqqueue_length(*sqq_ptr), 4);

    ck_assert_int_eq(sqq_ptr->front, 0);
    ck_assert_int_eq(sqq_ptr->rear, 4);

    ck_assert_int_eq(get_sqqueue_front(*sqq_ptr), 1);
    ck_assert_int_eq(get_sqqueue_back(*sqq_ptr), 4);


    elem_t elem;
    ck_assert_int_eq(sqqueue_deque(sqq_ptr, &elem), true);
    ck_assert_int_eq(elem, 1);

    ck_assert_int_eq(sqq_ptr->front, 1);
    ck_assert_int_eq(sqq_ptr->rear, 4);

    ck_assert_int_eq(get_sqqueue_front(*sqq_ptr), 2);
    ck_assert_int_eq(get_sqqueue_back(*sqq_ptr), 4);
    
    ck_assert_int_eq(sqqueue_deque(sqq_ptr, &elem), true);
    ck_assert_int_eq(elem, 2);
    ck_assert_int_eq(sqqueue_deque(sqq_ptr, &elem), true);
    ck_assert_int_eq(elem, 3);

    ck_assert_int_eq(sqq_ptr->front, 3);
    ck_assert_int_eq(sqq_ptr->rear, 4);

    ck_assert_int_eq(sqqueue_deque(sqq_ptr, &elem), true);
    ck_assert_int_eq(elem, 4);

    ck_assert_int_eq(is_empty_sqqueue(*sqq_ptr), true);

    ck_assert_int_eq(sqqueue_deque(sqq_ptr, &elem), false);
    ck_assert_int_eq(elem, ERROR_VAL);

    ck_assert_int_eq(sqqueue_enque(sqq_ptr, 1), true);

    ck_assert_int_eq(sqq_ptr->front, 4);
    ck_assert_int_eq(sqq_ptr->rear, 5);

    ck_assert_int_eq(sqqueue_deque(sqq_ptr, &elem), true);
    ck_assert_int_eq(elem, 1);

    ck_assert_int_eq(sqqueue_deque(sqq_ptr, &elem), false);
    ck_assert_int_eq(elem, ERROR_VAL);

    ck_assert_int_eq(is_empty_sqqueue(*sqq_ptr), true);

    for (index_t i = 0; i < CONTAINER_SIZE - 1; i++)
        ck_assert_int_eq(sqqueue_enque(sqq_ptr, i), true);

    ck_assert_int_eq(sqqueue_enque(sqq_ptr, 1), false);

    sqqueue_clear(&sqq_ptr);
    ck_assert_ptr_eq(sqq_ptr, NULL);
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
    #ifdef WZ_SEQ_QUEUE_
    tcase_add_test(tc_core, test_sqqueue);
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
