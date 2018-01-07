//
// Created by Cedric on 06.01.2018.
//
#include "DoubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList() {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;
}

DoubleLinkedList::DoubleLinkedList(char **array) {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;

    int i = 0;
    while (array[i] != nullptr) {
        this->pushFront(array[i]);
        i++;
    }
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &rhs) :
        header {new ListElement(rhs.header->getValue())},
        tail {new ListElement(rhs.tail->getValue())},
        numberOfElements {0} {
    ListElement *rhsElement = rhs.header;
    while(rhsElement != nullptr) {
        this->pushFront(rhsElement->getValue());
        rhsElement = rhsElement->getNext();
    }
}

void DoubleLinkedList::pushBack(const char *value) {
    //insert first element
    if (this->numberOfElements == 0) {
        this->header = new ListElement(value);
        this->tail = new ListElement(value);
    } else if (this->numberOfElements == 1) {
        auto *element = new ListElement(value);
        this->tail = element;
        this->tail->setPrvious(this->header);
        this->header->setNext(element);
    } else {
        auto * element = new ListElement(value);
        element->setPrvious(this->tail);
        this->tail->setNext(element);
        this->tail = element;
    }
    this->numberOfElements++;
}

void DoubleLinkedList::pushFront(const char *value) {
    if (this->numberOfElements == 0) {
        this->header = new ListElement(value);
        this->tail = new ListElement(value);
    } else if (this->numberOfElements == 1) {
        auto *element = new ListElement(value);
        this->header = element;
        this->header->setNext(this->tail);
        this->tail->setPrvious(element);
    } else {
        auto * element = new ListElement(value);
        element->setNext(this->header);
        this->header->setPrvious(element);
        this->header = element;
    }
    this->numberOfElements++;
}

char* DoubleLinkedList::popBack() {
    if (this->numberOfElements == 0) {
        return nullptr;
    } else if (this->numberOfElements == 1) {
        this->numberOfElements--;
        char *value = this->tail->getValue();
        this->header = nullptr;
        this->tail = nullptr;
        return value;
    } else {
        this->numberOfElements--;
        char *value = this->tail->getValue();
        this->tail = this->tail->getPrevious();
        this->tail->getNext()->setPrvious(nullptr);
        this->tail->setNext(nullptr);
        return value;
    }
}

char* DoubleLinkedList::popFront() {
    if (this->numberOfElements == 0) {
        return nullptr;
    } else if (this->numberOfElements == 1) {
        this->numberOfElements--;
        char *value = this->header->getValue();
        this->header = nullptr;
        this->tail = nullptr;
        return value;
    } else {
        this->numberOfElements--;
        char *value = this->header->getValue();
        this->header = this->header->getNext();
        this->header->getPrevious()->setNext(nullptr);
        this->header->setPrvious(nullptr);
        return value;
    }
}

void DoubleLinkedList::removeElement(int position) {
    if (position == 1) {
        this->popFront();
    } else {
        ListElement *element = this->operator[](position - 1);
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

bool DoubleLinkedList::operator==(const DoubleLinkedList &rhs) const {
    ListElement *thisElement = this->header;
    ListElement *rhsElement = rhs.header;

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

bool DoubleLinkedList::operator!=(const DoubleLinkedList &rhs) const {
    return !(rhs == *this);
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList &right) {
    this->header = nullptr;
    this->tail = nullptr;
    this->numberOfElements = 0;
    ListElement *rhsElement = right.header;
    while(rhsElement != nullptr) {
        this->pushFront(rhsElement->getValue());
        rhsElement = rhsElement->getNext();
    }
    return *this;
}

DoubleLinkedList DoubleLinkedList::operator+(const DoubleLinkedList &right) {
    *this += right;
    return *this;
}

DoubleLinkedList& DoubleLinkedList::operator+=(const DoubleLinkedList &right) {
    ListElement *element = right.header;
    while(element != nullptr) {
        this->pushBack(element->getValue());
        element = element->getNext();
    }

    return *this;
}

ListElement* DoubleLinkedList::operator[](const int i) {
    int index = 0;
    ListElement *element = header;
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