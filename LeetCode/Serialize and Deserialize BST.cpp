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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string out = "";
        if (root == NULL)
            return out;
        queue<TreeNode *> q;
        queue<int> vals;
        vals.push(root->val);
        q.push(root);
        while (!vals.empty())
        {
            int frontVal = vals.front();
            vals.pop();
            if (out.size() != 0)
                out += ",";
            out += to_string(frontVal);
            while (frontVal == -1 && !vals.empty())
            {
                frontVal = vals.front();
                out += "," + to_string(frontVal);
                vals.pop();
            }
            if (q.empty())
                break;
            TreeNode *front = q.front();
            q.pop();
            if (front->left)
            {
                q.push(front->left);
                vals.push(front->left->val);
            }
            else
                vals.push(-1);
            if (front->right)
            {
                q.push(front->right);
                vals.push(front->right->val);
            }
            else
                vals.push(-1);
        }
        return out;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return NULL;
        vector<int> levelOrder;
        stringstream tekenizer(data);
        string temp;
        while (getline(tekenizer, temp, ','))
            levelOrder.push_back(stoi(temp));
        for (auto x : levelOrder)
            cout << x << " ";
        cout << endl;
        queue<TreeNode *> vals;
        int val = levelOrder[0];
        TreeNode *root = new TreeNode(val);
        vals.push(root);
        int index = 0;
        while (!vals.empty())
        {
            TreeNode *front = vals.front();
            vals.pop();
            if (index == vals.size() - 1)
                break;
            int leftVal = levelOrder[++index];
            if (leftVal != -1)
            {
                //Left Node is Non NULL
                front->left = new TreeNode(leftVal);
                vals.push(front->left);
            }
            if (index == vals.size() - 1)
                break;
            int rightVal = levelOrder[++index];
            if (rightVal != -1)
            {
                //Right Node is Non NULL
                front->right = new TreeNode(rightVal);
                vals.push(front->right);
            }
        }
        return root;
    }
};
void printTree(TreeNode *node)
{
    if (node)
    {
        printTree(node->left);
        cout << node->val << " ";
        printTree(node->right);
    }
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    printTree(root);
    cout << endl;
    Codec *ser = new Codec();
    Codec *deser = new Codec();
    string tree = ser->serialize(root);
    cout << "Serialized BST into String ==> " << tree << endl;
    TreeNode *ans = deser->deserialize(tree);
    printTree(ans);
    cout << endl;
    return 0;
}