#include <bits/stdc++.h>
using namespace std;
int count = 0;
void findPathsTillTheEnd(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited, int total0, int steps, int row, int col)
{
    if (grid[x][y] == 2)
    {
        if (steps == total0 + 1)
            ::count++;
        return;
    }
    if (grid[x][y] == -1)
        return;

    visited[x][y] = true;
    steps++;

    if (x > 0)
        if (!visited[x - 1][y])
            findPathsTillTheEnd(grid, x - 1, y, visited, total0, steps, row, col);
    if (y > 0)
        if (!visited[x][y - 1])
            findPathsTillTheEnd(grid, x, y - 1, visited, total0, steps, row, col);
    if (x + 1 < row)
        if (!visited[x + 1][y])
            findPathsTillTheEnd(grid, x + 1, y, visited, total0, steps, row, col);
    if (y + 1 < col)
        if (!visited[x][y + 1])
            findPathsTillTheEnd(grid, x, y + 1, visited, total0, steps, row, col);

    visited[x][y] = false;
}
int uniquePathsIII(vector<vector<int>> grid)
{
    int total0 = 0;
    int startingX = 0, startingY = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
                total0++;
            if (grid[i][j] == 1)
                startingX = i, startingY = j;
        }
    }
    
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    
    findPathsTillTheEnd(grid, startingX, startingY, visited, total0, 0, grid.size(), grid[0].size());

    return ::count;
}
int main()
{
    cout << uniquePathsIII(vector<vector<int>>{
                {1, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 2}})
         << endl;
    return 0;
}