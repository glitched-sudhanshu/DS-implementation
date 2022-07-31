#include <iostream>
using namespace std;

class linkedList;

class Node
{
    int data;
    Node* next;

public:
    Node(int d) : data(d), next(NULL) {}

    int getData(){
        return data;
    }

    Node* getNext(){
        return next;
    }

    friend class linkedList;
};

class linkedList
{
    Node* head;
    Node* tail;

public:
    linkedList() : head(NULL), tail(NULL) {}

    Node* begin(){
        return head;
    }

    Node* end(){
        return tail;
    }

    void push_front(int data)
    {
        if (head == NULL)
        {
            Node *n = new Node(data);
            head = tail =  n;
            n->next=head;
        }
        else
        {
            Node *n = new Node(data);
            tail->next=n;
            n->next = head;
            head = n;
        }
    }

    void push_back(int data){
        if (head == NULL)
        {
            Node * n = new Node(data);
            head = tail = n;
            n->next=head;
        }
        else{
            Node *n = new Node(data);
            tail->next = n;
            n->next = head;
            tail = n;
        }
    }

    void insert(int data, int pos){
        if(pos == 0){
            push_front(data);
            return;
        }
        int jumps = pos-1;
        Node *temp = head;
        while(jumps--){
            temp = temp->next;
        }
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    void pop_front(){
        Node *temp = head;
        head = head->next;
        tail->next=head;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        
        temp->next = NULL;
        delete tail;
        tail = temp;
        tail->next=head;
    }

    void remove(int pos){
        if(pos == 0){
            pop_front();
            return;
        }
        else{
            Node *temp = head;
            for(int jumps = 1; (jumps <= pos-1) && (temp!=NULL); jumps++){
                temp = temp->next;
            }
            if(temp == NULL){
                cout << "Index out of bounds";
                return;
            }
            Node *to_remove = temp -> next;
            if(to_remove->next == head){
                pop_back();
                return;
            }
            temp->next = to_remove->next;
            to_remove->next = NULL;
            delete to_remove; 
        }
    }

    void reverse(Node* &head){
        Node* prev = NULL;
        Node* current = head;
        Node* temp;

        while(current != NULL){
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
    }
};
