find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

enable_testing()

function(op_test op_macro check_test)
    if(${op_macro})
        add_executable(${check_test} ${check_test}.c)
        target_link_libraries(${check_test} data_structure ${CHECK_LIBRARIES})
        # 普通测试
        add_test(NAME ${check_test} COMMAND ${check_test})
        # 超时测试
        add_test(
            NAME timeout_${check_test}
            COMMAND ${check_test}
        )
        set_tests_properties(timeout_${check_test} PROPERTIES TIMEOUT 1)
    endif(${op_macro})
endfunction(op_test)

set(check_list
    seq_list_test
    link_list_test
    seq_stack_test
    link_stack_test
    seq_queue_test
    link_queue_test
    string_test
    binary_tree_test
    threaded_binary_tree_test
)

foreach(item IN ZIP_LISTS op_list check_list)
    op_test(${item_0} ${item_1})
endforeach(item)

find_program(MEMORYCHECK_COMMAND NAMES valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")
