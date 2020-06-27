#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x) { data = x; };
};
Node *createBSTfromArray(vector<int> &arr, int lo, int hi)
{
    if (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        Node *node = new Node(arr[mid]);
        node->left = createBSTfromArray(arr, lo, mid - 1);
        node->right = createBSTfromArray(arr, mid + 1, hi);
        return node;
    }
    return NULL;
}
void createArrayfromBST(Node *root)
{
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(12);
    root->right->right = new Node(13);
    root->right->left = new Node(11);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    cout << "PreOrder : ";
    preorder(root);
    cout << endl;
    cout << "InOrder : ";
    inorder(root);
    cout << endl;
    cout << "PostOrder : ";
    postorder(root);
    cout << endl;
    vector<int> arr = {1, 3, 5, 7, 10};
    Node *root1 = createBSTfromArray(arr, 0, arr.size() - 1);
    inorder(root1);
    cout << endl;
    return 0;
}