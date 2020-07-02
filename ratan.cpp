#include <bits/stdc++.h>
using namespace std;
void printbfs(int n, vector<vector<int>> arr, int sv, bool visited[])
{

    queue<int> pv;
    pv.push(sv);
    visited[sv] = true;

    while (!pv.empty())
    {

        int cv = pv.front();

        pv.pop();
        cout << cv << " ";
        sort(arr[cv].begin(),arr[cv].end());
        for(auto x : arr[cv]){
            if (!visited[x])
            {
                pv.push(x);
                visited[x] = true;
            }
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> arr(v);
    while (e--)
    {
        int f, s;
        cin >> f >> s;

        arr[f].push_back(s);
        arr[s].push_back(f);
    }
    bool visited[v];

    for (int i = 0; i < v; i++)
    {

        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            printbfs(v, arr, i, visited);
        }
    }

    return 0;
}