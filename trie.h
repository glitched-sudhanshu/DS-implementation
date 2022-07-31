#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;

    Node(char data)
    {
        this->data = data;
        isTerminal = false;
    }
};

class Trie{
    Node* root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node* temp = root;
        for(char ch : word)
        {
            if(temp->m.count(ch) == 0)
            {
                Node* node = new Node(ch);
                temp->m[ch] = node;
            }
            temp = temp -> m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node* temp = root;
        for(char ch:word)
        {
            if(temp->m.count(ch) == 0) return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    void suffix_insert(string word)
    {
        for (int i = 0; word[i] != '\0'; i++)
        {
            insert(word.substr(i));
        }
    }
};

