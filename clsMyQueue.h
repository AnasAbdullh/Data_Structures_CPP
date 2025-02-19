#pragma once
#include "clsDblLinkedList.h"


template <class T>
class clsMyQueue {
protected:
    clsDblLinkedList<T> MydblLinkedList;

public:
    void push(T value) {
        MydblLinkedList.InsertAtEnd(value);
    }

    void Print() {
        MydblLinkedList.PrintList();
    }

    int Size() {
        return MydblLinkedList.Size();
    }

    T front() {
        if (MydblLinkedList.Size() == 0) {
            throw std::out_of_range("Queue is empty!"); // أو إرجاع قيمة افتراضية
        }
        return MydblLinkedList.GetItem(0);
    }

    T back() {
        if (MydblLinkedList.Size() == 0) {
            throw std::out_of_range("Queue is empty!"); // أو إرجاع قيمة افتراضية
        }
        return MydblLinkedList.GetItem(Size() - 1);
    }

    void pop() {
        if (MydblLinkedList.Size() == 0) {
            throw std::out_of_range("Queue is empty!"); // أو إرجاع false
        }
        MydblLinkedList.DeleteFirstNode();
    }
    
    T GetItem(T Item)
    {
      return MydblLinkedList.GetItem(Item);
    }
    
    void Reverse()
    {
      MydblLinkedList.Reverse();
    }
    
    bool UpdateItem(T index, T NewValue)
    {
      return MydblLinkedList.UpdateItem(index,NewValue);
    }
    
    bool InsertAfter(T index,T value)
    {
     return MydblLinkedList.InsertAfter(index,value);
    }
    
    void InsertAtFront(T value)
    {
      MydblLinkedList.InsertAtBeginning(value);
    }
    
    void InsertAtBack(T value)
    {
      MydblLinkedList.InsertAtEnd(value);
    }
    
    void Clear()
    {
      MydblLinkedList.Clear();
    }
    
    
};
