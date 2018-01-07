#include <iostream>
#include "ListIterator.hpp"

using namespace std;

template <class T>
bool checkList(DoubleLinkedList<T> *list, T *array, int size) {
    auto *iterator = new ListIterator<T>(list);
    int arrayPosition = 0;

    while (iterator->hasNext()) {
        if (array[arrayPosition] != nullptr) {
            if (array[arrayPosition] != iterator->next()->getValue()) {
                return false;
            }
            arrayPosition++;
        } else {
            return false;
        }
    }
    return size == arrayPosition;
}

void testList() {
    int numberOfSuccessfulTests = 0;
    auto *list = new DoubleLinkedList<char*>();
    list->pushFront(const_cast<char *>("element1"));
    list->pushBack(const_cast<char *>("element2"));
    list->pushFront(const_cast<char *>("element3"));
    list->pushFront(const_cast<char *>("element4"));
    list->pushFront(const_cast<char *>("element5"));
    list->pushBack(const_cast<char *>("element6"));
    list->pushBack(const_cast<char *>("element7"));

    char* elements[] = {const_cast<char *>("element5"), const_cast<char *>("element4"), const_cast<char *>("element3"),
                        const_cast<char *>("element1"), const_cast<char *>("element2"), const_cast<char *>("element6"),
                        const_cast<char *>("element7")};

    //Test 1
    numberOfSuccessfulTests += checkList(list, elements, 7);
    //Test 2
    numberOfSuccessfulTests += (list->popFront() == "element5");
    //Test 3
    numberOfSuccessfulTests += (list->popBack() == "element7");
    //Test 4
    numberOfSuccessfulTests += (list->popFront() == "element4");
    //Test 5
    numberOfSuccessfulTests += (list->popFront() == "element3");
    //Test 6
    numberOfSuccessfulTests += (list->popBack() == "element6");
    //Test 7
    numberOfSuccessfulTests += (list->popBack() == "element2");
    //Test 8
    numberOfSuccessfulTests += (list->popFront() == "element1");

    list->pushFront(const_cast<char *>("element1"));
    list->pushBack(const_cast<char *>("element2"));
    list->pushFront(const_cast<char *>("element3"));
    list->pushFront(const_cast<char *>("element4"));
    list->pushFront(const_cast<char *>("element5"));
    list->pushBack(const_cast<char *>("element6"));
    list->pushBack(const_cast<char *>("element7"));

    auto *iterator = new ListIterator<char *>(list);

    //Test 9
    numberOfSuccessfulTests += iterator->hasNext();
    //Test 10
    numberOfSuccessfulTests += (iterator->next()->getValue() == (char *) "element5");
    iterator->remove();
    //Test 11
    numberOfSuccessfulTests += (iterator->next()->getValue() == "element4");
    //Test 12
    numberOfSuccessfulTests += (iterator->next()->getValue() == "element3");
    iterator->remove();
    //Test 13
    numberOfSuccessfulTests += (iterator->next()->getValue() == "element1");
    //Test 14
    numberOfSuccessfulTests += iterator->hasNext();
    //Test 15
    numberOfSuccessfulTests += (iterator->next()->getValue() == "element2");
    iterator->remove();
    //Test 16
    numberOfSuccessfulTests += (iterator->next()->getValue() == "element6");
    //Test 17
    numberOfSuccessfulTests += (iterator->next()->getValue() == "element7");
    iterator->remove();
    //Test 18
    numberOfSuccessfulTests += !iterator->hasNext();

    char* elements2[] = {const_cast<char *>("element4"), const_cast<char *>("element1"), const_cast<char *>("element6")};

    //Test 19
    numberOfSuccessfulTests += checkList(list, elements2, 3);
    cout << numberOfSuccessfulTests << "/19 tests successful"<< endl;
}

void dialog() {
    cout << "1: neue Liste erstellen" << endl;
    cout << "2: Typ der Liste ausgeben" << endl;
    cout << "3: Element vorne anhaengen" << endl;
    cout << "4: Element hinten anhaengen" << endl;
    cout << "5: Element vorne erhalten" << endl;
    cout << "6: Element hinten erhalten" << endl;
    cout << "7: Liste von vorne nach hinten ausgeben" << endl;
    cout << "8: Liste von hinten nach vorne ausgeben" << endl;
}

int main() {
    testList();
    dialog();

    return 0;
}