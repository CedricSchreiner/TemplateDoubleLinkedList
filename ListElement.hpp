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
class ListElement {
public:
    ~ListElement() = default;
    explicit ListElement(T value);
    void setNext(ListElement<T> *next);
    void setPrvious(ListElement<T> *previous);
    void setValue(T value);
    ListElement<T>* getNext();
    ListElement<T>* getPrevious();
    T getValue();

    //operators
    bool operator==(const ListElement<T> &rhs) const;
    bool operator!=(const ListElement<T> &rhs) const;
    friend ostream &operator<<(ostream &os, const ListElement<T> &element);

protected:
private:
    ListElement *next;
    ListElement *previous;
    T value;
};

template <typename T>
ListElement<T>::ListElement(T value) {
    this->previous = nullptr;
    this->next = nullptr;
    this->value = value;
}

template <typename T>
void ListElement<T>::setPrvious(ListElement<T> *previous) {
    this->previous = previous;
}

template <typename T>
void ListElement<T>::setNext(ListElement<T> *next) {
    this->next = next;
}

template <typename T>
void ListElement<T>::setValue(const T value) {
    this->value = value;
}

template <typename T>
ListElement<T>* ListElement<T>::getNext() {
    return this->next;
}

template <typename T>
ListElement<T>* ListElement<T>::getPrevious() {
    return this->previous;
}

template <typename T>
T ListElement<T>::getValue() {
    return this->value;
}

template <typename T>
bool ListElement<T>::operator==(const ListElement<T> &rhs) const {
    return value == rhs.value;
}

template <typename T>
bool ListElement<T>::operator!=(const ListElement<T> &rhs) const {
    return !(rhs == *this);
}

template <typename T>
ostream &operator<<(ostream &os, const ListElement<T> &element) {
    return os << element.value;
}