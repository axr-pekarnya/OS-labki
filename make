#!/bin/bash

main_dir=$(pwd)
build_dir="$(pwd)/build"

rm -rf ${build_dir}
mkdir ${build_dir}
cd ${build_dir}

cmake ../
cmake --build . --target lab2_test 
ctest -V