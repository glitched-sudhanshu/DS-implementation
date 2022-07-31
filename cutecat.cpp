#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;

    Node(char data)
    {
        this->data = data;
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                Node *node = new Node(ch);
                temp->m[ch] = node;
            }
            temp = temp->m[ch];
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
};

void search_helper(Trie t, string doc, int s, unordered_map<string, bool> &mp)
{
    Node *temp = t.root;
    for (int i = s; doc[i] != '\0'; i++)
    {
        char ch = doc[i];
        if (temp->m.count(ch) == 0)
            return;
        temp = temp->m[ch];
        if (temp->isTerminal)
        {
            string passed = doc.substr(s, s - i + 1);
            mp[passed] = true;
        }
    }
    return;
}

vector<string> doc_search(string doc, vector<string> words)
{
    Trie t;

    // 1. Building trie
    for (int i = 0; i < words.size(); i++)
    {
        t.insert(words[i]);
    }

    unordered_map<string, bool> m;

    for (int i = 0; doc[i] != '\0'; i++)
    {
        search_helper(t, doc, i, m);
    }

    vector<string> res;

    for (int i = 0; i < words.size(); i++)
    {
        if (m[words[i]])
            cout << "yes    ";
        else
            cout << "sf ";
    }
    return res;
}

int main()
{
    string document = "little cute cat love to code in c++, java & python";
    vector<string> words = {"ttle", "cute cat", "cat", "cutest", "quite", "big"};

    vector<string> ans = doc_search(document, words);
    for (int i = 0; i < words.size(); i++)
    {
        cout << ans[i] << "\t";
    }
    return 0;
}