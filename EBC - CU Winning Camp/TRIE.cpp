#include<bits/stdc++.h>
using namespace std;
struct trie{
	struct trie *child[26];
	bool terminate;
	trie(){
		terminate = false;
		for(int i=0;i<26;i++) child[i] = NULL;
	}
};
void insert(struct trie *root,string str){
	int location ;
	struct trie *ptr;
	ptr = root;
	for(int i=0;i<str.length();i++){
		location = str[i]-97;
		if(ptr->child[location] == NULL){
			struct trie *nodenode = new trie();
			ptr->child[location] = nodenode;
		}
		ptr = ptr->child[location];
	}
	ptr->terminate = true;
}
bool search(struct trie *root,string str){
	int index = str[0]-97;
	
	if(str.length() == 0 ) return root->terminate;
	
	if(root->child[index] != NULL) return search(root->child[index],str.substr(1,str.length()));
	
	return false;
}
int searchAdv(struct trie *root,string str){
	int index = str[0]-97;
	
	if(str.length() == 0 && root->terminate) return 1;
	
	if(root->child[index] != NULL) return 1+searchAdv(root->child[index],str.substr(1,str.length()));
	
	return 0;
}
int main(){
	struct trie *root = new trie();
	insert(root,"search");
	insert(root,"searchx");
	string str;
	cin>>str;
	cout<<"Whether search is there or nor : "<<search(root,"search")<<endl;
	int end = searchAdv(root,str);
	cout<<"How much of "<<str<<" is hit in trie : "<<str.substr(0,end)<<endl;
	cout<<"Whether searchx is there or nor : "<<search(root,"searchx")<<endl;
	return 0;
}

