#include <bits/stdc++.h>
using namespace std;
void printAdjList(vector<vector<int>> adj)
{
    for (int i = 1; i < adj.size(); i++)
    {
        cout << "Vertices connected with vertice(" << i << ") => ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}
bool bfs(vector<vector<int>> adj, int dest)
{
    queue<int> nodes;
    vector<int> visited;
    nodes.push(1);
    while (!nodes.empty())
    {
        int temp = nodes.front();
        visited.push_back(temp);
        for (int i = 0; i < adj[temp].size(); i++)
        {
            if (find(visited.begin(), visited.end(), adj[temp][i]) == visited.end())
            {
                nodes.push(adj[temp][i]);
            }
            if (adj[temp][i] == dest)
                return true;
        }
        nodes.pop();
    }
    cout << "Reaching destination is not possible\n";
    return false;
}
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> adj(vertices + 1);
    int i1, i2;
    for (int i = 0; i < edges; i++)
    {
        cin >> i1 >> i2;
        adj[i1].push_back(i2);
        adj[i2].push_back(i1);
    }
    printAdjList(adj);
    int destination;
    cout << "Destination : ";
    cin >> destination;
    int count = 0;
    for (int i = 1; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            //Delete edge
            cout << "removing edge b/w ::-> " << i << " and " << adj[i][j] << endl;
            int val = adj[i][j];
            adj[i].erase(adj[i].begin() + j);
            auto it = find(adj[adj[i][j]].begin(), adj[adj[i][j]].end(), i);
            adj[adj[i][j]].erase(it);

            if (!bfs(adj, destination))
                count++;

            adj[i].insert(adj[i].begin() + j, val);
            adj[val].insert(it, i);
        }
    }
    cout << count << endl;
    return 0;
}
