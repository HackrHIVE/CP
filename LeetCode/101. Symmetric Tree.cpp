/*
 * @File: 101. Symmetric Tree.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 8th September 2020 11:29:31 pm
 * @Last Modified: Wednesday, 9th September 2020 10:13:42 am
 */
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
    bool inorder(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL || left->val != right->val)
            return false;

        return inorder(left->left, right->right) && inorder(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL || root->left == root->right)
            return true;
        return inorder(root->left, root->right);
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << sol->isSymmetric(root) << endl;
    return 0;
}