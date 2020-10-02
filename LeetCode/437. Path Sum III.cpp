/*
 * @File: 437. Path Sum III.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Friday, 2nd October 2020 3:04:17 pm
 * @Last Modified: Friday, 2nd October 2020 3:05:51 pm
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
    void visit(TreeNode *node, int &target, int sum, int &total)
    {
        if (sum == target)
            total++;
        if (node->left)
            visit(node->left, target, sum + node->left->val, total);
        if (node->right)
            visit(node->right, target, sum + node->right->val, total);
    }
    void visitAllNodes(TreeNode *node, int &target, int &total)
    {
        if (node)
        {
            visit(node, target, node->val, total);
            visitAllNodes(node->left, target, total);
            visitAllNodes(node->right, target, total);
        }
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        int out = 0;
        visitAllNodes(root, sum, out);
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    cout << sol->pathSum(root, 3) << endl;
    return 0;
}