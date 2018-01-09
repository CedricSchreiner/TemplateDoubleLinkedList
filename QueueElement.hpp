//
// Created by Cedric on 06.01.2018.
//

#ifndef DOUBLELINKEDLIST_LISTELEMENT_HPP
#define DOUBLELINKEDLIST_LISTELEMENT_HPP
#endif

#include <string>
#include <ostream>

using namespace std;

template <typename T>
class QueueElement {
public:
    ~QueueElement() = default;
    explicit QueueElement(T value);
    void setNext(QueueElement<T> *next);
    void setPrvious(QueueElement<T> *previous);
    void setValue(T value);
    QueueElement<T>* getNext();
    QueueElement<T>* getPrevious();
    T getValue();

    //operators
    bool operator==(const QueueElement<T> &rhs) const;
    bool operator!=(const QueueElement<T> &rhs) const;
    friend ostream &operator<<(ostream &os, const QueueElement<T> &element);

protected:
private:
    QueueElement *next;
    QueueElement *previous;
    T value;
};

template <typename T>
QueueElement<T>::QueueElement(T value) {
    this->previous = nullptr;
    this->next = nullptr;
    this->value = value;
}

template <typename T>
void QueueElement<T>::setPrvious(QueueElement<T> *previous) {
    this->previous = previous;
}

template <typename T>
void QueueElement<T>::setNext(QueueElement<T> *next) {
    this->next = next;
}

template <typename T>
void QueueElement<T>::setValue(const T value) {
    this->value = value;
}

template <typename T>
QueueElement<T>* QueueElement<T>::getNext() {
    return this->next;
}

template <typename T>
QueueElement<T>* QueueElement<T>::getPrevious() {
    return this->previous;
}

template <typename T>
T QueueElement<T>::getValue() {
    return this->value;
}

template <typename T>
bool QueueElement<T>::operator==(const QueueElement<T> &rhs) const {
    return value == rhs.value;
}

template <typename T>
bool QueueElement<T>::operator!=(const QueueElement<T> &rhs) const {
    return !(rhs == *this);
}

template <typename T>
ostream &operator<<(ostream &os, const QueueElement<T> &element) {
    return os << element.value;
}