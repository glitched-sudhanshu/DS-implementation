#include <iostream>
#include "linkedList.h"
using namespace std;

int main(){

    linkedList l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);
    l1.push_front(5);
    
    Node* head = l1.begin();
    while(head != NULL){
        cout << head->getData() << " -> ";
        head = head->getNext();
    }

    cout << endl;

    head = l1.begin();
    l1.reverse(head);

    // Node* head_new = l1.begin();
    // while(head_new != NULL){
    //     cout << head_new->getData() << " -> ";
    //     head_new = head_new->getNext();
    // }

    return 0;
}