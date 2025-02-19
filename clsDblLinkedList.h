#pragma once

#include <iostream>


template <class T> class clsDblLinkedList {

protected:
    int _size = 0;

public:
    class Node {
    public:
        T value;
        Node *next;
        Node *prev;
    };

    Node *head = nullptr;

    Node *Find(T value) {
        Node *copyHead = head;
        while (copyHead != NULL) {

            if (copyHead->value == value) {
                return copyHead;
            }

            copyHead = copyHead->next;
        }

        return nullptr;
    }

    void InsertAtBeginning(T value) {

        Node *newNode = new Node();

        newNode->value = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
        ++_size;
    }

    void PrintNodeDetails(Node *node) {
        if (node->prev != nullptr) {
            std::cout << node->prev->value;
        } else {
            std::cout << "NULL";
        }

        std::cout << " <--> " << node->value << " <--> ";

        if (node->next != nullptr) {
            std::cout << node->next->value << std::endl;
        } else {
            std::cout << "NULL" << std::endl;
        }
    }

    void PrintListDetails() {
        Node *copyHead = head;
        std::cout << "\n\n";
        while (copyHead != nullptr) {
            PrintNodeDetails(copyHead);
            copyHead = copyHead->next;
        }
        std::cout << "\n\n";
    }

/*    void PrintList() {
        Node *copyHead = head;
        std::cout << "NULL <--> ";
        while (copyHead != nullptr) {
            std::cout << copyHead->value << " <--> ";
            copyHead = copyHead->next;
        }
        std::cout << "NULL" << std::endl;
    }*/
    
    void PrintList() {
        Node *copyHead = head;
        while (copyHead != nullptr) {
            std::cout << copyHead->value << "  ";
            copyHead = copyHead->next;
        }
        
        std::cout << std::endl;
    }
   
    

    void InsertAfter(Node *current, T value) {

        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current
           node. 3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it
           exists).
        */

        if (current == nullptr) {
            return;
        }

        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        ++_size;
    }

    bool InsertAfter(T index, T value) {
        auto ItemNode = GetNode(index);
        if(ItemNode){
          InsertAfter(ItemNode,value);
          _size++;
          return true;
        }
        return false;
    }

    void InsertAtEnd(T value) {

        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */

        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;

            ++_size;
        }
    }

    void InsertAtEnd(Node *&Current, T value) {

        Node *newNode = new Node();
        newNode->value = value;
        Current->next = nullptr;
        if (Current == nullptr) {
            Current->prev = nullptr;
            Current = newNode;

        } else {

            auto LastNode = head;
            while (LastNode->next != nullptr) {
                LastNode = LastNode->next;
            }

            LastNode->next = newNode;
            newNode->prev = LastNode;

            ++_size;
        }
    }

    void DeleteNode(Node *&head, T value) {
        if (head == nullptr) {
            return;
        }

        if (head->value == value) {
            Node *temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            --_size;
            return;
        }

        Node *Current = head;
        Node *Prev = nullptr;

        while (Current != nullptr && Current->value != value) {
            Prev = Current;
            Current = Current->next;
        }

        if (Current == nullptr) {
            return;
        }

        Prev->next = Current->next;
        if (Current->next != nullptr) {
            Current->next->prev = Prev;
        }

        --_size;

        delete Current;
    }

    void DeleteNode(Node *&NodeToDelete) {
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }

        --_size;
        delete NodeToDelete;
    }

    void DeleteFirstNode() {
    // إذا كانت القائمة فارغة، لا يوجد شيء نحذفه
    if (head == nullptr) {
        return;
    }

    // إذا كانت القائمة تحتوي على أكثر من عقدة
    if (head->next != nullptr) {
        // 
        auto temp = head;
        head = head->next;
        head->prev = nullptr; // تعيين الـ prev للرأس الجديد إلى nullptr
        delete temp;
    } else {
     delete head; 
     head = nullptr;
    }

    // تقليص الحجم
    --_size;

    // حذف العقدة القديمة
    //delete temp;
    
    }

    /*void DeleteLastNode() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) { // ✅ إذا كانت العقدة الوحيدة
            delete head;
            head = nullptr;
            --_size;
            return;
        }

        Node *LastNode = head;

        while (LastNode->next != nullptr) { // ✅ العثور على آخر عقدة
            LastNode = LastNode->next;
        }
        
        LastNode->prev->next = nullptr;

        --_size;

        delete LastNode;
    }*/
    
    void DeleteLastNode() {
    if (head == nullptr) return;

    if (head->next == nullptr) { // إذا كانت هناك عقدة واحدة فقط
        delete head;
        head = nullptr;
        _size = 0; // تأكد من تعيين الحجم إلى 0 هنا!
        return;
    }

    Node* LastNode = head;
    while (LastNode->next != nullptr) {
        LastNode = LastNode->next;
    }

    LastNode->prev->next = nullptr;
    delete LastNode;
    _size--;  // تقليل الحجم
    }
    int Size() {
        return _size;
    }

    // bool IsEmpty() { return (head == nullptr); }
    bool IsEmpty() {
        return (_size == 0);
    }

    
    void Clear() {
    while (_size > 0) {
       // std::cout << "Deleting node, size before deletion: " << _size << std::endl;
        DeleteLastNode();
    }
    //std::cout << "All nodes deleted, size: " << _size << std::endl;
   }

    void Reverse() {

        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            return;
        }

        auto Current = head;
        Node *Temp = nullptr;

        while (Current != nullptr) {

            Temp = Current->prev;
            Current->prev = Current->next;
            Current->next = Temp;
            head = Current;
            Current = Current->prev;
        }
    }

    Node *GetNode(T index) {

        if (index >= _size || index < 0)
            return nullptr;

        auto Current = head;

        for (int i = 0; i < index; i++) {
            Current = Current->next;
        }
        return Current;
    }

    T GetItem(T value) {
        auto ItemNode = GetNode(value);
        return ItemNode ? ItemNode->value : T{};
    }

    bool UpdateItem(T index, T NewValue) {
        auto ItemUpdate = GetNode(index);
        if (ItemUpdate) {
            ItemUpdate->value = NewValue;
            return true;
        }
        return false;
    }
    
    
};
