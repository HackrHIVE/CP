#include <iostream>
#include <queue>
using namespace std;
struct Node{
  Node *left,*right;
  int data;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};
class Handler{
  public:
  Node *root;
  queue <Node *> ZigZagQueue;
  Handler(){
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
  }

  void ZigZagOrderQueue(Node *node){
      //Not Right
      bool leftRight = false;
      ZigZagQueue.push(node);
      while(!ZigZagQueue.empty()){
	      Node *temp = ZigZagQueue.front();
          cout<<ZigZagQueue.front()->data<<" ";
          if(leftRight){
            if(temp->left!=NULL) ZigZagQueue.push(temp->left);
            if(temp->right!=NULL) ZigZagQueue.push(temp->right);
          }
          else{
            if(temp->right!=NULL) ZigZagQueue.push(temp->right);
            if(temp->left!=NULL) ZigZagQueue.push(temp->left);
          }
          leftRight = !leftRight;
          ZigZagQueue.pop();
      }
  }
};

int main() {
  Handler *x = new Handler();
  x->ZigZagOrderQueue(x->root);
  return 0;
}