cmake_minimum_required(VERSION 3.10)

project(test-c-call-cpp LANGUAGES C)
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)


# include_directories(
#     ${CMAKE_SOURCE_DIR}/lib-source/include
# )

link_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB_RECURSE SRC_LIST
        "main.c"
)

message(${SRC_LIST})

add_executable(test-c-call-cpp.out ${SRC_LIST})

# 在工程中共引入target搜索路径
target_include_directories(test-c-call-cpp.out PRIVATE ${CMAKE_SOURCE_DIR}/lib-source/include)

# 添加库
# 2023/10/31 链接静态库提示 in function `wrapper_circle_queue_create':
# circle_queue.cpp:(.text+0x241): undefined reference to `operator new(unsigned long)'
# 及 In function `wrapper_circle_queue_delete':
# circle_queue.cpp:(.text+0x298): undefined reference to `operator delete(void*)'
# 编译成动态则可以运行，不知道为什么
target_link_libraries(test-c-call-cpp.out PRIVATE test-c-call-cpp)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)


