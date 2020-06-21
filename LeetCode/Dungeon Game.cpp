#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calculateBoiz(vector<vector<int>> &dungeon, int sumAll, int row, int col, vector<vector<int>> &memoizer, vector<vector<bool>> &visited)
    {
        sumAll += dungeon[row][col];
        int out = 0;
        if (sumAll <= 0 && dungeon[row][col] < 0)
            out += abs(dungeon[row][col]);
        if (row == dungeon.size() - 1 && col == dungeon[0].size() - 1)
            return out;
        visited[row][col] = true;
        int tempA = INT_MAX;
        int tempB = INT_MAX;
        if (row + 1 < dungeon.size())
            if (!visited[row + 1][col])
                tempA = calculateBoiz(dungeon, sumAll, row + 1, col, memoizer, visited);
            else
                tempA = memoizer[row + 1][col];
        if (col + 1 < dungeon[0].size())
            if (!visited[row][col + 1])
                tempB = calculateBoiz(dungeon, sumAll, row, col + 1, memoizer, visited);
            else
                tempB = memoizer[row][col + 1];
        int x = min(tempA, tempB);
        memoizer[row][col] = 0;
        if (out == 0)
        {
            if (x == INT_MAX)
                return 0;
            else if (x > dungeon[row][col])
                return memoizer[row][col] = x - dungeon[row][col];
            else
                return 0;
        }
        return memoizer[row][col] = out + x;
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        vector<vector<bool>> visited(dungeon.size(), vector<bool>(dungeon[0].size(), false));
        vector<vector<int>> memoizer(dungeon.size(), vector<int>(dungeon[0].size(), 0));
        return calculateBoiz(dungeon, 0, 0, 0, memoizer, visited) + 1;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    Solution *sol = new Solution();
    vector<vector<int>> in = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}};
    cout << sol->calculateMinimumHP(in) << endl;
    return 0;
}