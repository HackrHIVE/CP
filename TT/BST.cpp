#include<iostream>
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
class NodeHelper{
    public:
    Node *root;
    int count = 0;
    NodeHelper(){
        root = NULL;
    }
    Node* insertNode(Node* node,int data){
        if(node==NULL){
            count++;
            return new Node(data);
        }

        if(data < node->data) node->left = insertNode(node->left,data);
        else if(data > node->data) node->right = insertNode(node->right,data);
        
        return node;
    }
    Node* createBSTfromArray(int* arr,int size,int l,int r){
        if(l<=r){
            int mid = (l+r)/2;
            Node* node = new Node(arr[mid]);
            node->left = createBSTfromArray(arr,size,l,mid-1);
            node->right = createBSTfromArray(arr,size,mid+1,r);
            return node;
        }
        return NULL;
    }
    void inorder(Node *root){
        if(root==NULL) return;
    
        if(root->left==NULL && root->right==NULL){
            cout<<root->data<<endl;
            return;
        }

        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
};
int main(){
    Node *root = NULL;
    NodeHelper *object = new NodeHelper();
    root = object->insertNode(root,50);
    object->insertNode(root,30);
    object->insertNode(root,20);
    object->insertNode(root,70);
    object->insertNode(root,80);
    object->inorder(root);
    int arry[5] = {20,30,50,70,80};
    int *arr = new int[object->count];
    Node *bst = object->createBSTfromArray(arry,object->count,0,object->count-1);
    object->inorder(bst);
    return 0;
}
