/*
Problem for TRIE
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/cost-of-data-11/description/
*/
#include<bits/stdc++.h>
using namespace std;
int countNodes = 0;
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
			countNodes++;
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
int main(){
	struct trie *root = new trie();
	int n;
	cin>>n;
	string temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		insert(root,temp);
	}
	cout<<countNodes+1;
	return 0;
}
 