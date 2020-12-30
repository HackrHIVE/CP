#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        /*
        0 => 1 : 2
        1 => 0 : 3
        */
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int live = 0;
                if (i - 1 >= 0)
                {
                    if (j - 1 >= 0)
                        live += board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 3 ? 1 : 0;
                    if (j + 1 < m)
                        live += board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 3 ? 1 : 0;
                    live += board[i - 1][j] == 1 || board[i - 1][j] == 3 ? 1 : 0;
                }
                if (i + 1 < n)
                {
                    if (j - 1 >= 0)
                        live += board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 3 ? 1 : 0;
                    if (j + 1 < m)
                        live += board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 3 ? 1 : 0;
                    live += board[i + 1][j] == 1 || board[i + 1][j] == 3 ? 1 : 0;
                }
                if (j - 1 >= 0)
                    live += board[i][j - 1] == 1 || board[i][j - 1] == 3 ? 1 : 0;
                if (j + 1 < m)
                    live += board[i][j + 1] == 1 || board[i][j + 1] == 3 ? 1 : 0;
                int dead = 8 - live;
                if (board[i][j] == 1)
                {
                    if (live < 2 || live > 3)
                        board[i][j] = 3;
                    else
                        board[i][j] = 1;
                }
                else if (live == 3)
                    board[i][j] = 2;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    sol->gameOfLife(board);
    for (auto x : board)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}