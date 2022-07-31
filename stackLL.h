#include <iostream>
using namespace std;

template <typename T>
class Stack;

template <typename T>
class Node
{

public:
    T data;
    Node<T> *next;
    Node(T d)
    {
        data = d;
    }

};

template <typename T>
class Stack
{
    Node<T> *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(T data)
    {
        Node<T> *n = new Node<T>(data);
        n->next = head;
        head = n;
    }

    bool pop()
    {
        if (head != NULL)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        return false;
    }

    T top()
    {
        Node<T>* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            T tempvar =  temp->data;
            temp = temp -> next;
            //return tempvar;
        }
        
    };
};