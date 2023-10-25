#! /bin/bash
if [ ! -d debug_cross_complite ];then
        mkdir debug_cross_complite
else
        rm -rf ./debug_cross_complite/*
fi

CROSS_COMPLITE_PATH=${PWD}/toolchain-cmake

CROSS_COMPLITE_NAME=arm-buildroot-linux-gnueabihf.cmake

cd debug_cross_complite

cmake .. \
-DCMAKE_BUILD_TYPE=Debug \ 
-DCMAKE_DEBUG_POSTFIX=d \
-Dgtest_force_shared_crt=ON \
-Dgtest_build_samples=ON \
-DCMAKE_INSTALL_PREFIX=./ \
-DCMAKE_TOOLCHAIN_FILE=${CROSS_COMPLITE_PATH}/${CROSS_COMPLITE_NAME}
make -j8



# -DCMAKE_BUILD_TYPE=Debug 
# None: 编译器默认值
# Debug: 产生除错信息
# Release: 进行最佳化
# RelWithDebInfo: 进行最佳化，但仍然会启用 DEBUG flag
# MinSizeRel: 进行程式码最小化

# CMAKE_C_FLAGS C编译器的编译选项

# PROJECT_SOURCE_DIR 目前正在处理中的专案最上层目录，即内含 project() 指令的 CMakeLists 所在资料夹

# CMAKE_CXX_FLAGS C++编译器的编译选项。

# -DCMAKE_DEBUG_POSTFIX=d如果编译方式是debug，加这一项，出来的lib后面就会带一个d

# -DCMAKE_DEBUG_POSTFIX：debug版本生成lib追加的后缀名（d表示原本为xx.so，编译生成的是xxd.so）
# -Dgtest_force_shared_crt=ON：Winodws设置构建库类型为MD。
# -DCMAKE_INSTALL_PREFIX=~/SDK/googletest/v1.12.1/debug ：指定SDK生成后的保存目录。
# -DCMAKE_C_COMPILER=/usr/bin/gcc-11：指定使用的gcc编译版本。
# -DCMAKE_CXX_COMPILER=/usr/bin/g++-11：指定使用的g++版本。
# -DCMAKE_TOOLCHAIN_FILE cmake工具链文件(.cmake)
