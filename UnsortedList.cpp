#include "UnsortedList.h"


template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    currentPos = nullptr;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    NodeT<T>* tmp;

    while(head != nullptr){
        tmp = head;
        head = head->next;
        delete tmp;
    }
    length = 0;
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    NodeT<T>* tmp;

    try {
        tmp = new NodeT<T>;
        delete tmp;
        return false;
    }
    catch(std::bad_alloc e) {
        return true;
    }

}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {

    NodeT<T>* curr = head;

    while(curr != nullptr) {

        if (curr->info == someItem) {
            return true;
        }
        curr = curr->next; // move to next item

    }

    return false;
}

template<class T>
void UnsortedList<T>::PutItem(T item) {

    NodeT<T>* newNode = new NodeT<T>;
    newNode->info = item;
    newNode->next = head;

    head = newNode;
    length++;
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    if (length > 0 && head->info == item) {
        NodeT<T>* tmp = head;
        head = head->next;
        delete tmp;
        length--;
        return;
    }

    NodeT<T>* curr = head;
    NodeT<T>* prev = nullptr;
    while(curr != nullptr){

        if (curr->info == item) {
            prev->next = curr->next;
            delete curr;
            length--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currentPos = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {

    if (currentPos == nullptr){
        throw "No items left!";
    }
    // return the item at the current position
    T currItem = currentPos->info; // remember the current item
    currentPos = currentPos->next; // move the iterator over
    return currItem; // return the current item
}