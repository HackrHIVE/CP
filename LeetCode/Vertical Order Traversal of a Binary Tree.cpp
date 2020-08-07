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
    int left = 0;
    int right = 0;
    unordered_map<int, vector<pair<int, int>>> umap;
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);
        vector<vector<int>> out;
        for (int i = left; i <= right; i++)
        {
            if (umap.find(i) != umap.end())
            {
                sort(umap[i].begin(), umap[i].end(), sortMyWay);
                vector<int> temp;
                for (auto x : umap[i])
                    temp.push_back(x.first);
                out.push_back(temp);
            }
        }
        return out;
    }
    static bool sortMyWay(pair<int, int> x, pair<int, int> y)
    {
        if (x.second < y.second)
            return true;
        else if (x.second == y.second)
            return x.first < y.first;
        return false;
    }
    void dfs(TreeNode *root, int vLevel, int hLevel)
    {
        if (root == NULL)
            return;
        umap[vLevel].push_back({root->val, hLevel++});
        if (left > vLevel)
            left = vLevel;
        if (right < vLevel)
            right = vLevel;
        dfs(root->left, vLevel - 1, hLevel);
        dfs(root->right, vLevel + 1, hLevel);
    }
};
int main()
{
    Solution *sol = new Solution();
    /*TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(8);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->left->right = new TreeNode(4);
    root->right->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->left->left = new TreeNode(6);*/
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(9);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(2);
    root->right->left->right = new TreeNode(3);
    root->right->left->right->left = new TreeNode(4);
    root->right->left->right->left->left = new TreeNode(6);
    root->right->left->right->left->left->left = new TreeNode(7);
    root->right->left->right->right = new TreeNode(8);
    vector<vector<int>> out = sol->verticalTraversal(root);
    for (auto x : out)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}