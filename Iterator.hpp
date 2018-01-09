//
// Created by Cedric on 06.01.2018.
//

#ifndef DOUBLELINKEDLIST_LISTITERATOR_HPP
#define DOUBLELINKEDLIST_LISTITERATOR_HPP

#endif

#include "DQueue.hpp"

template <typename T>
class Iterator {
public:
    explicit Iterator(DQueue<T> *list);
    bool hasNext();
    QueueElement<T>* next();
    void remove();
protected:
private:
    DQueue<T> *list;
    int position;
};

template <typename T>
Iterator<T>::Iterator(DQueue<T> *list) {
    this->list = list;
    this->position = 0;
}

template <typename T>
bool Iterator<T>::hasNext() {
    bool tmp = this->list->operator[](position) != nullptr;
    return tmp;
}

template <typename T>
QueueElement<T>* Iterator<T>::next() {
    QueueElement<T> *element = this->list->operator[](position++);
    return element;
}

template <typename T>
void Iterator<T>::remove() {
    this->list->removeElement(position--);
}