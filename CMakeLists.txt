cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_executable(task_1 homework1/task_1.c homework1/input_task_1.h homework1/input_task_1.c)
