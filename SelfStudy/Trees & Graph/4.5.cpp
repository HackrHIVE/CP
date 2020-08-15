/*
 * @File: 4.5.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 15th August 2020 6:08:03 pm
 * @Last Modified: Saturday, 15th August 2020 6:21:16 pm
 */
/*
 * Validate BST : Implement a function to check if a binary tree is a binary search tree.
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorder(Node *node, vector<int> &inO)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        inO.push_back(node->data);
        return;
    }
    inorder(node->left, inO);
    inO.push_back(node->data);
    inorder(node->right, inO);
}
int main()
{
    int rootD;
    cin >> rootD;
    Node *root = new Node(rootD);
    queue<Node *> q;
    q.push(root);
    int l, r;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cin >> l >> r;
        if (l != -1)
        {
            front->left = new Node(l);
            q.push(front->left);
        }
        if (r != -1)
        {
            front->right = new Node(r);
            q.push(front->right);
        }
    }
    vector<int> inO;
    inorder(root, inO);
    vector<int> sorted = inO;
    sort(sorted.begin(), sorted.end());
    int i = 0;
    for (i = 0; i < inO.size(); i++)
    {
        if (inO[i] == sorted[i])
            continue;
        else
            break;
    }
    if (i == inO.size())
        cout << "Given Binary Tree is a BST\n";
    else
        cout << "Given Binary Tree is not a BST\n";
    return 0;
}