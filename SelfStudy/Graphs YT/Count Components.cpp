#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph, int &node, vector<bool> &visited, int componentId, unordered_map<int, vector<int>> &components)
{
    visited[node] = true;
    components[componentId].push_back(node);
    for (auto x : graph[node])
    {
        if (!visited[x])
            dfs(graph, x, visited, componentId, components);
    }
}
int countComponents(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    int component = 0;
    unordered_map<int, vector<int>> components;
    for (int node = 0; node < n; node++)
    {
        if (!visited[node])
        {
            component++;
            dfs(graph, node, visited, component, components);
        }
    }
    for (auto x : components)
    {
        cout << "Component with components ID " << x.first << " => ";
        for (auto y : x.second)
            cout << y << " ";
        cout << endl;
    }
    return component;
}
int main()
{
    int vertices;
    cout << "Vertices: ";
    cin >> vertices;
    int edges;
    cout << "Edges: ";
    cin >> edges;
    vector<vector<int>> graph(vertices);
    cout << "Enter edges data (u,v) direction oriented:\n";
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int totalComponents = countComponents(graph);
    cout << "Total components => " << totalComponents << endl;
    return 0;
}
/*
6 11
7 11
6 7
5 17
5 16
1 5
4 0
8 4
8 14
0 8
14 0
13 0
14 13
9 3
15 9
2 15
9 2
15 10
*/