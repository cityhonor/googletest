cmake_minimum_required(VERSION 3.10)

project(libcircle-queue LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SRC_LIST
        "src/*.cpp"
        "main.cpp"
        )


link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)


add_library(libcircle-queue STATIC ${SRC_LIST})


target_include_directories(
    libcircle-queue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/lib-sub-source/include
)


# 在工程中共引入googletest头文件搜索路径
target_include_directories(libcircle-queue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib-sub-source/include)


target_link_libraries(libcircle-queue PRIVATE sub_source)


set_target_properties(libcircle-queue PROPERTIES OUTPUT_NAME "circle-queue")
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)





