#! /bin/bash
if [ ! -d debug ];then
        mkdir debug
        cd debug
else
        cd debug
        rm -rf ./*
fi
cmake .. \
-DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_DEBUG_POSTFIX=d \
-Dgtest_force_shared_crt=ON \
-Dgtest_build_samples=ON \
-DCMAKE_INSTALL_PREFIX=./
#-DCMAKE_TOOLCHAIN_FILE=../toolchin-cmake/arm-buildroot-linux-gnueabihf.cmake
make -j8

