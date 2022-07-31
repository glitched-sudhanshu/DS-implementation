#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node
{
public:
    string key;
    T val;
    Node<T> *next;

    Node(string key, T val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    // recurrsive destructor to delete the entire row
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class HashTable
{
    Node<T> **table;
    int cs; // number of buckets utilized
    int ts; // total number of buckets

    hashFn(string key)
    {
        int power = 1;
        int idx = 0;

        for (char ch : key)
        {
            idx = (idx + power * ch) % ts;
            power = (power * 29) % ts;
        }
        return idx;
    }

    void rehash()
    {
        // cout << "here";
        Node<T> **old_table = table;
        cs = 0;
        int os = ts;
        ts = 2 * ts + 1;
        table = new Node<T> *[ts]; // ideally it should be a prime number
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }

        // copy elements to new table
        for (int i = 0; i < os; i++)
        {
            Node<T> *temp = old_table[i];
            while (temp != NULL)
            {
                string key = temp->key;
                T val = temp->val;
                // happens in the new table
                insert(key, val);
                temp = temp->next;
            }

            if (old_table[i] != NULL)
                delete old_table[i];
        }

        delete[] old_table;
        return;
    }

public:
    HashTable(int default_size = 7)
    {
        cs = 0;
        ts = default_size;
        table = new Node<T> *[ts];
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T val)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, val);

        // insertion at the head of the Linked list
        // make sure that this operation reamins O(1)
        n->next = table[idx];
        table[idx] = n;

        cs++;

        float load_factor = cs / float(ts);

        if (load_factor > 0.7)
        {
            rehash();
        }
    }

    bool isPresent(string key)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    T* search(string key)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                cout << &(temp->val) << endl
                ;
                return &(temp->val);
            }
            temp = temp->next;
        }
        return NULL;
    }

    void erase(string key)
    {
        if (isPresent(key))
        {
            int idx = hashFn(key);
            Node<T> *dummy = new Node<T>("Temp", INT_MIN);
            dummy->next = table[idx];
            Node<T> *temp = dummy;
            while (temp != NULL)
            {
                if (temp->next->key == key)
                {
                    Node<T> *del = temp->next;
                    temp->next = del->next;
                    delete del;
                    table[idx] = temp->next;
                    return;
                    // delete dummy;
                }
                temp = temp->next;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket " << i << " -> ";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // returning a memory by reference
    T &operator[](string key)
    {
        // return the value
        // if key is not found then create a new node and return
        // return the existing node

        T *valueFound = search(key);
        if (valueFound == NULL)
        {
            T object;
            insert(key, object);
            valueFound = search(key);
        }
        return *valueFound;
    }
};