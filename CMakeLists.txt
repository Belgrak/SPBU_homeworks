cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
        library/commonUtils/ioInputInteger.c
)
add_library(library ${SOURCE_LIB})

add_executable(task1.1 homework1/task_1.c)
target_link_libraries(task1.1 library)
add_executable(task1.2 homework1/task_2.c)
