cmake_minimum_required(VERSION 3.9)
project(TemplateDoubleLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(TemplateDoubleLinkedList main.cpp DoubleLinkedList.hpp ListElement.hpp ListIterator.hpp)