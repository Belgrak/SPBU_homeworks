cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
        library/commonUtils/ioInputInteger.c
        library/commonUtils/linkedMap.c
)
add_library(library ${SOURCE_LIB})

add_executable(task1.1 homework1/task_1.c)
target_link_libraries(task1.1 library)
add_executable(task1.2 homework1/task_2.c)
add_executable(task1.3 homework1/task_3.c)
add_executable(task1.4 homework1/task_4.c)
target_link_libraries(task1.4 library)
add_executable(task1.5 homework1/task_5.c)

add_executable(task2.1 homework2/task2_1.c)
target_link_libraries(task2.1 library)

add_executable(task3.2 homework3/task3_2.c)
target_link_libraries(task3.2 m)