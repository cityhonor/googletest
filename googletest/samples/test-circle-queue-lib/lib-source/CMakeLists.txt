cmake_minimum_required(VERSION 3.10)

project(libcircle-queue LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SRC_LIST
        "src/*.cpp"
        )

message(${SRC_LIST})

link_directories(${CMAKE_SOURCE_DIR}/../../../debug/lib)

add_library(libcircle-queue STATIC ${SRC_LIST})

set_target_properties(libcircle-queue PROPERTIES OUTPUT_NAME "circle-queue")
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

# 设置可执行文件的输出路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# # 在工程中共引入GoogleTest头文件搜索路径
# target_include_directories(libcircle-queue PUBLIC ${CMAKE_SOURCE_DIR}/../../include)

# 必须放到add_executable之前
target_link_libraries(libcircle-queue PRIVATE gtest_maind gtestd)

include_directories(
    ./include
)


# set_target_properties(libcircle-queue PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")

