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
    bool possible(TreeNode *node, int sum, int target)
    {
        sum += node->val;

        if (node->left != NULL)
            if (possible(node->left, sum, target))
                return true;
        if (node->right != NULL)
            if (possible(node->right, sum, target))
                return true;

        if (sum == target)
            return node->left == NULL && node->right == NULL;

        return false;
    }
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        return possible(root, 0, sum);
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    cout << sol->hasPathSum(root, 22) << endl;
    return 0;
}