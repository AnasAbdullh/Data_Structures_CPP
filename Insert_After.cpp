#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node* next;
};

Node * Find(Node * head,int value)
{
    while(head != NULL)
    {

        if(head -> value == value)
        {
            return head;
        }

        head = head->next;
    }

    return NULL;

}

void insertAfter(Node * prv,int value)
{
    Node * new_node = new Node();
    new_node ->value = value;
    new_node ->next = prv->next;
    prv->next = new_node;
}

void InsertAtBeginning(Node* &head, int value)
{

    // Allocate memory to a node
    Node * new_node = new Node();

    // insert the data
    new_node->value = value;
    new_node->next = head;

    // Move head to new node
    head = new_node;
}

// Print the linked list
void PrintList(Node* head)
{
    while (head != NULL) {
        cout << head->value << endl;
        head = head->next;
    }
}

int main()
{
    Node * head = NULL;

    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);

    //PrintList(head);

    Node * found = Find(head,2);

    insertAfter(found,30);

    PrintList(head);


    // system("read");

}
