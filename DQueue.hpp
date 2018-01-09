//
// Created by Cedric on 06.01.2018.
//

#include "QueueElement.hpp"

#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_HPP

#endif
template <typename T>
class DQueue {
public:
    ~DQueue() = default;
    DQueue();
    explicit DQueue(T *array, int size);
    DQueue(const DQueue<T> &rhs);
    void pushBack(T value);
    void pushFront(T value);
    T popBack();
    T popFront();
    void removeElement(int position);
    const char* toString();
    const char* printBackwards();

    //operators
    bool operator==(const DQueue<T> &rhs) const;
    bool operator!=(const DQueue<T> &rhs) const;
    DQueue<T>& operator=(const DQueue<T>& right);
    DQueue<T> operator+(const DQueue<T>& right);
    DQueue<T>& operator+=(const DQueue<T>& right);
    QueueElement<T>* operator[](int i);

protected:
private:
    QueueElement<T> *header;
    QueueElement<T> *tail;
    int numberOfElements;
};


template <typename T>
DQueue<T>::DQueue() {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;
}

template <typename T>
DQueue<T>::DQueue(T *array, int size) {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;

    int i = 0;
    while (i < size) {
        this->pushBack(array[i]);
        i++;
    }
}

template <typename T>
DQueue<T>::DQueue(const DQueue &rhs) :
        header {new QueueElement<T>(rhs.header->getValue())},
        tail {new QueueElement<T>(rhs.tail->getValue())},
        numberOfElements {0} {
    QueueElement<T> *rhsElement = rhs.header;
    while(rhsElement != nullptr) {
        this->pushBack(rhsElement->getValue());
        rhsElement = rhsElement->getNext();
    }
}

template <typename T>
void DQueue<T>::pushBack(const T value) {
    //insert first element
    if (this->numberOfElements == 0) {
        this->header = new QueueElement<T>(value);
        this->tail = new QueueElement<T>(value);
    } else if (this->numberOfElements == 1) {
        auto *element = new QueueElement<T>(value);
        this->tail = element;
        this->tail->setPrvious(this->header);
        this->header->setNext(element);
    } else {
        auto * element = new QueueElement<T>(value);
        element->setPrvious(this->tail);
        this->tail->setNext(element);
        this->tail = element;
    }
    this->numberOfElements++;
}

template <typename T>
void DQueue<T>::pushFront(const T value) {
    if (this->numberOfElements == 0) {
        this->header = new QueueElement<T>(value);
        this->tail = new QueueElement<T>(value);
    } else if (this->numberOfElements == 1) {
        auto *element = new QueueElement<T>(value);
        this->header = element;
        this->header->setNext(this->tail);
        this->tail->setPrvious(element);
    } else {
        auto * element = new QueueElement<T>(value);
        element->setNext(this->header);
        this->header->setPrvious(element);
        this->header = element;
    }
    this->numberOfElements++;
}

template <typename T>
T DQueue<T>::popBack() {
    if (this->numberOfElements == 0) {

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
T DQueue<T>::popFront() {
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
void DQueue<T>::removeElement(int position) {
    if (position == 1) {
        this->popFront();
    } else {
        QueueElement<T> *element = this->operator[](position - 1);
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
const char* DQueue<T>::toString() {
    QueueElement<T> *element = this->header;
    auto *string = new std::string;
    while(element != nullptr) {
        *string += element->getValue();
        *string += '\n';
        element = element->getNext();
    }
    return string->c_str();
}

template <typename T>
const char* DQueue<T>::printBackwards() {
    QueueElement<T> *element = this->tail;
    auto *string = new std::string;
    while(element != nullptr) {
        *string += element->getValue();
        *string += '\n';
        element = element->getPrevious();
    }
    return string->c_str();
}

template <typename T>
bool DQueue<T>::operator==(const DQueue<T> &rhs) const {
    QueueElement<T> *thisElement = this->header;
    QueueElement<T> *rhsElement = rhs.header;

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
    return rhsElement == nullptr;
}

template <typename T>
bool DQueue<T>::operator!=(const DQueue<T> &rhs) const {
    return !(rhs == *this);
}

template <typename T>
DQueue<T>& DQueue<T>::operator=(const DQueue<T> &right) {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;
    QueueElement<T> *rhsElement = right.header;
    while(rhsElement != nullptr) {
        this->pushFront(rhsElement->getValue());
        rhsElement = rhsElement->getNext();
    }
    return *this;
}

template <typename T>
DQueue<T> DQueue<T>::operator+(const DQueue<T> &right) {
    *this += right;
    return *this;
}

template <typename T>
DQueue<T>& DQueue<T>::operator+=(const DQueue<T> &right) {
    QueueElement<T> *element = right.header;
    while(element != nullptr) {
        this->pushBack(element->getValue());
        element = element->getNext();
    }

    return *this;
}

template <typename T>
QueueElement<T>* DQueue<T>::operator[](const int i) {
    int index = 0;
    QueueElement<T> *element = header;
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