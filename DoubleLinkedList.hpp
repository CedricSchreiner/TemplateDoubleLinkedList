//
// Created by Cedric on 06.01.2018.
//

#include "ListElement.hpp"

#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_HPP

#endif

class DoubleLinkedList {
public:
    DoubleLinkedList();
    explicit DoubleLinkedList(char **array);
    DoubleLinkedList(const DoubleLinkedList &rhs);
    void pushBack(const char *value);
    void pushFront(const char *value);
    char* popBack();
    char* popFront();
    void removeElement(int position);

    //operators
    bool operator==(const DoubleLinkedList &rhs) const;
    bool operator!=(const DoubleLinkedList &rhs) const;
    DoubleLinkedList& operator=(const DoubleLinkedList& right);
    DoubleLinkedList operator+(const DoubleLinkedList& right);
    DoubleLinkedList& operator+=(const DoubleLinkedList& right);
    ListElement* operator[](int i);

protected:
private:
    ListElement *header;
    ListElement *tail;
    int numberOfElements;
};
