#include <bits/stdc++.h>
using namespace std;
int count = 0;
void findPathsTillTheEnd(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited, int total0, int steps, int row, int col)
{
    cout << "findPathsTillTheEnd() for : " << x << "," << y << endl;
    if (grid[x][y] == 2)
    {
        if (steps == total0)
            ::count++;
        return;
    }
    if (grid[x][y] == -1)
        return;

    visited[x][y] = true;
    steps++;
    cout << "Steps now -> " << steps << endl;

    if (x > 0)
    {
        cout << "Up Check\n";
        //Upwards
        if (!visited[x - 1][y])
        {
            cout << "Going Upwards\n";
            findPathsTillTheEnd(grid, x - 1, y, visited, total0, steps, row, col);
        }
    }
    if (y > 0)
    {
        cout << "Left Check\n";
        //Leftwards
        if (!visited[x][y - 1])
        {
            cout << "Going Leftwards\n";
            findPathsTillTheEnd(grid, x, y - 1, visited, total0, steps, row, col);
        }
    }
    if (x < row)
    {
        cout << "Down Check\n";
        //Downwards
        if (!visited[x + 1][y])
        {
            cout << "Going Downwards\n";
            findPathsTillTheEnd(grid, x + 1, y, visited, total0, steps, row, col);
        }
    }
    if (y < col)
    {
        cout << "Right Check\n";
        //Rightwards
        if (!visited[x][y + 1])
        {
            cout << "Going Rightwards\n";
            findPathsTillTheEnd(grid, x, y + 1, visited, total0, steps, row, col);
        }
    }

    visited[x][y] = false;
}
int uniquePathsIII(vector<vector<int>> grid)
{
    int total0 = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
                total0++;
        }
    }
    cout << "total Zeroes : " << total0 << endl;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for(auto x:visited){
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }
    cout << "Size of visited -> " << visited.size() << " : " << visited[0].size() << endl;
    findPathsTillTheEnd(grid, 0, 0, visited, total0, 0, grid.size(), grid[0].size());

    return ::count;
}
int main()
{
    cout << uniquePathsIII(vector<vector<int>>{
                {1, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 2, -1}})
         << endl;
    return 0;
}