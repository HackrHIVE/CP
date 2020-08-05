#include <bits/stdc++.h>
using namespace std;
struct trie
{
    struct trie *child[26];
    bool terminate;
    trie()
    {
        terminate = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
class WordDictionary
{
public:
    /** Initialize your data structure here. */
    struct trie *root;
    WordDictionary()
    {
        root = new trie();
    }

    void insertX(struct trie *root, string str)
    {
        int location;
        struct trie *ptr;
        ptr = root;
        for (int i = 0; i < str.length(); i++)
        {
            location = str[i] - 97;
            if (ptr->child[location] == NULL)
            {
                struct trie *nodenode = new trie();
                ptr->child[location] = nodenode;
            }
            ptr = ptr->child[location];
        }
        ptr->terminate = true;
    }
    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        insertX(root, word);
    }

    bool searchX(struct trie *root, string str)
    {
        if (str.length() == 1)
        {
            if (str[0] == '.')
            {
                bool out = false;
                for (int i = 0; i < 26; i++)
                    if (root->child[i] != NULL)
                        out |= root->child[i]->terminate;
                    else if (out)
                        return true;
                return out;
            }
            else
            {
                if (root->child[str[0] - 97] != NULL)
                    return root->child[str[0] - 97]->terminate;
                return false;
            }
        }
        else if (str[0] == '.')
        {
            bool out = false;
            for (int i = 0; i < 26; i++)
            {
                if (root->child[i] != NULL)
                {
                    out |= searchX(root->child[i], str.substr(1, str.length()));
                    if (out)
                        return true;
                }
            }
            return out;
        }
        else
        {
            int index = str[0] - 97;

            if (root->child[index] != NULL)
                return searchX(root->child[index], str.substr(1, str.length()));
        }
        return false;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return searchX(root, word);
    }
};
int main()
{
    WordDictionary *obj = new WordDictionary();
    obj->addWord("at");
    obj->addWord("and");
    obj->addWord("an");
    obj->addWord("add");
    cout << obj->search("a") << endl;
    cout << obj->search(".at") << endl;
    obj->addWord("bat");
    cout << obj->search(".at") << endl;
    cout << obj->search("an.") << endl;
    cout << obj->search("a.d.") << endl;
    cout << obj->search("b.") << endl;
    cout << obj->search("a.d") << endl;
    cout << obj->search(".") << endl;
    return 0;
}