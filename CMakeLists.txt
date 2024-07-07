cmake_minimum_required(VERSION 3.28)
project(HuffEncoding)

set(CMAKE_CXX_STANDARD 17)

add_executable(HuffEncoding main.cpp
        MinHeap.h
        HuffNode.h
        LeafNode.h
        HuffTree.h
)
