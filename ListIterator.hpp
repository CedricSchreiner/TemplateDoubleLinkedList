//
// Created by Cedric on 06.01.2018.
//

#ifndef DOUBLELINKEDLIST_LISTITERATOR_HPP
#define DOUBLELINKEDLIST_LISTITERATOR_HPP

#endif

#include "DoubleLinkedList.hpp"

template <typename T>
class ListIterator {
public:
    explicit ListIterator(DoubleLinkedList<T> *list);
    bool hasNext();
    ListElement<T>* next();
    void remove();
protected:
private:
    DoubleLinkedList<T> *list;
    int position;
};

template <typename T>
ListIterator<T>::ListIterator(DoubleLinkedList<T> *list) {
    this->list = list;
    this->position = 0;
}

template <typename T>
bool ListIterator<T>::hasNext() {
    bool tmp = this->list->operator[](position) != nullptr;
    return tmp;
}

template <typename T>
ListElement<T>* ListIterator<T>::next() {
    ListElement<T> *element = this->list->operator[](position++);
    return element;
}

template <typename T>
void ListIterator<T>::remove() {
    this->list->removeElement(position--);
}