/*
 * @File: 4.1.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 13th August 2020 6:07:37 pm
 * @Last Modified: Saturday, 15th August 2020 2:25:41 pm
 */
/*
 * Route Between Nodes : Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph, vector<bool> &visited, int src, int dest)
{
    visited[src] = true;
    if (src == dest)
        return;
    for (auto x : graph[src])
        if (!visited[x])
            dfs(graph, visited, x, dest);
}
int main()
{
    int edges, n;
    cout << "Nodes ==> ";
    cin >> n;
    cout << "Edges ==> ";
    cin >> edges;
    vector<vector<int>> graph(n + 1, vector<int>{});
    int a, b;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<bool> visited(n + 1, false);
    int src, dest;
    cout << "Source ==> ";
    cin >> src;
    cout << "Destination ==> ";
    cin >> dest;
    dfs(graph, visited, src, dest);
    if (visited[dest])
        cout << dest << " is reachable from " << src << endl;
    else
        cout << dest << " is not reachable from " << src << endl;
    return 0;
}