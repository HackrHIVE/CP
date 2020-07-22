#include <bits/stdc++.h> 
#include <unordered_map>
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
    unordered_map<int, vector<int> > umap;
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        helper(root, 0);

        vector<vector<int> > out = {};
        int size = umap.size();
        for (int key = 0; key < size; key++)
        {
            vector<int> temp = umap[key];
            if (key % 2 == 0)
                out.push_back(temp);
            else
            {
                vector<int> pmet;
                for(int i = temp.size()-1;i>=0;i--) pmet.push_back(temp[i]);
                out.push_back(pmet);
            }
        }
        return out;
    }
    void helper(TreeNode *root, int level)
    {
        if (root == NULL)
            return;
        umap[level].push_back(root->val);
        level++;
        helper(root->left, level);
        helper(root->right, level);
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
    vector<vector<int> > out = sol->zigzagLevelOrder(root);
    for (auto x : out)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}