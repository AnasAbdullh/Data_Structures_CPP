#pragma once
#include "clsDynamicArray.h"


template <class T>
class clsMyQueueArr {
protected:

    clsDynamicArray <T> MyDynamicArray;
    //int _size = 1;

public:
    void push(T value) {
       /* MyDynamicArray.Resize(Size() +1);
        MyDynamicArray.SetItem(MyDynamicArray.Size() -1,value);*/
        
       MyDynamicArray.InsertAtEnd(value);
    }

    void Print() {
        MyDynamicArray.PrintList();
    }

    int Size() {
        return MyDynamicArray.Size();
    }

    T front() {
        if (MyDynamicArray.Size() == 0) {
            throw std::out_of_range("Queue is empty!"); // أو إرجاع قيمة افتراضية
        }
        return MyDynamicArray.GetItem(0);
    }

    T back() {
        if (MyDynamicArray.Size() == 0) {
            throw std::out_of_range("Queue is empty!"); // أو إرجاع قيمة افتراضية
        }
        return MyDynamicArray.GetItem(Size() - 1);
    }

    void pop() {
        if (MyDynamicArray.Size() == 0) {
            throw std::out_of_range("Queue is empty!"); // أو إرجاع false
        }
        MyDynamicArray.DeleteItemAt(0);
    }
    
    T GetItem(T Item)
    {
      return MyDynamicArray.GetItem(Item);
    }
    
    void Reverse()
    {
      MyDynamicArray.Reverse();
    }
    
    bool UpdateItem(T index, T NewValue)
    {
      return MyDynamicArray.SetItem(index,NewValue);
    }
    
    bool InsertAfter(T index,T value)
    {
     return MyDynamicArray.InsertAfter(index,value);
    }
    
    void InsertAtFront(T value)
    {
      MyDynamicArray.InsertAt(0,value);
    }
    
    void InsertAtBack(T value)
    {
      MyDynamicArray.InsertAtEnd(value);
    }
    
    void Clear()
    {
      MyDynamicArray.Clear();
    }
    
    
};
