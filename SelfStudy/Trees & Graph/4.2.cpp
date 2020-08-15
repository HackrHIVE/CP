/*
 * @File: 4.2.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 13th August 2020 11:45:05 pm
 * @Last Modified: Saturday, 15th August 2020 2:25:36 pm
 */
/*
 * Minimal Treee : Given a sorted(increasing order) array with unique integer elements, 
 *                 write an algorithm to create a binary search tree with minimal height.
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left, *right;
    int data;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *createBSTfromArray(int *arr, int lo, int hi)
{
    if (lo > hi)
        return NULL;
    int mid = lo + (hi - lo) / 2;
    Node *node = new Node(arr[mid]);
    node->left = createBSTfromArray(arr, lo, mid - 1);
    node->right = createBSTfromArray(arr, mid + 1, hi);
    return node;
}
void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *root = createBSTfromArray(arr, 0, n - 1);
    cout << "BST Created.\n";
    inorder(root);
    cout << endl;
    delete[] arr;
    return 0;
}