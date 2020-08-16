/*
 * @File: Path Through Graph.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 15th August 2020 10:24:43 pm
 * @Last Modified: Sunday, 16th August 2020 12:13:49 am
 * @Status: Accepted
 */
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    unordered_set<int> connected;
    Node(int data)
    {
        this->data = data;
    }
};
void factors(int x, vector<int> &y)
{
    int i = x - 1;
    y.push_back(x);
    while (i > 0)
    {
        if (x % i == 0)
        {
            factors(i, y);
            return;
        }
        i--;
    }
}
int minEdges = INT_MAX;
void dfs(unordered_map<int, Node *> &umap, unordered_map<int, bool> &visited, int src, int dest, int edges)
{
    if (src == dest)
    {
        if (minEdges > edges)
            minEdges = edges;
        return;
    }
    visited[src] = true;
    Node *currentNode = umap[src];
    for (auto x : currentNode->connected)
    {
        if (!visited[x])
            dfs(umap, visited, x, dest, edges + 1);
    }
    visited[src] = false;
}
int main()
{
    int m, n;
    cin >> m >> n;
    if (n == m)
        cout << "0";
    else
    {
        vector<int> mF;
        factors(m, mF);
        vector<int> nF;
        factors(n, nF);
        unordered_map<int, Node *> umap;
        unordered_map<int, bool> visited;
        unsigned int index = 0;
        Node *node = new Node(mF[index]);
        node->connected.insert(mF[index + 1]);
        umap.insert({mF[index], node});
        visited.insert({mF[index], false});
        node = new Node(mF[index + 1]);
        node->connected.insert(mF[index]);
        umap.insert({mF[index + 1], node});
        visited.insert({mF[index + 1], false});
        index++;
        while (index < mF.size() - 1)
        {
            int current = mF[index];
            int next = mF[index + 1];
            Node *node = umap[current];
            node->connected.insert(next);
            node = new Node(next);
            node->connected.insert(current);
            umap.insert({next, node});
            visited.insert({next, false});
            index++;
        }
        index = 0;
        if (umap.find(nF[index]) != umap.end())
            node = umap[nF[index]];
        else
            node = new Node(nF[index]);
        if (node->connected.find(nF[index + 1]) == node->connected.end())
            node->connected.insert(nF[index + 1]);
        umap[nF[index]] = node;
        visited[nF[index]] = false;
        if (umap.find(nF[index + 1]) != umap.end())
            node = umap[nF[index + 1]];
        else
            node = new Node(nF[index + 1]);
        if (node->connected.find(nF[index]) == node->connected.end())
            node->connected.insert(nF[index]);
        umap[nF[index + 1]] = node;
        visited[nF[index + 1]] = false;
        index++;
        while (index < nF.size() - 1)
        {
            int current = nF[index];
            int next = nF[index + 1];
            Node *node = umap[current];
            node->connected.insert(next);
            if (umap.find(next) != umap.end())
                node = umap[next];
            else
                node = new Node(next);
            if (node->connected.find(current) == node->connected.end())
                node->connected.insert(current);
            umap[next] = node;
            visited[next] = false;
            index++;
        }
        /*
        // For checking all Nodes in graph and their connected nodes.
        for (auto x : umap)
        {
            cout << "Node : " << x.first << endl;
            cout << "Connected : ";
            for (auto y : x.second->connected)
                cout << y << " ";
            cout << endl;
        }
        */
        dfs(umap, visited, m, n, 0);
        cout << minEdges;
    }
    return 0;
}