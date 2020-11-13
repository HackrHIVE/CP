#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    Node *connect(Node *root)
    {
        int current = 1;
        int level = 0;
        if (root == NULL)
            return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (current == 1)
            {
                front->next = NULL;
                current = pow(2, ++level);
            }
            else
            {
                front->next = q.front();
                current--;
            }
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
        return root;
    }
};
int main()
{
    Solution *sol = new Solution();
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *out = sol->connect(root);
    return 0;
}