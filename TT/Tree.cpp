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
  queue <int> parentsList1;
  queue <int> parentsList2;
  vector< vector<int> > levelO;
  bool flag = false;
  Handler(){
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
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

  void LevelOrder(Node *node,int level){
//  	cout<<"LevelOrder() : "<<node->data<<"\tlevel : "<<level<<endl;
//      if(node==NULL) return;

      if(level>=levelO.size()){
          vector<int> temp;
          temp.push_back(node->data); 
          levelO.push_back(temp);
      }
      else{
          vector<int> temp = levelO[level];
          temp.push_back(node->data); 
          levelO[level] = temp;
      }
      
      if(node->left!=NULL) LevelOrder(node->left,level+1);
      if(node->right!=NULL) LevelOrder(node->right,level+1);
  }

  void printLevelOrder(){
      for(int i=0;i<levelO.size();i++){
          for(int j=0;j<levelO[i].size();j++) cout<<levelO[i][j]<<" ";
      }
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
//  cout<<"PreOrder : ";
//  x->PreOrder(x->root);
//  cout<<"\nPostOrder : ";
//  x->PostOrder(x->root);
//  cout<<"\nInOrder : ";
//  x->InOrder(x->root);
  cout<<endl;
//  x->FindParent(x->root,x->root->left->left);
  x->LevelOrder(x->root,0);
  cout<<endl<<"Level Order : ";
  x->printLevelOrder();
  return 0;
}
