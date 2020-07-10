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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode *, int>> q;
        int nq;
        unsigned int res = 0, left;
        pair<TreeNode *, unsigned int> p;

        q.push({root, (unsigned int)0});
        while (!q.empty())
        {
            nq = q.size();
            left = -1;
            for (int i = 0; i < nq; i++)
            {
                p = q.front();
                q.pop();
                if (p.first == nullptr)
                    continue;
                if (left == -1)
                    left = p.second;
                res = max(res, p.second - left + 1);
                q.push({p.first->left, p.second * 2});
                q.push({p.first->right, p.second * 2 + 1});
            }
        }
        return (int)res;
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(7);
    cout << sol->widthOfBinaryTree(root) << endl;
    return 0;
}