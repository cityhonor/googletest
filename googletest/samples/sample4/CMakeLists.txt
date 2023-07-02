cmake_minimum_required(VERSION 3.10)

project(sample4 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 必须放到add_executable之前
link_directories(${CMAKE_SOURCE_DIR}/../../../debug/lib)
link_libraries(gtest_maind gtestd)

include_directories(
    ./
)

aux_source_directory(. SRC_LIST)

message(${SRC_LIST})

add_executable(sample4 ${SRC_LIST})

# 在工程中共引入GoogleTest头文件搜索路径
target_include_directories(sample4 PUBLIC ${CMAKE_SOURCE_DIR}/../../include)




set_target_properties(sample4 PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")

