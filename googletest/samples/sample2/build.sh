#! /bin/bash

function error_input
{
	echo "Please enter valid parameters"
}

function make_fun
{
	if [ -d build ];then
		rm -rf ./build/*
	else
		mkdir build
	fi

	cd build

	if [ "$1" == CROSS ]; then
	CROSS_COMPLITE_PATH=${PWD}/../../../../toolchain-cmake
	CROSS_COMPLITE_NAME=arm-buildroot-linux-gnueabihf.cmake
	cmake .. -DCMAKE_TOOLCHAIN_FILE=${CROSS_COMPLITE_PATH}/${CROSS_COMPLITE_NAME} -DCMAKE_BUILD_PLATFORM=ARM

	else
	cmake ..

	fi

	make -j8


}


if [ 1 -gt "$#" ]; then
	echo "please enter valid parameters"
else
	make_fun "$1"
fi

# $0：表示脚本名称。
# $#：表示传递给脚本的参数个数。
# $@：表示所有传递给脚本的参数的列表。
# $?：表示上一个命令的返回值。