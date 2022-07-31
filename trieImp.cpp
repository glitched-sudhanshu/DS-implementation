#include<bits/stdc++.h>
#include "trie.h"
using namespace std;

int main()
{
    string words[] = {"hello", "apple", "she", "app"};
    Trie t;
    for(auto w : words)
    {
        t.insert(w);
    }

    t.remove("apple");
    for(int i=0; i<4; i++)
    {
        cout << t.search(words[i]) << endl;
    }
    return 0;
}