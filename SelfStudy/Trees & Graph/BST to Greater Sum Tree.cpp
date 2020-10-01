/*
 * @File: BST to Greater Sum Tree.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 1st October 2020 5:57:30 pm
 * @Last Modified: Thursday, 1st October 2020 6:13:17 pm
 */
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void printTree(Node *node)
{
    if (node == NULL)
        return;
    printTree(node->left);
    cout << node->data << " ";
    printTree(node->right);
}
void transform(Node *node, int &sum)
{
    if (node == NULL)
        return;
    transform(node->right, sum);
    sum += node->data;
    node->data = sum - node->data;
    transform(node->left, sum);
}
int main()
{
    Node *root = new Node(11);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right = new Node(29);
    root->right->left = new Node(15);
    root->right->right = new Node(40);
    root->right->right->left = new Node(35);
    printTree(root);
    cout << endl;
    int sum = 0;
    transform(root, sum);
    printTree(root);
    cout << endl;
    return 0;
}