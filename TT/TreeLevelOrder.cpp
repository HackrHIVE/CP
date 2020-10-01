#include <iostream>
#include <queue>
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
  queue<Node *> levelQueue;
  Handler()
  {
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
  }

  void LevelOrderQueue(Node *node)
  {
    levelQueue.push(node);
    while (!levelQueue.empty())
    {
      Node *temp = levelQueue.front();
      cout << levelQueue.front()->data << " ";
      if (temp->left != NULL)
        levelQueue.push(temp->left);
      if (temp->right != NULL)
        levelQueue.push(temp->right);
      levelQueue.pop();
    }
  }
};

int main()
{
  Handler *x = new Handler();
  x->LevelOrderQueue(x->root);
  return 0;
}