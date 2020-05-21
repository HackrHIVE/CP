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
    Node* createBSTfromArray(int* arr,int l,int r){
        if(l<=r){
            int mid = (l+r)/2;
            Node* node = new Node(arr[mid]);
            node->left = createBSTfromArray(arr,l,mid-1);
            node->right = createBSTfromArray(arr,mid+1,r);
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
    int closestToTarget(int target,Node *node){
        int closest = node->data;
        int diff = closest-target;
        if(diff>0) node = node->left;
        else if(diff<0) node = node->right;
        else return node->data;
        while(node!=NULL){
            if(abs(target-closest)>abs(node->data-target)){
                closest = node->data;
                diff = closest-target;
                if(diff == 0) return closest;
                if(diff>0) node = node->left;
                else node = node->right;
            }
            else{
                if(node->data>target) node = node->left;
                else node = node->right;
            }
        }
        return closest;
    }
};
int main(){
//    Node *root = NULL;
    NodeHelper *object = new NodeHelper();
//    root = object->insertNode(root,50);
//    object->insertNode(root,30);
//    object->insertNode(root,20);
//    object->insertNode(root,70);
//    object->insertNode(root,80);
//    object->inorder(root);
    int arry[5] = {10,9,13,15,16};
    int n = sizeof(arry)/sizeof(arry[0]); 
    Node *bst = object->createBSTfromArray(arry,0,n);
//    object->inorder(bst);
    cout<<"Closest to 12"<<" is "<<object->closestToTarget(12,bst);
    return 0;
}
