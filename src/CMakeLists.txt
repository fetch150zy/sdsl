add_library(data_structure STATIC empty.c)

target_include_directories(data_structure
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include         # *.h
        ${CMAKE_SOURCE_DIR}                 # tools.h alias.h
    )

function(op_link op_macro c_macro src)
    if(${op_macro})
        target_compile_definitions(data_structure INTERFACE ${c_macro})
        target_sources(data_structure INTERFACE ${src})
    endif(${op_macro})
endfunction(op_link)


set(macro_list
    "WZ_SEQ_LIST_"
    "WZ_LINK_LIST_"
    "WZ_SEQ_STACK_"
    "WZ_LINK_STACK_"
    "WZ_SEQ_QUEUE_"
    "WZ_LINK_QUEUE_"
    "WZ_STRING_"
    "WZ_BIN_TREE_"
    "WZ_TH_BIN_TREE_"
)
set(src_list
    "wz_seq_list.c"             # 顺序线性表
    "wz_link_list.c"            # 链式线性表
    "wz_seq_stack.c"            # 顺序栈
    "wz_link_stack.c"           # 链式栈
    "wz_seq_queue.c"            # 顺序队列
    "wz_link_queue.c"           # 链式队列
    "wz_string.c"               # 字符串
    "wz_binary_tree.c"          # 二叉树
    "wz_threaded_binary_tree.c" # 线索二叉树
)

foreach(item IN ZIP_LISTS op_list macro_list src_list)
    op_link(${item_0} ${item_1} ${item_2})
endforeach(item)




# 处理与平台有关的代码
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(data_structure PRIVATE "IS_LINUX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(data_structure PRIVATE "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(data_structure PRIVATE "IS_WINDOWS")
endif()

# 处理与编译器有关的源代码
target_compile_definitions(data_structure PRIVATE "COMPILER_NAME=${CMAKE_C_COMPILER_ID}")

if(CMAKE_C_COMPILER_ID MATCHES Intel)
    target_compile_definitions(data_structure PRIVATE "IS_INTEL_C_COMPILER")
endif()
if(CMAKE_C_COMPILER_ID MATCHES GNU)
    target_compile_definitions(data_structure PRIVATE "IS_GNU_C_COMPILER")
endif()
if(CMAKE_C_COMPILER_ID MATCHES MSVC)
    target_compile_definitions(data_structure PRIVATE "IS_MINCROSOFT_C_COMPILER")
endif()


# 检测处理器架构体系
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_compile_definitions(data_structure PRIVATE "IS_64_BIT_ARCH")
    message(STATUS "Target is 64 bits")
else()
    target_compile_definitions(data_structure PRIVATE "IS_32_BIT_ARCH")
    message(STATUS "Target is 32 bits")
endif()

# 安装相关
install(TARGETS data_structure
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )

install(FILES ${CMAKE_SOURCE_DIR}/include/wz_list.h DESTINATION include)