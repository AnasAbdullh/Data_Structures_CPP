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

    if(head != nullptr)
    {
        head->prev = newNode;
    }

    head = newNode;

}

Node * Find(Node * head,int value)
{

    while(head != nullptr)
    {

        if(head ->value == value)
        {
            return head;
        }

        head = head ->next;

    }
    return nullptr;
}

void PrintNodeDetails(Node* head)
{

    if(head->prev != nullptr)
    {
        cout << head->prev->value ;
    } else {
        cout << "NULL";
    }

    cout << " <--> " << head->value << " <--> ";

    if(head->next != nullptr)
    {
        cout << head->next->value << endl;
    } else {
        cout << "NULL";
    }


}

void InsertAfter(Node * head,int value)
{
    auto AfterNode= Find(head,value);
    auto new_node = new Node();

    new_node->value = 4;
    new_node->next = AfterNode->next;
    new_node->prev = AfterNode;

    if(AfterNode->next != nullptr) {
        AfterNode->next->prev = new_node;
    }
    
    AfterNode->next = new_node;

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }
    cout << "\n\n";
}


// Print the linked list
void PrintList(Node* head)

{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";

}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);
    InsertAfter(head,5);
    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    //PrintListDetails(head);


}