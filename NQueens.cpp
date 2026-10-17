
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = 0;

    void backtrack(int row, int n,
                   vector<bool> &cols,
                   vector<bool> &diag1,
                   vector<bool> &diag2)
    {
        if (row == n)
        {
            ans++;
            return;
        }

        for (int col = 0; col < n; col++)
        {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2])
                continue;

            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            backtrack(row + 1, n, cols, diag1, diag2);

            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

public:
    int totalNQueens(int n)
    {
        ans = 0;

        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, cols, diag1, diag2);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.totalNQueens(n) << '\n';

    return 0;
}
