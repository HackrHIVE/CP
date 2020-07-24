#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > out = {};
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> > &graph)
    {
        vector<int> path;
        path.push_back(0);
        for (auto x : graph[0])
                traverse(graph, path, x);
        if (out.size() == 0)
            out.push_back(path);
        return out;
    }
    void traverse(vector<vector<int> > &graph, vector<int> path, int node)
    {
        path.push_back(node);
        if (node == graph.size() - 1)
        {
            out.push_back(path);
            return;
        }
        for (auto x : graph[node])
            traverse(graph, path, x);
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> in = {{}};
    vector<vector<int>> out = sol->allPathsSourceTarget(in);
    for (auto x : out)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}