/*
 * @File: 111. Minimum Depth of Binary Tree.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 9th September 2020 3:38:20 pm
 * @Last Modified: Wednesday, 9th September 2020 8:37:39 pm
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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        int left = INT_MAX;
        int right = INT_MAX;
        if (root->left != NULL)
            left = minDepth(root->left);
        if (root->right != NULL)
            right = minDepth(root->right);
        return min(left, right) + 1;
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
    cout << sol->minDepth(root) << endl;
    return 0;
}