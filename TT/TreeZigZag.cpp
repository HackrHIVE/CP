/*
 * @File: TreeZigZag.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Monday, 20th July 2020 8:54:30 pm
 * @Last Modified: Thursday, 1st October 2020 11:04:54 pm
 */
#include <iostream>
#include <stack>
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
class Handler
{
public:
  Node *root;
  Handler()
  {
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right = new Node(5);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
  }

  void ZigZagOrderQueue(bool otherWay)
  {
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
      while (!s1.empty())
      {
        Node *temp = s1.top();
        if (!otherWay)
          cout << " -> ";
        if (otherWay)
          cout << " <- ";
        cout << temp->data;
        s1.pop();
        if (otherWay)
          if (temp->right != NULL)
            s2.push(temp->right);
        if (temp->left != NULL)
          s2.push(temp->left);
        if (!otherWay)
          if (temp->right != NULL)
            s2.push(temp->right);
      }
      cout << endl;
      while (!s2.empty())
      {
        Node *temp = s2.top();
        if (!otherWay)
          cout << " <- ";
        if (otherWay)
          cout << " -> ";
        cout << temp->data;
        s2.pop();
        if (otherWay)
          if (temp->left != NULL)
            s1.push(temp->left);
        if (temp->right != NULL)
          s1.push(temp->right);
        if (!otherWay)
          if (temp->left != NULL)
            s1.push(temp->left);
      }
      cout << endl;
    }
  }
};

int main()
{
  Handler *x = new Handler();
  //There are two ways to start ZigZagTraversal
  //1. At root Level : Right to Left
  //2. At root Level : Left to Right
  bool otherWay = true;
  x->ZigZagOrderQueue(otherWay);
  cout << endl;
  x->ZigZagOrderQueue(!otherWay);
  return 0;
}