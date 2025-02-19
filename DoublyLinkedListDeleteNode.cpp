#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node* next;
    Node* prev;
};

void InsertAtBeginning(Node*& head, int value) {


    /*
        1-Create a new node with the desired value.
        2-Set the next pointer of the new node to the current head of the list.
        3-Set the previous pointer of the current head to the new node.
        4-Set the new node as the new head of the list.
    */

    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

Node* Find(Node* head, int Value)
{

    while (head != nullptr) {

        if (head->value == Value)
            return head;


        head = head->next;
    }

    return nullptr;


}

void InsertAfter(Node* current, int value) {


    /*  1 - Create a new node with the desired value.
         2-Set the next pointer of the new node to the next node of the current node.
         3-Set the previous pointer of the new node to the current node.
         4-Set the next pointer of the current node to the new node.
         5-Set the previous pointer of the next node to the new node(if it exists).
    */

    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}


void PrintNodeDetails(Node* head)
{

    if (head->prev != nullptr)
        cout << head->prev->value;
    else
        cout << "nullptr";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != nullptr)
        cout << head->next->value << "\n";
    else
        cout << "nullptr";

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != nullptr) {
        PrintNodeDetails(head);
        head = head->next;
    }
}


// Print the linked list
/*void PrintList(Node* head)

{
    cout << "nullptr <--> ";
    while (head != nullptr) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "nullptr";

}*/

void PrintList(Node* head)
{
    cout << "\n";
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << "\n";
}

void DeleteNode(Node*& head, int value)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->value == value)
    {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    Node* Current = head;
    Node* Prev = nullptr;

    while (Current != nullptr && Current->value != value)
    {
        Prev = Current;
        Current = Current->next;
    }

    if (Current == nullptr)
    {
        return;
    }

    Prev->next = Current->next;
    if (Current->next != nullptr) {
        Current->next->prev = Prev;
    }

    delete Current;
}

void InsertEnd(Node * &head,int value)
{

    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;
    if(head == nullptr)
    {
        newNode->prev = nullptr;
        head = newNode;

    } else {

        auto LastNode = head;
        while(LastNode->next != nullptr)
        {
            LastNode = LastNode->next;
        }

        LastNode->next = newNode;
        newNode->prev = LastNode;

    }

}


void DeleteNode(Node*& head, Node*& NodeToDelete) {
    

    /*
        1-Set the next pointer of the previous node to the next pointer of the current node.
        2-Set the previous pointer of the next node to the previous pointer of the current node.
        3-Delete the current node.
    */
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
    delete NodeToDelete;
}


int main()
{
    Node* head = nullptr;

    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 0);
    InsertEnd(head,50);


    PrintList(head);
    DeleteNode(head,3);
    PrintList(head);


    cout << endl;

}
