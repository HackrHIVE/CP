/*
 * @File: 4.4.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 15th August 2020 5:38:46 pm
 * @Last Modified: Saturday, 15th August 2020 5:40:12 pm
 */
/*
 * Check Balanced : Implement a function to check if a binary tree is balanced. 
 *                  For the purpose of this question, a balanced tree is defined to be a tree such that 
 *                  the heights of the two subtrees of any node never differ by more than one.
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
static bool unbalanced = false;
int calculateHeight(Node *node)
{
    if (unbalanced)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 0;
    int left, right = 0;
    if (node->left != NULL)
        left = calculateHeight(node->left);
    if (node->right != NULL)
        right = calculateHeight(node->right);
    if (abs(right - left) > 1)
        unbalanced = true;
    return max(left, right) + 1;
}
int main()
{
    int rootData;
    cin >> rootData;
    Node *root = new Node(rootData);
    queue<Node *> q;
    q.push(root);
    int left, right;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cin >> left;
        cin >> right;
        if (left != -1)
        {
            front->left = new Node(left);
            q.push(front->left);
        }
        if (right != -1)
        {
            front->right = new Node(right);
            q.push(front->right);
        }
    }
    calculateHeight(root);
    if (unbalanced)
        cout << "Binary Tree is unbalanced\n";
    else
        cout << "Binary Tree is balanced\n";
    return 0;
}