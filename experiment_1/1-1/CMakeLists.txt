# 设置最低兼容的CMake版本
cmake_minimum_required(VERSION 3.18.2)
# 设置工程名称，储存在PROJECT_NAME变量中
project(experiment_1)

# 添加可执行文件
add_executable(${PROJECT_NAME} 
    1-1.cpp
    mat2x2.h
)