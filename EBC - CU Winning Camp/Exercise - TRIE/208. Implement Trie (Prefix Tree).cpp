/*
Problem for TRIE
https://leetcode.com/problems/implement-trie-prefix-tree/
*/
struct trie{
	struct trie *child[26];
	bool terminate;
    // bool isContinue;
	trie(){
		terminate = false;
		// isContinue = false;
		for(int i=0;i<26;i++) child[i] = NULL;
	}
};

class Trie {
public:
    /** Initialize your data structure here. */
    struct trie *root;
    Trie() {
        root = new trie();
    }
    void insertX(struct trie *root,string str){
        int location ;
        struct trie *ptr;
        ptr = root;
        for(int i=0;i<str.length();i++){
            location = str[i]-97;
            if(ptr->child[location] == NULL){
                struct trie *nodenode = new trie();
                ptr->child[location] = nodenode;
                // if(i+1 != str.length()) ptr->isContinue = true;
            }
            ptr = ptr->child[location];
        }
        ptr->terminate = true;
    }
    bool searchX(struct trie *root,string str){
        int index = str[0]-97;

        if(str.length() == 0 ) return root->terminate;

        if(root->child[index] != NULL) return searchX(root->child[index],str.substr(1,str.length()));

        return false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertX(root,word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchX(root,word);
    }
    
    bool startsWithX(struct trie *root,string str){
        int index = str[0]-97;

        // if(str.length() == 0 ) return root->isContinue;
        if(str.length() == 0 ) return true;

        if(root->child[index] != NULL) return startsWithX(root->child[index],str.substr(1,str.length()));

        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithX(root,prefix);
    }
};