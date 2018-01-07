//
// Created by Cedric on 06.01.2018.
//

#include "ListElement.hpp"

#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_HPP

#endif
template <typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList();
    explicit DoubleLinkedList(T *array);
    DoubleLinkedList(const DoubleLinkedList<T> &rhs);
    void pushBack(T value);
    void pushFront(T value);
    T popBack();
    T popFront();
    void removeElement(int position);

    //operators
    bool operator==(const DoubleLinkedList<T> &rhs) const;
    bool operator!=(const DoubleLinkedList<T> &rhs) const;
    DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& right);
    DoubleLinkedList<T> operator+(const DoubleLinkedList<T>& right);
    DoubleLinkedList<T>& operator+=(const DoubleLinkedList<T>& right);
    ListElement<T>* operator[](int i);

protected:
private:
    ListElement<T> *header;
    ListElement<T> *tail;
    int numberOfElements;
};


template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(T *array) {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;

    int i = 0;
    while (array[i] != nullptr) {
        this->pushFront(array[i]);
        i++;
    }
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList &rhs) :
        header {new ListElement<T>(rhs.header->getValue())},
        tail {new ListElement<T>(rhs.tail->getValue())},
        numberOfElements {0} {
    ListElement<T> *rhsElement = rhs.header;
    while(rhsElement != nullptr) {
        this->pushFront(rhsElement->getValue());
        rhsElement = rhsElement->getNext();
    }
}

template <typename T>
void DoubleLinkedList<T>::pushBack(const T value) {
    //insert first element
    if (this->numberOfElements == 0) {
        this->header = new ListElement<T>(value);
        this->tail = new ListElement<T>(value);
    } else if (this->numberOfElements == 1) {
        auto *element = new ListElement<T>(value);
        this->tail = element;
        this->tail->setPrvious(this->header);
        this->header->setNext(element);
    } else {
        auto * element = new ListElement<T>(value);
        element->setPrvious(this->tail);
        this->tail->setNext(element);
        this->tail = element;
    }
    this->numberOfElements++;
}

template <typename T>
void DoubleLinkedList<T>::pushFront(const T value) {
    if (this->numberOfElements == 0) {
        this->header = new ListElement<T>(value);
        this->tail = new ListElement<T>(value);
    } else if (this->numberOfElements == 1) {
        auto *element = new ListElement<T>(value);
        this->header = element;
        this->header->setNext(this->tail);
        this->tail->setPrvious(element);
    } else {
        auto * element = new ListElement<T>(value);
        element->setNext(this->header);
        this->header->setPrvious(element);
        this->header = element;
    }
    this->numberOfElements++;
}

template <typename T>
T DoubleLinkedList<T>::popBack() {
    if (this->numberOfElements == 0) {
        return nullptr;
    } else if (this->numberOfElements == 1) {
        this->numberOfElements--;
        T value = this->tail->getValue();
        this->header = nullptr;
        this->tail = nullptr;
        return value;
    } else {
        this->numberOfElements--;
        T value = this->tail->getValue();
        this->tail = this->tail->getPrevious();
        this->tail->getNext()->setPrvious(nullptr);
        this->tail->setNext(nullptr);
        return value;
    }
}

template <typename T>
T DoubleLinkedList<T>::popFront() {
    if (this->numberOfElements == 0) {

    } else if (this->numberOfElements == 1) {
        this->numberOfElements--;
        T value = this->header->getValue();
        this->header = nullptr;
        this->tail = nullptr;
        return value;
    } else {
        this->numberOfElements--;
        T value = this->header->getValue();
        this->header = this->header->getNext();
        this->header->getPrevious()->setNext(nullptr);
        this->header->setPrvious(nullptr);
        return value;
    }
}

template <typename T>
void DoubleLinkedList<T>::removeElement(int position) {
    if (position == 1) {
        this->popFront();
    } else {
        ListElement<T> *element = this->operator[](position - 1);
        if (element == this->tail) {
            this->popBack();
        } else {
            element->getPrevious()->setNext(element->getNext());
            element->getNext()->setPrvious(element->getPrevious());
            element->setNext(nullptr);
            element->setPrvious(nullptr);
            this->numberOfElements--;
        }
    }
}

template <typename T>
bool DoubleLinkedList<T>::operator==(const DoubleLinkedList<T> &rhs) const {
    ListElement<T> *thisElement = this->header;
    ListElement<T> *rhsElement = rhs.header;

    if (thisElement == nullptr && rhsElement != nullptr) {
        return false;
    }

    while (thisElement != nullptr) {
        if (rhsElement == nullptr || *rhsElement != *thisElement) {
            return false;
        }

        rhsElement = rhsElement->getNext();
        thisElement = thisElement->getNext();
    }
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::operator!=(const DoubleLinkedList<T> &rhs) const {
    return !(rhs == *this);
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> &right) {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;
    ListElement<T> *rhsElement = right.header;
    while(rhsElement != nullptr) {
        this->pushFront(rhsElement->getValue());
        rhsElement = rhsElement->getNext();
    }
    return *this;
}

template <typename T>
DoubleLinkedList<T> DoubleLinkedList<T>::operator+(const DoubleLinkedList<T> &right) {
    *this += right;
    return *this;
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator+=(const DoubleLinkedList<T> &right) {
    ListElement<T> *element = right.header;
    while(element != nullptr) {
        this->pushBack(element->getValue());
        element = element->getNext();
    }

    return *this;
}

template <typename T>
ListElement<T>* DoubleLinkedList<T>::operator[](const int i) {
    int index = 0;
    ListElement<T> *element = header;
    if (i >= 0 && i < numberOfElements) {
        while(index < i) {
            element = element->getNext();
            index++;
        }
        return element;
    } else {
        return nullptr;
    }
}