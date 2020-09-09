/*
 * @File: 110. Balanced Binary Tree.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 9th September 2020 2:11:47 pm
 * @Last Modified: Wednesday, 9th September 2020 2:29:13 pm
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
private:
    bool trigger = false;

public:
    int getHeight(TreeNode *node)
    {
        if (node->left == NULL && node->right == NULL)
            return 1;
        int leftHeight = 0;
        int rightHeight = 0;
        if (node->left != NULL)
            leftHeight = getHeight(node->left);
        if (node->right != NULL)
            rightHeight = getHeight(node->right);
        if (abs(rightHeight - leftHeight) > 1)
            trigger = true;
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        int left = 0, right = 0;
        if (root->left != NULL)
            left = getHeight(root->left);
        if (root->right != NULL)
            right = getHeight(root->right);
        return abs(left - right) <= 1 && !trigger;
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sol->isBalanced(root) << endl;
    return 0;
}