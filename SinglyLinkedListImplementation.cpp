#include <iostream>
using namespace std;

class Node {
public:
    int value = 0;
    Node * Next = nullptr;
};

int main()
{

    Node * Node1 = new Node();
    Node * Node2 = new Node();
    Node * Node3 = new Node();

    Node1->value = 10;
    Node2->value = 20;
    Node3->value = 30;


    Node1->Next = Node2;
    Node2->Next = Node3;
    Node3 = nullptr;

    Node * Head = Node1;


    while (Head != nullptr)
    {
        cout << Head->value << endl;
        Head = Head->Next;
    }




    return 0;
}