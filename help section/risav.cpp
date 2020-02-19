#include<bits/stdc++.h>
using namespace std;
queue<int> q2;

struct node{
int data=NULL;
struct node *left;
struct node *right;
};

//new node
 node* NewNode(int data)
{
struct node* root=new node;
root->data=data;
root->left=NULL;
root->right=NULL;
}
// levelorder
void levelorder(node *root)
{
int tempo=0;
if(root==NULL)
return ;
queue<node *> q;
q.push(root);
while(q.empty()==false)
{
//cout<<"Inside While"<<" ";
node *root=q.front();
tempo=root->data;
::q2.push(tempo);
q.pop();
if(root->left!=NULL)
{
levelorder(root->left);
}
if(root->right!=NULL)
{
levelorder(root->right);
}}
cout<<"Queue After Level Order: ";

while(::q2.empty()!=false)
{
//int temp=;
cout<<::q2.front()<<" ";
::q2.pop();
}
}

//main
int main()
{
struct node * root=NewNode(1);
root->left=NewNode(2);
root->right=NewNode(3);
root->left->left=NewNode(4);
root->left->right=NewNode(5);
cout<<"Traversal Of Binary Tree: ";
levelorder(root);
return 0;
}
