cmake_minimum_required(VERSION 3.10)

project(libsub_source LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SRC_LIST
        "src/*.cpp"
        )

add_library(libsub-source STATIC ${SRC_LIST})

target_include_directories(
    libsub-source PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(libsub-source PROPERTIES OUTPUT_NAME "sub_source")
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../lib)





