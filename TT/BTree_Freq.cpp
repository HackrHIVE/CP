#include<iostream>
#include<map>
#include<utility>  
using namespace std;
map<int,int> mappy;
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
void trav(Node *root){
    if(root==NULL) return;

    trav(root->left);
    if(mappy.find(root->data)!=mappy.end()){
        mappy[root->data]++;
    }else{
        mappy.insert(make_pair(root->data,1));
    }
    trav(root->right);

}
int main(){
    Node *root = new Node(50);
    root->left = new Node(20);
    root->left->left = new Node(20);
    root->left->right = new Node(70);
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    trav(root);
    map<int,int>::iterator it = mappy.begin();
    while(it!=mappy.end()){
        cout<<it->first<<" -> "<<it->second<<endl;
        it++;
    }
    return 0;
}
