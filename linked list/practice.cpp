#include <iostream>
// #include "list.h"
using namespace std;
class Node
{

    int data;

public:
    Node *Next;
    Node(int d) : data(d), Next(NULL) {}
    int getdata() { return data; }
    friend class List;
};

// th list is created using node class
// Node class here is used to store the data and the next pointer
class List
{

    Node *Head;
    Node *Tail;

public:
    List() : Head(NULL), Tail(NULL) {}

    // to start with the list we need accese to the header file
    Node *begin()
    {
        return Head;
    }

    // Push front function is used to push the data at the front side of the linked list
    void Push_front(int data)
    {
        if (Head == NULL)
        {
            Node *n = new Node(data);
            Head = Tail = n;
            return;
        }
        else
        {
            Node *n = new Node(data);
            n->Next = Head;
            Head = n;
        }
    }

    // used to push the data at the end of the linked list
    void Push_back(int data)
    {
        Node *n = new Node(data);
        if (Head == NULL)
        {
            Head = Tail = n;
            return;
        }
        else
        {
            Tail->Next = n;
            Tail = n;
        }
    }
    // To insert the element in the middile somewhere in the linked list
    void Insert(int data, int pos)
    {
        Node *n = new Node(data);
        if (pos == 0)
        {
            Push_front(data);
            return;
        }
        else
        {
            Node *temp = Head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->Next;
            }
            n->Next = temp->Next;
            temp->Next = n;
        }
    }
    void remove(int pos)
    {
        if (pos == 0)
        {
            Node *temp = Head;
            Head = Head->Next;
            delete temp;
            return;
        }
        else
        {
            Node *temp = Head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->Next;
            }
            Node *todelete = temp->Next;
            temp->Next = temp->Next->Next;
            delete todelete;
        }
    }
};

// to check the list.h file off the folder tried print in main

int main()
{

    List l;
    l.Push_back(10);
    l.Push_back(20);
    l.Push_front(30);

    /* while (head != NULL)
     {
         cout << head->getdata() << "->";
         head = head->Next;
     }
     */
    Node *head = l.begin();
    l.Insert(4, 2);
    l.remove(2);
    while (head != NULL)
    {
        cout << head->getdata() << "->";
        head = head->Next;
    }

    return 0;
}