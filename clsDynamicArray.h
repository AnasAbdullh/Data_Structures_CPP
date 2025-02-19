#pragma once

template <class T> class clsDynamicArray {
private:
        T _Size = 0;
public:


    T *_arr = new T[_Size];

    clsDynamicArray(T Size = 0) {
        if (Size < 0) {
            Size = 0;
        }
        _Size = Size;
    }

    ~clsDynamicArray() {
        delete[] _arr;
    }

    bool SetItem(T index, T value) {
        if (index >= _Size || index < 0) {
            return false;
        }
        _arr[index] = value;
        return true;
    }

    bool IsEmpty() {
        return (_Size == 0);
    }

    T Size() {
        return _Size;
    }

    void Resize(int value) {
        T *NewArr = new T[value];

        int limit = (value < _Size) ? value : _Size;

        for (int i = 0; i < limit; i++) {
            NewArr[i] = _arr[i];
        }

        delete[] _arr;
        _arr = NewArr;
        NewArr = nullptr;

        _Size = value;
    }

    void PrintList() {
        for (T i = 0; i < _Size; i++) {
            std::cout << _arr[i] << "  ";
        }
        std::cout << std::endl;
    }

    T GetItem(T index) {
        return _arr[index];
    }

    void Reverse() {

        for (int i = 0; i < _Size / 2; i++) {
            std::swap(_arr[i], _arr[_Size - i - 1]);
        }
    }

    void Clear() {
        delete[] _arr;
        _arr = nullptr;
        _Size = 0;
    }

    bool DeleteItemAt(T index) {

        if (index < 0 || index >= _Size) {
            return false;
        }
        T *Temp = new T[_Size - 1];
        int j = 0;
        for (int i = 0; i < _Size; i++) {
            if (i != index) {
                Temp[j] = _arr[i];
                j++;
            }
        }

        delete[] _arr;
        _arr = Temp;
        Temp = nullptr;
        _Size--;
        return true;
    }

    bool DeleteFirstItem() {
        return DeleteItemAt(0);
    }

    bool DeleteLastItem() {
        return DeleteItemAt(_Size - 1);
    }

    T Find(T value) {
        for (int i = 0; i < _Size; i++) {
            if (_arr[i] == value)
                return i;
        }

        return -1;
    }

    bool DeleteItem(T value) {
        return DeleteItemAt(Find(value));
    }

    bool InsertAt(T index, T value) 
    {
    if (index < 0 || index > _Size) {
        return false;
    }

    T * Temp = new T[_Size + 1];
    
    for(int i = 0 ; i < index; i++) {
        Temp[i] = _arr[i];
    }
    
    //0 10  1 20  2 30  3 40  4 50

    //std::cout << "Index: " << index << ", Current Size: " << _Size << std::endl;

    Temp[index] = value;

    for(int i = index ;i < _Size; i++) {
        Temp[i+1] = _arr[i];
    }

    delete[] _arr;
    _arr = Temp;
    
    _Size++;
    //std::cout << "New Size after insertion: " << _Size << std::endl;
    return true;
    }
    
    bool InsertAtBeginning(T value)
    {
      return InsertAt(0,value);
    }
    
    bool InsertBefore(T index,T value)
    { 
      if(index < 1) return InsertAt(0,value);
      return InsertAt(index -1,value);
    }
    
    bool InsertAfter(T index,T value)
    {
      if(index >= _Size)
      {
        std::cout << _Size << std::endl;
        return InsertAt(_Size -1,value);
      }
      return InsertAt(index + 1,value);
    }
    
    bool InsertAtEnd(T value)
    {
      //std::cout << _Size << std::endl; // = 5
      return InsertAt(_Size,value);
    }
};
