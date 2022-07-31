#include <iostream>
#include <math.h>
#include "stackLL.h"
using namespace std;

int postfixEval(string s)
{
    Stack<int> S;
    int i = 0;
    while (s[i] != '\0')
    {
        if(s[i]>=48 && s[i]<=57){
            S.push(s[i]-'0');
        }
        else{
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();
            switch (s[i])
            {
            case '+':
                S.push(a + b);
                break;
            case '-':
                S.push(b - a);
                break;
            case '/':
                S.push(b / a);
                break;
            case '*':
                S.push(b*a);
                break;
            case '^':
                S.push(pow(b,a));
                break;
            default:
                break;
            }
        }
        i++;
    }
    return S.top();
}

int main()
{
    Stack<char> S;

    int choice;

    do
    {
        cout << "\nEnter your choice:\n1. Push\n2. Pop\n3. Print\n(Press any key to exit)\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter element:\n";
            char data;
            cin >> data;
            S.push(data);
            break;
        case 2:
            if (S.pop())
            {
                cout << "\nDeleting element...\n";

                cout << "\nElement deleted\n";
            }
            else
            {
                cout << "\nPhele kuch daalo to\n";
            }
            break;
        case 3:
            cout << "\n----Stack----\n";
            S.top();
            break;

        default:
            break;
        }
    } while (choice >= 1 && choice <= 3);
    // string s = "823^/23*";
    // cout << postfixEval(s);

    return 0;
}