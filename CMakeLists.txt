cmake_minimum_required(VERSION 3.30)
project(linked_lists C)

set(CMAKE_C_STANDARD 99)

add_executable(linked_lists main.c
        LinkedList/LinkedList.c
        LinkedList/LinkedList.h
        DoublyLinkedList/DoublyLinkedList.c
        DoublyLinkedList/DoublyLinkedList.h)
