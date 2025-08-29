#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// using recursion purely.
int eggdrops(int n, int k)
{
    if (k == 0 || k == 1 || n == 1)
        return k;

    int res = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        int cur = 1 + max(eggdrops(n - 1, i - 1), eggdrops(n, k - i));

        if (cur < res)
            res = cur;
    }

    return res;
}

// using recursion with memorization.
int memeggdrops(int n, int k, vector<vector<int>> &myvec)
{
    if (myvec[n][k] != -1)
        return myvec[n][k];

    if (k == 0 || k == 1 || n == 1)
        return k;

    int res = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        myvec[n][k] = 1 + max(eggdrops(n - 1, i - 1), eggdrops(n, k - i));

        if (myvec[n][k] < res)
            res = myvec[n][k];
    }

    return res;
}

// using dynamic programming.
int dpeggdrops(int n, int k)
{
    vector<vector<int>> myvec(n + 1, vector<int>(k + 1, 0));

    for (int col = 1; col <= k; col++)
        myvec[1][col] = col;

    for (int row = 1; row <= n; row++)
        myvec[row][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            myvec[i][j] = INT_MAX;

            for (int x = 1; x <= j; x++)
            {
                int res = 1 + max(myvec[i - 1][x - 1], myvec[i][j - x]);

                if (res < myvec[i][j])
                    myvec[i][j] = res;
            }
        }
    }

    return myvec[n][k];
}

int main()
{
    // cout << eggdrops(2, 100) << "\n";

    // vector<vector<int>> myvec(2 + 1, vector<int>(10 + 1, -1));
    // cout << memeggdrops(2, 10, myvec) << "\n";

    cout << dpeggdrops(2, 100) << "\n";
}