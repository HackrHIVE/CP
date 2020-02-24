#include<iostream>
#include<algorithm>
using namespace std;
int count = 0;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* *arr;
Node* *sorted;
int index = 0;
int calculateNodes(Node *root){
    if(root==NULL) return 0;
    
    if(root->left==NULL && root->right==NULL) return 1;

    return 1+calculateNodes(root->left)+calculateNodes(root->right);
}
bool comp(Node* x,Node* y){
    return x->data<y->data;
}
void inorder(Node *root){
    
    if(root==NULL) return;
 
    if(root->left==NULL && root->right==NULL){
        arr[index++] = root;
        sorted[index-1] = root;
        return;
    }

    inorder(root->left);
    arr[index++] = root;
    sorted[index-1] = root;
    inorder(root->right);

}
int main(){
	/*
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    */
    /**/
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
    /**/
    int size = calculateNodes(root);
    cout<<"No. of nodes -> "<<size<<endl;
    arr = new Node*[size];
    sorted = new Node*[size];
    inorder(root);
    sort(sorted,sorted+size,comp);
    bool notSoBST = false;
    for(int i=0;i<size;i++){
        if(arr[i]->data == sorted[i]->data) continue;

        notSoBST = true;
        break;
    }
	if(notSoBST) cout<<"Binary Tree provided is not a BST";
	else cout<<"Binary Tree provided is a BST";
    return 0;
}
