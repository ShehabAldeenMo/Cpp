
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    void backtracking(int openN, int closeN, int n, vector<string> &res, string &str)
    {
        if (openN == closeN && openN == n)
        {
            res.push_back(str);
            return;
        }

        if (openN < n)
        {
            str += "(";
            backtracking(openN + 1, closeN, n, res, str);
            str.pop_back();
        }

        if (closeN < openN)
        {
            str += ")";
            backtracking(openN, closeN + 1, n, res, str);
            str.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string str;
        backtracking(0, 0, n, res, str);
        return res;
    }
};

int main()
{
    Solution sol;
    sol.generateParenthesis(3);
}
