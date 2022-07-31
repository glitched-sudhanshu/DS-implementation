#include <bits/stdc++.h>
#include "SegmentTreeImp.h"
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 5};
    int n = 3;
    SegTree segt(n);
    segt.build(arr, 0, 0, n - 1);
    cout << segt.queryMin(arr, 0, 0, n - 1, 0, 2);
    segt.update(arr, 0, 0, n - 1, 1, 2);
    cout << segt.queryMin(arr, 0, 0, n - 1, 0, 2);
}

