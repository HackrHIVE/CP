/*
 * @File: 257. Binary Tree Paths.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Friday, 2nd October 2020 1:29:48 pm
 * @Last Modified: Friday, 2nd October 2020 1:32:00 pm
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
    void possiblePaths(TreeNode *node, string path, vector<string> &out)
    {
        if (node == NULL)
            return;
        path += "->" + to_string(node->val);
        if (node->left == NULL && node->right == NULL)
        {
            out.push_back(path);
            return;
        }
        if (node->left != NULL)
            possiblePaths(node->left, path, out);
        if (node->right != NULL)
            possiblePaths(node->right, path, out);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> out;
        if (root == NULL)
            return out;
        string path = to_string(root->val);
        possiblePaths(root->left, path, out);
        possiblePaths(root->right, path, out);
        if (out.size() == 0)
            out.push_back(path);
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    vector<string> out = sol->binaryTreePaths(root);
    for (auto x : out)
        cout << x << endl;
    return 0;
}