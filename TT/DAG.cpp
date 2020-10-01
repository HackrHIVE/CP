#include <bits/stdc++.h>
using namespace std;
bool myWay(pair<int, int> x, pair<int, int> y)
{
    return (x.second < y.second);
}
int dfs(vector<int> adj[], int n, vector<bool> &visited)
{
}
int longestPath(vector<int> adj[], int n)
{
    vector<pair<int, int>> sortedVertices;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
        sortedVertices.push_back({i, adj[i].size()});
    sort(sortedVertices.begin(), sortedVertices.end(), myWay);
    int minPath =
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int n = 5;
    vector<int> adjList[n + 1];
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    adjList[2].push_back(3);
    adjList[2].push_back(4);
    adjList[4].push_back(3);
    adjList[5].push_back(1);
    adjList[5].push_back(2);
    adjList[5].push_back(3);
    cout << longestPath(adjList, n) << endl;
    return 0;
}