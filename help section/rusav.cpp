#include<bits/stdc++.h>
using namespace std;
struct node {
int data=NULL;
struct node *left;
struct node *right;
};
//Function For New Node
node * newNode(int data)
{
node * root = new node;
root->data=data;
root->left=NULL;
root->right=NULL;
return root;
}
//tree creation
node *treecreation(int ar[],int l,int r)
{
if(l>r)
return NULL;
else
{
int mid=(l+r)/2;
node * root=newNode(ar[mid]);
root->left=treecreation(ar,l,mid-1);
root->right=treecreation(ar,mid+1,r);
}
}
//levelorderfunction
void levelorder(node * root)
{
if(root==NULL)
return;
queue<node *>q;
q.push(root);
while(q.empty()==false)
{
node *root=q.front();
cout<<root->data<<" ";
q.pop();
if(root->left!=NULL)
{
q.push(root->left);
}
if(root->right!=NULL)
{
q.push(root->right);
}
}
}
//main function
int main()
{
int ar[]={1,2,3,4,5,6,7};
int n= sizeof(ar)/sizeof(ar[0]);
int l=0;
int r=n-1;
struct node* root=treecreation(ar,l,r);
levelorder(root);
}
