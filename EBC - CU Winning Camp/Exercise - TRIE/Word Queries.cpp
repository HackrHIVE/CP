#include<bits/stdc++.h>
using namespace std;
struct TRIE{
	struct TRIE *child[26];
	bool terminate;
	int count;
	TRIE(){
		count = 0;
		terminate = false;
		for(int i=0;i<26;i++) child[i] = NULL;
	}
};
void insert(TRIE *root,string str){
	// char x = '!';
	for(int i=0;i<str.length();i++){

		if(root->child[str[i]-97] == NULL){
			root->child[str[i]-97] = new TRIE();
		}
		root->count++;
		// x = str[i];
		root = root->child[str[i]-97];
	}
	root->count++;
	root->terminate = true;
}
int check(TRIE *root,string str){
	int i=0;
	// char x = '!';
	for(i=0;i<str.length();i++){
		if(i+1 == str.length()){
			return root->child[str[i]-97]->count;
		}
		// x = str[i];
		if(root->child[str[i]-97] != NULL){
			root = root->child[str[i]-97];
		}
		else break;
	}
	return 0;
}
int main(){
	int n,q;
	cin>>n>>q;
	string temp;
	struct TRIE *root = new TRIE();
	while(n--){
		cin>>temp;
		insert(root,temp);
	}
	while(q--){
		cin>>temp;
		cout<<check(root,temp)<<endl;
	}
	return 0;
}