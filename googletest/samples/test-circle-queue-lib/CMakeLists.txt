cmake_minimum_required(VERSION 3.10)

project(test-circle-queue.out LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(lib-source)
add_subdirectory(lib-source/lib-sub-source)


file(GLOB_RECURSE APP_LIST
        "main.cpp"
        )

message(${APP_LIST})


link_directories(${CMAKE_SOURCE_DIR}/lib-source/lib ${CMAKE_SOURCE_DIR}/../../../debug/lib)


add_executable(test-circle-queue.out ${APP_LIST})


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)


# 在工程中共引入googletest头文件搜索路径
target_include_directories(test-circle-queue.out PRIVATE ${CMAKE_SOURCE_DIR}/../../include)


# 添加circle-queue库文件的类声明头文件
target_include_directories(test-circle-queue.out PRIVATE ${CMAKE_SOURCE_DIR}/lib-source/include ${CMAKE_SOURCE_DIR}/lib-source/lib-sub-source/include)

# 2023/10/29学习 circle-queue库调用sub_source库类，此处引用circle-queue库需同时引用sub_source库，暂不明白其中原理
target_link_libraries(test-circle-queue.out PRIVATE gtest_maind gtestd circle-queue sub_source)


set_target_properties(test-circle-queue.out PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")

