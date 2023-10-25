cmake_minimum_required(VERSION 3.10)

project(test-circle-queue LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 必须放到add_executable之前
link_directories(${CMAKE_SOURCE_DIR}/../../../debug/lib)
link_libraries(gtest_maind gtestd)

include_directories(
    ./include
)

file(GLOB_RECURSE SRC_LIST
        "src/*.cpp"
        "main.cpp"
        )

message(${SRC_LIST})

add_executable(test-circle-queue ${SRC_LIST})

# 在工程中共引入GoogleTest头文件搜索路径
target_include_directories(test-circle-queue PUBLIC ${CMAKE_SOURCE_DIR}/../../include)




set_target_properties(test-circle-queue PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")

