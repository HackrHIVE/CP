#include <iostream>
#include <queue>
#include <stack>
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
  stack <int> preO;
  stack <int> postO;
  queue <Node *> levelQueue;
  queue <int> parentsList1;
  queue <int> parentsList2;
  bool flag = false;
  Handler(){
  	root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(10);
    root->left->right = new Node(5);
    root->left->right->left = new Node(11);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
//    root = new Node(1);
//    root->left = new Node(2);
//    root->right = new Node(3);
//    root->left->left = new Node(4);
//    root->left->right = new Node(5); 
  }

  void PreOrderStack(Node *node){
      if(node==NULL) return;

      PreOrderStack(node->right);
      PreOrderStack(node->left);

      preO.push(node->data);

      if(node==root){
          while(!preO.empty()){
              cout<<preO.top()<<" ";
              preO.pop();
          }
      }
  }
  
  void PostOrderStack(Node *node){
      if(node==NULL) return;

      postO.push(node->data);

      PostOrderStack(node->right);
      PostOrderStack(node->left);

      if(node==root){
          while(!postO.empty()){
              cout<<postO.top()<<" ";
              postO.pop();
          }
      }
  }

  void InOrderStack(Node *node){
      
      stack <Node *> inO;
      while(node!=NULL || !inO.empty()){
      	
        while(node!=NULL){
        	inO.push(node);
//        	if(node->left==NULL)break;
        	node = node->left;
        }
        node = inO.top();
        inO.pop();
        cout<<node->data<<" ";
        node = node->right;
        
      }
      
  }

  void LevelOrderStack(Node *node){
      levelQueue.push(node);
      while(!levelQueue.empty()){
	      Node *temp = levelQueue.front();
          cout<<levelQueue.front()->data<<" ";
          if(temp->left!=NULL) levelQueue.push(temp->left);
          if(temp->right!=NULL) levelQueue.push(temp->right);
          levelQueue.pop();
      }
  }

  void PreOrder(Node *node){
    if(node == NULL) return;
    cout<<node->data<<" ";
    PreOrder(node->left);
    PreOrder(node->right);
  }
  void PostOrder(Node *node){
    if(node == NULL) return;
    PreOrder(node->left);
    PreOrder(node->right);
    cout<<node->data<<" ";
  }

  bool FindParent(Node *node,Node *f){
    if(node == NULL) return false;

    if(node == f) return true;

    if(FindParent(node->left, f)) {
      (flag) ? parentsList1.push(node->data) : parentsList2.push(node->data);
      cout<<node->data<<" ";
      return true;
    } 
    if(FindParent(node->right,f)) {
      (flag) ? parentsList1.push(node->data) : parentsList2.push(node->data);
      cout<<node->data<<" ";
      return true;
    } 
    return false;
  }
  void InOrder(Node *node){
    if(node == NULL) return;
    PreOrder(node->left);
    cout<<node->data<<" ";
    PreOrder(node->right);
  }
};

int main() {
  Handler *x = new Handler();
  cout<<"PreOrder : ";
  x->PreOrder(x->root);
  cout<<"\nPostOrder : ";
  x->PostOrder(x->root);
  cout<<"\nInOrder : ";
  x->InOrder(x->root);
  cout<<endl;
  x->FindParent(x->root,x->root->left->left);
  cout<<endl<<"PreOrder using Stack : \n";
  x->PreOrderStack(x->root);
  cout<<endl<<"PostOrder using Stack : \n";
  x->PostOrderStack(x->root);
  cout<<endl<<"InOrder using Stack : \n";
  x->InOrderStack(x->root);
  cout<<"\nLevelOrder using Stack : \n";
  x->LevelOrderStack(x->root);
  return 0;
}
