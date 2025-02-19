#pragma once

#include "clsDblLinkedList.h"

template <class T>
class clsMyStack
{

protected :

    clsDblLinkedList<T> _Mylist ;

public:

    void push(T value)
    {
        _Mylist.InsertAtBeginning(value);

    }

    void Print() {
        _Mylist.PrintList();
    }
    
    int Size() {
        return _Mylist.Size();
    }
    
    T Top() {
        if (_Mylist.Size() == 0) {
            throw std::out_of_range("Queue is empty!"); // أو إرجاع قيمة افتراضية
        }
        return _Mylist.GetItem(0);
    }
    
    T Bottom()
    {
      return _Mylist.GetItem(Size() -1);
    }
    
    void pop()
    {
      _Mylist.DeleteFirstNode();
    }
    
    T GetItem(T index)
    {
      return _Mylist.GetItem(index);
    }
    
    void Reverse()
    {
      _Mylist.Reverse();
    }
    
    bool UpdateItem(T index, T NewValue)
    {
      return _Mylist.UpdateItem(index,NewValue);
    }
    
    void InsertAfter(T index, T value)
    {
      _Mylist.InsertAfter(index,value);
    }
    
    void InsertAtFront(T value)
    {
      _Mylist.InsertAtBeginning(value);
    }
    
    void InsertAtBack(T value)
    {
      _Mylist.InsertAtEnd(value);
    }
    
    void Clear()
    {
      
      _Mylist.Clear();
    }
    
    
    

};
