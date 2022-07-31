#include<iostream>
#include"circularLinkedList.h"

int main(){
    linkedList l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);
    l.push_back(5);
    l.push_back(4);
    l.insert(6,3);
    l.remove(3);

    Node* head = l.begin();
    Node* temp = head;

    do{
        cout << temp->getData() << "  ->  ";
        temp = temp ->getNext();
    }while(temp != head);
    
    cout << temp->getData() << "  ->  ";

    return 0;
}