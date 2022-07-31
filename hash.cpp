#include <bits/stdc++.h>
#include "hashmap.h"
using namespace std;

int main()
{
    HashTable<int> h;
    h.insert("apple", 1);
    h.insert("mango", 2);
    h.insert("litchi", 3);
    h.insert("guava", 4);
    h.insert("kiwi", 5);
    h.insert("banana", 6);
    h.insert("papaya", 7);
    h.insert("orange", 9);

    int *sVal = h.search("dasf");
    cout << *(sVal) << endl;

    h.print();
}