/*
 * Build Order : You are given a list of projects and a list of dependencies (which is a list of pairs of projects, 
 *               where the second project is dependent on the first project). All of a project's dependencies must be built
 *               before the project is. Find a build order that will allow the projects to be built. 
 *               If there is no valid build order, return an error.
 * EXAMPLE:
 * Input:
 *          projects: 1, 2, 3, 4, 5, 6
 *          dependencies: (1, 4), (6, 2), (2, 4), (6, 1), (4, 3)
 * Output:  6, 5, 1, 2, 4, 3
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int edges, n;
    cout << "Number of Projects ==> ";
    cin >> n;
    cout << "Dependencies ==> ";
    cin >> edges;
    vector<vector<int>> graph(n + 1, vector<int>{});
    int a, b;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<bool> visited(n + 1, false);
    return 0;
}