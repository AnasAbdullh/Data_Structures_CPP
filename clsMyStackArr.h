#include "clsMyQueueArr.h"


template <class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
  
public:
  void push(T value) 
  {
    clsMyQueueArr<T>::MyDynamicArray.InsertAtBeginning(value);
  }
  
  T Top()
  {
   return clsMyQueueArr<T>::front();
  }
  
  T Bottom()
  {
    return clsMyQueueArr<T>::back();
  }
  
  
  
};
