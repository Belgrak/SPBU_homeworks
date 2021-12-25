cmake_minimum_required(VERSION 3.17)
project(spbu_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c
        library/commonUtils/ioInputInteger.c
        library/commonUtils/linkedMap.c
        library/commonUtils/values.c
        library/commonUtils/treeMap.c
        library/commonUtils/mergeSort.c
        library/commonUtils/binary.c
        library/commonUtils/DFA.c
        library/commonUtils/linkedList.c
        library/commonUtils/list.c
        library/commonUtils/complexNumber.c
)
add_library(library ${SOURCE_LIB})

set(TREE_LIB
        library/commonUtils/values.c
        library/commonUtils/treeMap.c
        )
add_library(treeMap ${TREE_LIB})

add_executable(task1.1 homework1/task_1.c)
target_link_libraries(task1.1 library)
add_executable(task1.2 homework1/task_2.c)
add_executable(task1.3 homework1/task_3.c)
add_executable(task1.4 homework1/task_4.c)
target_link_libraries(task1.4 library)
add_executable(task1.5 homework1/task_5.c)

add_executable(task2.1 homework2/task2_1.c)
target_link_libraries(task2.1 library)
add_executable(task2.2 homework2/task2_2.c)
target_link_libraries(task2.2 library)

add_executable(task3.1 homework3/task3.1.c)
target_link_libraries(task3.1 library m)
add_executable(task3.2 homework3/task3_2.c)
add_executable(task3.3 homework3/task3_3.c)
target_link_libraries(task3.3 library)

add_executable(task4.1 homework4/task4_1.c)
target_link_libraries(task4.1 library m)

add_executable(task5.1 homework5/task5.1.c)
target_link_libraries(task5.1 treeMap m)

add_executable(test2.1 test2/test2.1.c)
target_link_libraries(test2.1 library)
add_executable(test2.2 test2/test2.2.c)

add_executable(task8.2 homework8/task8.2.c)
target_link_libraries(task8.2 library)

add_executable(retest1.1 retest1/retest1.1.c)
target_link_libraries(retest1.1 library m)
add_executable(retest1.2 retest1/retest1.2.c)
target_link_libraries(retest1.2 library)

add_executable(final2 final/final2.c)
target_link_libraries(final2 library m)

add_executable(final1 final/final1.c)
target_link_libraries(final1 library m)

add_executable(retest.final3 final2/retest.final3.c)
add_executable(retest2.3 final2/retest2.3.c)
target_link_libraries(retest2.3 library)

