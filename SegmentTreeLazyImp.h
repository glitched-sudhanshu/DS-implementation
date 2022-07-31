#include <bits/stdc++.h>
using namespace std;

class SegLazyTree
{
    vector<int> seg, lazy;

public:
    SegLazyTree(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<int> arr)
    {
        // putting ith element of array into the segment tree.
        if (low == high)
        {
            seg[idx] = arr[low];
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void update(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
        }

        int mid = (high + low) >> 1;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);

        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int querySum(int idx, int low, int high, int l, int r)
    {

        // if prev lazy is remaining
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];

            // propagating the lazy to its children downwards
            //  for the remaining nodes to get updated
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }

        // for complete overlap
        // l low high r
        if (l <= low && high <= r)
        {
            return seg[idx];
        }
        // no overlap
        // l r low high || low high l r
        if (r < low || high < l)
        {
            return 0;
        }

        // partial overlap
        int mid = (low + high) / 2;
        int left = querySum(2 * idx + 1, low, mid, l, r);
        int right = querySum(2 * idx + 2, mid + 1, high, l, r);

        // seg[idx] = left + right;
        return left + right;
    }
    
};
