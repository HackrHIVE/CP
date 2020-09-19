/*
 * @File: GFG_India and its Spirituality.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Sunday, 13th September 2020 7:35:32 pm
 * @Last Modified: Sunday, 13th September 2020 8:10:01 pm
 */
#include <bits/stdc++.h>
using namespace std;
int maxOut = 0;
void placeSpiritual(vector<vector<char>> &a, int n, int m, int row, int col)
{
    if (row > 0)
        if (a[row - 1][col] != '*')
            a[row - 1][col] = '#';
    if (row + 1 < n)
        if (a[row + 1][col] != '*')
            a[row + 1][col] = '#';
    if (col > 0)
        if (a[row][col - 1] != '*')
            a[row][col - 1] = '#';
    if (col + 1 < m)
        if (a[row][col + 1] != '*')
            a[row][col + 1] = '#';
    if (row > 0 && col > 0)
        if (a[row - 1][col - 1] != '*')
            a[row - 1][col - 1] = '#';
    if (row + 1 < n && col > 0)
        if (a[row + 1][col - 1] != '*')
            a[row + 1][col - 1] = '#';
    if (col + 1 < m && row > 0)
        if (a[row - 1][col + 1] != '*')
            a[row - 1][col + 1] = '#';
    if (col + 1 < m && row + 1 < n)
        if (a[row + 1][col + 1] != '*')
            a[row + 1][col + 1] = '#';
}
void dfs(vector<vector<char>> &a, int n, int m, int row, int col, vector<vector<bool>> &v, int path)
{
    // cout << "DFS @ " << row << "," << col << endl;
    v[row][col] = true;

    if (row > 0)
        if (!v[row - 1][col] && a[row - 1][col] == '#')
            dfs(a, n, m, row - 1, col, v, path + 1);
    if (row + 1 < n)
        if (!v[row + 1][col] && a[row + 1][col] == '#')
            dfs(a, n, m, row + 1, col, v, path + 1);
    if (col > 0)
        if (!v[row][col - 1] && a[row][col - 1] == '#')
            dfs(a, n, m, row, col - 1, v, path + 1);
    if (col + 1 < m)
        if (!v[row][col + 1] && a[row][col + 1] == '#')
            dfs(a, n, m, row, col + 1, v, path + 1);
    if (row > 0 && col > 0)
        if (!v[row - 1][col - 1] && a[row - 1][col - 1] == '#')
            dfs(a, n, m, row - 1, col - 1, v, path + 1);
    if (row + 1 < n && col > 0)
        if (!v[row + 1][col - 1] && a[row + 1][col - 1] == '#')
            dfs(a, n, m, row + 1, col - 1, v, path + 1);
    if (col + 1 < m && row > 0)
        if (!v[row - 1][col + 1] && a[row - 1][col + 1] == '#')
            dfs(a, n, m, row - 1, col + 1, v, path + 1);
    if (col + 1 < m && row + 1 < n)
        if (!v[row + 1][col + 1] && a[row + 1][col + 1] == '#')
            dfs(a, n, m, row + 1, col + 1, v, path + 1);

    if (path > maxOut)
        maxOut = path;
    v[row][col] = false;
}
int maxCities(vector<vector<char>> &a, int n, int m)
{
    maxOut = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '*')
                placeSpiritual(a, n, m, i, j);
        }
    }
    // for (auto x : a)
    // {
    //     for (auto y : x)
    //         cout << y;
    //     cout << endl;
    // }
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#' && !v[i][j])
            {
                // cout << "calling DFS at " << i << "," << j << endl;
                dfs(a, n, m, i, j, v, 1);
            }
        }
    }
    return ::maxOut;
}
int main()
{
    int t, m, n;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        cout << maxCities(a, n, m) << endl;
    }
    return 0;
}