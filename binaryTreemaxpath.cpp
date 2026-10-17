
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    int ans;

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    if (n == 0)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    if (a[0] == -1)
        return 0;

    TreeNode *root = new TreeNode(a[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n)
    {
        TreeNode *cur = q.front();
        q.pop();

        if (i < n && a[i] != -1)
        {
            cur->left = new TreeNode(a[i]);
            q.push(cur->left);
        }
        i++;

        if (i < n && a[i] != -1)
        {
            cur->right = new TreeNode(a[i]);
            q.push(cur->right);
        }
        i++;
    }

    Solution sol;
    cout << sol.maxPathSum(root) << '\n';

    return 0;
}
