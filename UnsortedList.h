#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

template<class T>
struct NodeT {
    T info;
    NodeT* next;
};

template<class T>
class UnsortedList
{
public:
  UnsortedList();
  // Constructor
  
  void MakeEmpty();
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  bool Contains(T someItem);
  // Function: Determines if someItem is in the list.
  // Pre:  List has been initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then the function returns true.
  // 	     otherwise it will return false. List is unchanged.

  void PutItem(T item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  // Post: item is in list.

  void DeleteItem(T item);
  // Function: Deletes the first element whose key matches item's key.
  // Pre:  ???
  // Post: ???    

  void ResetIterator();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  T GetNextItem();
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
  int length;
  NodeT<T>* head;           // head of list
  NodeT<T>* currentPos;     // used to remember where where we are in the iterator.
};


#include "UnsortedList.cpp"

#endif
