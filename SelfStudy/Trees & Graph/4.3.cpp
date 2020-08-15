/*
 * @File: 4.3.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 15th August 2020 2:25:01 pm
 * @Last Modified: Saturday, 15th August 2020 2:25:15 pm
 */
/*
 * List of Depths : Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth 
 *                  (e.q., if you have a tree with depth D, you'll have D linked lists).
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
struct LNode
{
    Node *data;
    LNode *next;
    LNode(Node *data)
    {
        this->data = data;
        this->next = NULL;
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
vector<LNode *> compileListOfLNode(Node *root)
{
    vector<LNode *> out;
    queue<Node *> q;
    if (root != NULL)
        q.push(root);
    int level = 0;
    int size = 0;
    while (!q.empty())
    {
        if (size == 0)
        {
            size = q.size();
            level++;
        }
        Node *front = q.front();
        q.pop();
        if (size > 0)
        {
            if (out.size() < level)
                out.push_back(new LNode(front));
            else
            {
                LNode *tNode = out[level - 1];
                while (tNode->next != NULL)
                    tNode = tNode->next;
                tNode->next = new LNode(front);
            }
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
            size--;
        }
    }
    return out;
}
void printV(vector<LNode *> out)
{
    cout << "Level-wise LinkedList is as : \n";
    for (int i = 0; i < out.size(); i++)
    {
        LNode *x = out[i];
        LNode *temp = x;
        cout << "Level " << i << " ==> [ ";
        while (x != NULL)
        {
            cout << x->data->data << " ";
            x = x->next;
        }
        cout << "]" << endl;
    }
}
int main()
{
    int n;
    cout << "Number of Nodes : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Input inorder of BST : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *root = createBSTfromArray(arr, 0, n - 1);
    cout << "BST Created.\n";
    vector<LNode *> out = compileListOfLNode(root);
    printV(out);
    delete[] arr;
    return 0;
}