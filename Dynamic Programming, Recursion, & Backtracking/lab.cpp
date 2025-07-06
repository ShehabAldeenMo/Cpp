#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// using recursion function
int LCS(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    if (m == 0 || n == 0)
        return 0;
    else if (s1.at(m - 1) == s2.at(n - 1))
    {
        return (1 + LCS(s1.substr(0, m - 1), s2.substr(0, n - 1)));
    }
    else if (s1.at(m - 1) != s2.at(n - 1))
    {
        return max(LCS(s1, s2.substr(0, n - 1)), LCS(s1.substr(0, m - 1), s2));
    }
}

// using recursion with dynamic programming.
vector<vector<int>> dp;
bool init_flag = false;

void Init(int m, int n, int def = -1)
{
    dp.clear(); // Important: Clear the DP table for fresh computation

    for (int i = 0; i <= m; i++)
    {
        vector<int> v(n + 1, def);
        dp.push_back(v);
    }
}

int DP_LCS(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    if (m == 0 || n == 0)
        dp[m][n] = 0;

    if (!init_flag)
    {
        init_flag = true;
        Init(m, n);
    }

    if (dp[m][n] != -1)
        return dp[m][n];

    if (s1.at(m - 1) == s2.at(n - 1))
    {
        dp[m][n] = (1 + DP_LCS(s1.substr(0, m - 1), s2.substr(0, n - 1)));
    }
    else if (s1.at(m - 1) != s2.at(n - 1))
    {
        dp[m][n] = max(DP_LCS(s1, s2.substr(0, n - 1)), DP_LCS(s1.substr(0, m - 1), s2));
    }

    return dp[m][n];
}

// using dynamic programming fully.
int DP_LowerToUpper(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    Init(m, n, 0);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1.at(i - 1) == s2.at(j - 1))
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[m][n];
}

int main()
{
    cout << "LCS: " << LCS("aab", "azb") << "\n";
    cout << "LCS: " << DP_LCS("aab", "azb") << "\n";
    cout << "LCS: " << DP_LowerToUpper("aab", "azb") << "\n";
}