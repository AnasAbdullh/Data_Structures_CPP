#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node* next;
};

void InsertAtBeginning(Node*& head, int value)
{
    // Allocate memory to a node
    Node* new_node = new Node();

    // insert the data
    new_node->value = value;
    new_node->next = head;

    // Move head to new node
    head = new_node;

}

Node *Find(Node* head, int Value)
{

    while (head != NULL) {

        if (head->value == Value)
            return head;


        head = head->next;
    }

    return NULL;

}

// Insert a node after a node
void InsertAfter(Node* prev_node, int Value) {

    if (prev_node == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->value = Value;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Insert at the end
void InsertAtEnd(Node*& head, int value)
{
    auto new_node = new Node();
    new_node->value = value;
    new_node->next = nullptr;

    if (head == nullptr) {
        head = new_node;
    } else {
        auto LastNode = head;
        while (LastNode->next != nullptr) {
            LastNode = LastNode->next;
        }
        LastNode->next = new_node;
    }
}

// Print the linked list
void PrintList(Node* head)
{
    cout << "\n";
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    Node * head = nullptr;

    InsertAtEnd(head,1);
    InsertAtEnd(head,2);
    InsertAtEnd(head,3);


    PrintList(head);


}