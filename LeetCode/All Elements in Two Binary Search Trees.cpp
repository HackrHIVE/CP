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
    void traverseTree(TreeNode *node, vector<int> &list)
    {
        if (node == NULL)
            return;
        traverseTree(node->left, list);
        list.push_back(node->val);
        traverseTree(node->right, list);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> list1;
        vector<int> list2;
        traverseTree(root1, list1);
        traverseTree(root2, list2);
        cout << "List1 : ";
        printArr(list1);
        cout << "List2 : ";
        printArr(list2);
        /*
        vector<int> v;
        v.insert(v.begin(), list1.begin(), list1.end());
        v.insert(v.end(), list2.begin(), list2.end());
        sort(v.begin(), v.end());
        return v;
        */
        vector<int> v;
        int i = 0, j = 0;
        while (i < list1.size() && j < list2.size())
        {
            if (list1[i] < list2[j])
                v.push_back(list1[i++]);
            else
                v.push_back(list2[j++]);
        }
        while (i < list1.size())
            v.push_back(list1[i++]);
        while (j < list2.size())
            v.push_back(list2[j++]);
        return v;
    }
    void printArr(vector<int> &arr)
    {
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }
};
int main()
{
    Solution *sol = new Solution();
    TreeNode *root1, *root2;
    root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    vector<int> out = sol->getAllElements(root1, root2);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}