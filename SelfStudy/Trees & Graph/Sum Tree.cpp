/*
 * @File: Sum Tree.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Friday, 2nd October 2020 3:37:01 pm
 * @Last Modified: Friday, 2nd October 2020 3:42:26 pm
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int transform(TreeNode *node)
{
    if (node == NULL)
        return 0;

    int value = node->val;

    node->val = transform(node->left) + transform(node->right);

    return node->val + value;
}
void printInorder(TreeNode *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(-2);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(-4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(5);
    printInorder(root);
    cout << endl;
    transform(root);
    printInorder(root);
    cout << endl;
    return 0;
}