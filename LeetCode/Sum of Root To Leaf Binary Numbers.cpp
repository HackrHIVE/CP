/*
 * @File: Sum of Root To Leaf Binary Numbers.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 8th September 2020 5:49:12 pm
 * @Last Modified: Wednesday, 9th September 2020 10:15:09 am
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
    unsigned long out = 0;

public:
    void visitNodes(TreeNode *node, string path)
    {
        node->val == 1 ? path.append("1") : path.append("0");
        if (node->left == NULL && node->right == NULL)
        {
            unsigned long n = std::bitset<31>(path).to_ulong();
            out += n;
            return;
        }
        if (node->left != NULL)
            visitNodes(node->left, path);
        if (node->right != NULL)
            visitNodes(node->right, path);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        visitNodes(root, "");
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    cout << sol->sumRootToLeaf(root) << endl;
    return 0;
}