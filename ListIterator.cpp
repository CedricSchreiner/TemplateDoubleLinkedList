//
// Created by Cedric on 06.01.2018.
//

#include "ListIterator.hpp"

ListIterator::ListIterator(DoubleLinkedList *list) {
    this->list = list;
    this->position = 0;
}

bool ListIterator::hasNext() {
    bool tmp = this->list->operator[](position) != nullptr;
    return tmp;
}

ListElement* ListIterator::next() {
    ListElement *element = this->list->operator[](position++);
    return element;
}

void ListIterator::remove() {
    this->list->removeElement(position--);
}