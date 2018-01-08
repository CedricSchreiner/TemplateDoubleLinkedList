#include <iostream>
#include "ListIterator.hpp"

using namespace std;

template <class T>
bool checkList(DoubleLinkedList<T> *list, T *array, int size) {
    auto *iterator = new ListIterator<T>(list);
    int arrayPosition = 0;

    while (iterator->hasNext()) {
        if (arrayPosition < size) {
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

void checkIfTestFailed(int *currentTest, int *failedTests, int numberOfSuccessfulTests) {
    (*currentTest)++;
    if (*currentTest != numberOfSuccessfulTests + *failedTests) {
        (*failedTests)++;
        cout << *currentTest << " failed" << endl;
    }
}

template <typename T>
void testList() {
    int numberOfSuccessfulTests = 0;
    int failedTests = 0;
    int currentTest = 0;

    //elements that are used for the test----------------------------------------------
    T element1 = 1;
    T element2 = 2;
    T element3 = 3;
    T element4 = 4;
    T element5 = 5;
    T element6 = 6;
    T element7 = 7;
    //----------------------------------------------------------------------------------

    //start test for the list-----------------------------------------------------------
    auto *list = new DoubleLinkedList<T>();
    list->pushFront(element1);
    list->pushBack(element2);
    list->pushFront(element3);
    list->pushFront(element4);
    list->pushFront(element5);
    list->pushBack(element6);
    list->pushBack(element7);

    T elements[] = {element5, element4, element3, element1, element2, element6, element7};

    //Test 1
    numberOfSuccessfulTests += checkList(list, elements, 7);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 2
    numberOfSuccessfulTests += (list->popFront() == element5);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 3
    numberOfSuccessfulTests += (list->popBack() == element7);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);
    //Test 4
    numberOfSuccessfulTests += (list->popFront() == element4);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 5
    numberOfSuccessfulTests += (list->popFront() == element3);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 6
    numberOfSuccessfulTests += (list->popBack() == element6);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 7
    numberOfSuccessfulTests += (list->popBack() == element2);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 8
    numberOfSuccessfulTests += (list->popFront() == element1);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);
    //-------------------------------------------------------------------------------------


    //start test the iterator for list-----------------------------------------------------
    list->pushFront(element1);
    list->pushBack(element2);
    list->pushFront(element3);
    list->pushFront(element4);
    list->pushFront(element5);
    list->pushBack(element6);
    list->pushBack(element7);

    auto *iterator = new ListIterator<T>(list);

    //Test 9
    numberOfSuccessfulTests += iterator->hasNext();
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 10
    numberOfSuccessfulTests += (iterator->next()->getValue() == element5);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);
    iterator->remove();

    //Test 11
    numberOfSuccessfulTests += (iterator->next()->getValue() == element4);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 12
    numberOfSuccessfulTests += (iterator->next()->getValue() == element3);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);
    iterator->remove();

    //Test 13
    numberOfSuccessfulTests += (iterator->next()->getValue() == element1);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 14
    numberOfSuccessfulTests += iterator->hasNext();
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 15
    numberOfSuccessfulTests += (iterator->next()->getValue() == element2);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);
    iterator->remove();

    //Test 16
    numberOfSuccessfulTests += (iterator->next()->getValue() == element6);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 17
    numberOfSuccessfulTests += (iterator->next()->getValue() == element7);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);
    iterator->remove();

    //Test 18
    numberOfSuccessfulTests += !iterator->hasNext();
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    T elements2[] = {element4, element1, element6};

    //Test 19
    numberOfSuccessfulTests += checkList(list, elements2, 3);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);
    //-------------------------------------------------------------------------------------

    //test the Copy constructor and operators----------------------------------------------
    DoubleLinkedList<T> copiedList(*list);

    //Test 20
    numberOfSuccessfulTests += checkList(&copiedList, elements2, 3);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 21
    numberOfSuccessfulTests += copiedList.operator==(*list);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 22
    copiedList.pushBack(element1);
    numberOfSuccessfulTests += copiedList.operator!=(*list);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);

    //Test 23
    T elements3[] = {element4, element1, element6, element1, element4, element1, element6};
    copiedList += *list;
    numberOfSuccessfulTests += checkList(&copiedList, elements3, 7);
    checkIfTestFailed(&currentTest, &failedTests, numberOfSuccessfulTests);
    //-------------------------------------------------------------------------------------

    cout << numberOfSuccessfulTests << "/23 tests successful"<< endl;
}

int main() {
    testList<double>();
    return 0;
}