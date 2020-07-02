#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> out;
    void jamereSher(TreeNode *root, int level)
    {
        if (level < out.size())
            out[level].push_back(root->val);
        else
            out.push_back({root->val});
        if (root->left != NULL)
            jamereSher(root->left, level + 1);
        if (root->right != NULL)
            jamereSher(root->right, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        jamereSher(root, 0);
        vector<vector<int>> outout;
        for (int i = out.size() - 1; i >= 0; i--)
            outout.push_back(out[i]);
        return outout;
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution *sol = new Solution();
    vector<vector<int>> out = sol->levelOrderBottom(root);
    for (auto x : out)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}