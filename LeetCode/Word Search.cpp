#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool goOn(vector<vector<char> > &board, char *word, int row, int col, vector<vector<bool> > &visited)
    {
        if (word[0] == 0)
            return true;

        if (row < 0 || row == board.size() || col == board[0].size() || col < 0)
            return false;

        if (visited[row][col])
            return false;

        bool out = false;
        if (word[0] == board[row][col])
        {
            visited[row][col] = true;
            out |= goOn(board, word + 1, row + 1, col, visited);
            out |= goOn(board, word + 1, row, col + 1, visited);
            out |= goOn(board, word + 1, row, col - 1, visited);
            out |= goOn(board, word + 1, row - 1, col, visited);
            visited[row][col] = false;
        }

        return out;
    }
    bool exist(vector<vector<char> > &board, string word)
    {
        char *chArr = new char[word.length() + 1];
        strcpy(chArr, word.c_str());
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        bool out = false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0] && !visited[i][j])
                    out |= goOn(board,chArr+1,i,j,visited);
            }
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    cout << sol->exist(board, "ABCCED") << endl;
    return 0;
}