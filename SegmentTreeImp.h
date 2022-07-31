#include <bits/stdc++.h>
using namespace std;

class SegTree
{

    vector<int> seg;

public:
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(vector<int> arr, int idx, int low, int high)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(arr, 2 * idx + 1, low, mid);
        build(arr, 2 * idx + 2, mid + 1, high);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int queryMin(vector<int> arr, int idx, int low, int high, int l, int r)
    {
        // no overlap l r low high | low high l r
        if (r < low || high < l)
        {
            return 0;
        }
        // complete overlap l low high r
        else if (l <= low && high <= r)
        {
            return seg[idx];
        }

        int mid = (low + high) / 2;
        int left = queryMin(arr, 2 * idx + 1, low, mid, l, r);
        int right = queryMin(arr, 2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(vector<int> arr, int idx, int low, int high, int i, int val)
    {
        // means position we are at is i
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(arr, 2 * idx + 1, low, mid, i, val);
        else
            update(arr, 2 * idx + 2, mid + 1, high, i, val);

        seg[idx] = seg[2 * idx + 2] + seg[2 * idx + 1];
    }
};