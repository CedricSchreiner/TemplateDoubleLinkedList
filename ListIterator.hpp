//
// Created by Cedric on 06.01.2018.
//

#ifndef DOUBLELINKEDLIST_LISTITERATOR_HPP
#define DOUBLELINKEDLIST_LISTITERATOR_HPP

#endif

#include "DoubleLinkedList.hpp"

class ListIterator {
public:
    explicit ListIterator(DoubleLinkedList *list);
    bool hasNext();
    ListElement* next();
    void remove();
protected:
private:
    DoubleLinkedList *list;
    int position;
};
