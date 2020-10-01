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
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    /*
    Adjacency List
    */
    vector<vector<int>> adj(vertices + 1);
    int i1, i2;
    for (int i = 0; i < edges; i++)
    {
        cin >> i1 >> i2;
        adj[i1].push_back(i2);
        adj[i2].push_back(i1);
    }
    printAdjList(adj);
    int **arr = new int *[vertices];
    for (int i = 0; i < vertices; i++)
        arr[i] = new int[vertices];
    memset(arr, vertices * vertices * sizeof(int), 0);
    for (int i = 1; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            arr[i - 1][adj[i][j] - 1] = 1;
            arr[adj[i][j] - 1][i - 1] = 1;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "  ";
        for (int j = i + 1; j < vertices; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
