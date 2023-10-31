cmake_minimum_required(VERSION 3.10)

project(test-c-call-cpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB_RECURSE SRC_LIST
        "src/*.cpp"
        )

message(${SRC_LIST})

add_library(libtest-c-call-cpp SHARED ${SRC_LIST})
# add_library(libtest-c-call-cpp STATIC ${SRC_LIST})

set_target_properties(libtest-c-call-cpp PROPERTIES OUTPUT_NAME "test-c-call-cpp")
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib)


