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
  vector< vector<int> > levelO;
  Handler(){
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
  }

  void LevelOrder(Node *node,int level){

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
};

int main() {
  Handler *x = new Handler();
  x->LevelOrder(x->root,0);
  cout<<"Level Order : ";
  x->printLevelOrder();
  return 0;
}