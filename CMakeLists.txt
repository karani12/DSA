cmake_minimum_required(VERSION 3.27)
project(DSA C)

set(CMAKE_C_STANDARD 11)

add_library(DSA STATIC BTree.c
        BinaryTree.c
        Stack.c)
