cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
        library/commonUtils/ioInputInteger.c
        library/commonUtils/linkedMap.c
        library/commonUtils/mergeSort.c
        library/commonUtils/binary.c
        library/commonUtils/DFA.c

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

add_executable(task3.1 homework3/task3.1.c)
target_link_libraries(task3.1 library m)
add_executable(task3.2 homework3/task3_2.c)
add_executable(task3.3 homework3/task3_3.c)
target_link_libraries(task3.3 library)

add_executable(task4.1 homework4/task4_1.c)
target_link_libraries(task4.1 library m)

add_executable(test2.1 test2/test2.1.c)
target_link_libraries(test2.1 library)

add_executable(test2.2 test2/test2.2.c)

add_executable(task8.2 homework8/task8.2.c)
target_link_libraries(task8.2 library)

add_executable(final1 final/final1.c)
target_link_libraries(final1 library)