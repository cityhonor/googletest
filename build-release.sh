#! /bin/bash
if [ ! -d release ];then
	mkdir release
	cd release
else
	cd release
	rm -rf ./*
fi	
cmake .. \
-DCMAKE_BUILD_TYPE=Release \
-Dgtest_force_shared_crt=ON \
-Dgtest_build_samples=ON \
-DCMAKE_INSTALL_PREFIX=./
#-DCMAKE_TOOLCHAIN_FILE=../toolchin-cmake/arm-buildroot-linux-gnueabihf.cmake
make -j8
