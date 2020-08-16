/*
 * @File: 4.6.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 15th August 2020 9:15:27 pm
 * @Last Modified: Saturday, 15th August 2020 10:01:05 pm
 */
/*
 * Successor : Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. 
 *             You may assume that each node has a link to its parent.
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right, *parent;
    Node(int data, Node *node)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->parent = node;
    }
};
Node *findSuccessor(Node *node)
{
    if (node->right == NULL)
    {
        Node *temp = node->parent;
        while (temp->right == node)
        {
            node = temp;
            temp = node->parent;
        }
        return temp;
    }
    Node *temp = node->right;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}
int main()
{
    int l, r;
    cin >> l;
    Node *root = new Node(l, NULL);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        cin >> l >> r;
        Node *front = q.front();
        q.pop();
        if (l != -1)
        {
            front->left = new Node(l, front);
            q.push(front->left);
        }
        if (r != -1)
        {
            front->right = new Node(r, front);
            q.push(front->right);
        }
    }
    Node *out = findSuccessor(root->left->right->right);
    cout << "In-Order successor to " << root->left->right->right->data << " is " << out->data << endl;
    return 0;
}