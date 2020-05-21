#include<iostream>
#include<vector>
using namespace std;
int minHL = 16;
int maxHL = -16;
int adjuster;
struct Node{
    Node *left,*right;
    int data;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
/*
              10
           //     \\
        12          15
      //   \\     //   \\
    17      20  21      22
   //       //  //         \\
19      18    13            25
   \\           \\        //
    21            14   24
*/
void findMinMaxLevel(Node *root,int Level){
    if(root==NULL) return;

    if(Level<::minHL) ::minHL = Level;
    if(Level>::maxHL) ::maxHL = Level;

    if(root->left!=NULL){
        findMinMaxLevel(root->left,Level-1);
    }
    if(root->right!=NULL){
        findMinMaxLevel(root->right,Level+1);
    }
}
void verticalTraversal(Node *root,int Level,vector<int> *arr){
    if(root==NULL) return;
	
    arr[Level+::adjuster].push_back(root->data);
	verticalTraversal(root->left,Level-1,arr);
    verticalTraversal(root->right,Level+1,arr);
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(12);
    root->left->right = new Node(20);
    root->left->right->left = new Node(18);
    root->left->left = new Node(17);
    root->left->left->left = new Node(19);
    root->left->left->left->right = new Node(21);
    root->right = new Node(15);
    root->right->left = new Node(21);
    root->right->left->left = new Node(13);
    root->right->left->left->right = new Node(14);
    root->right->right = new Node(22);
    root->right->right->right = new Node(25);
    root->right->right->right->left = new Node(24);
    findMinMaxLevel(root,0);
    int size = ::maxHL-::minHL;    
    ::adjuster = -::minHL;
    vector<int> *arr = new vector<int>[size+1];
    verticalTraversal(root,0,arr);
    for(int i=0;i<size+1;i++){
        cout<<"Level "<<i-::adjuster<<" : ";
        for(int j=0;j<arr[i].size();j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
