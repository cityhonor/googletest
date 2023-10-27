cmake_minimum_required(VERSION 3.10)

project(libcircle-queue LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SRC_LIST
        "src/*.cpp"
        )

message(${SRC_LIST})
message(${CMAKE_SOURCE_DIR})

add_library(libcircle-queue STATIC ${SRC_LIST})

target_include_directories(
    libcircle-queue PRIVATE ./include
)

set_target_properties(libcircle-queue PROPERTIES OUTPUT_NAME "circle-queue")
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib-source/lib)





