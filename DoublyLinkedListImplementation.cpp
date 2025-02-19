#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node* next;
    Node * prve;
};

void InsertAtBeginning(Node * &head,int value)
{

    auto new_node = new Node();
    
    new_node->head;
    new_node->nullptr;
    head->prve = new_node;
    
}

// Print the linked list
void PrintList(Node* head)
{

    while (head != nullptr) {
        cout << head->value << endl;
        head = head->next;
    }

}

int main()
{

    Node * Node1 = nullptr;
    Node * Node2 = nullptr;
    Node * Node3 = nullptr;

    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    Node1->value = 1;
    Node2->value = 2;
    Node3->value = 3;

    Node1->next = Node2;
    Node1->prve = nullptr;

    Node2->next = Node3;
    Node2->prve = Node1;

    Node3->next = nullptr;
    Node3->prve = Node2;


    PrintList(Node1);

}
