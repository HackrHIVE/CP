#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void isConnectedToTerminal(vector<vector<char>> &board, int row, int col)
    {
        if (board[row][col] == 'O')
            board[row][col] = 'x';
        if (row + 1 < board.size())
        {
            if (board[row + 1][col] == 'O')
                isConnectedToTerminal(board, row + 1, col);
        }

        if (row > 0)
        {
            if (board[row - 1][col] == 'O')
                isConnectedToTerminal(board, row - 1, col);
        }

        if (col + 1 < board[0].size())
        {
            if (board[row][col + 1] == 'O')
                isConnectedToTerminal(board, row, col + 1);
        }

        if (col > 0)
        {
            if (board[row][col - 1] == 'O')
                isConnectedToTerminal(board, row, col - 1);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O')
                isConnectedToTerminal(board, i, 0);
            if (board[i][board[i].size() - 1] == 'O')
                isConnectedToTerminal(board, i, board[i].size() - 1);
        }
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[0][i] == 'O')
                isConnectedToTerminal(board, 0, i);
            if (board[board.size() - 1][i] == 'O')
                isConnectedToTerminal(board, board.size() - 1, i);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'x')
                    board[i][j] = 'O';
            }
        }
    }
};
int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cout.tie(nullptr);
    // std::cin.tie(nullptr);
    Solution *sol = new Solution();
    vector<vector<char>> in = {{'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}, {'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}};
    // {{'X', 'X', 'X', 'X'},
    //                            {'X', 'O', 'O', 'X'},
    //                            {'X', 'X', 'O', 'X'},
    //                            {'X', 'O', 'X', 'X'}};
    cout << "Input : \n";
    for (auto x : in)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    sol->solve(in);
    cout << "Output : \n";
    for (auto x : in)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}