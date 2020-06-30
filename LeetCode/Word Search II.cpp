#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    bool end;
    vector<TrieNode *> children;
    TrieNode()
    {
        end = false;
        children = vector<TrieNode *>(26, NULL);
    }
};
class Trie
{
    TrieNode *root;

public:
    TrieNode *getRoot()
    {
        return root;
    }
    Trie(vector<string> &words)
    {
        root = new TrieNode();
        for (auto x : words)
            addWord(x);
    }
    void addWord(string word)
    {
        TrieNode *current = root;
        for (auto x : word)
        {
            if (current->children[x - 97] == NULL)
                current->children[x - 97] = new TrieNode();
            current = current->children[x - 97];
        }
        current->end = true;
    }
};
class Solution
{
public:
    set<string> words;
    void findWord(vector<vector<char>> &board, TrieNode *root,
                  string word, int row, int col)
    {
        if (row < 0 || col < 0 || col >= board[0].size() || row >= board.size() || board[row][col] == '0')
            return;

        if (root->children[board[row][col] - 97] != NULL)
        {
            word += board[row][col];
            root = root->children[board[row][col] - 97];
            if (root->end)
                words.insert(word);
            char x = board[row][col];
            board[row][col] = '0';
            findWord(board, root, word, row + 1, col);
            findWord(board, root, word, row, col + 1);
            findWord(board, root, word, row - 1, col);
            findWord(board, root, word, row, col - 1);
            board[row][col] = x;
        }
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<string> out;
        Trie *tr = new Trie(words);
        TrieNode *root = tr->getRoot();

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                findWord(board, root, "", i, j);

        for (auto x : this->words)
            out.push_back(x);
        return out;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    Solution *sol = new Solution();
    vector<vector<char>> inBoard = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};
    vector<string> inWords = {"oath", "pea", "eat", "rain"};
    vector<string> out = sol->findWords(inBoard, inWords);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}