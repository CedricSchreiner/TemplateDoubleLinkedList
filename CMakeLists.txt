cmake_minimum_required(VERSION 3.9)
project(TemplateDoubleLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(DoubleLinkedList main.cpp ListElement.cpp ListElement.hpp DoubleLinkedList.cpp DoubleLinkedList.hpp ListIterator.cpp ListIterator.hpp)