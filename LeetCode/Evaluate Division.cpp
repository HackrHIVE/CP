#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++)
        {
            vector<string> x = equations[i];
            unordered_map<char, int> umap;
            for (auto y : x[0])
                umap[y]++;
            for (auto y : x[1])
                umap[y]--;
            string numerator = "";
            string denominator = "";
            for (auto y : umap)
                if (y.second > 0)
                    numerator += y.first;
                else if (y.second < 0)
                    denominator += y.first;
            graph[numerator].push_back({denominator, values[i]});
            graph[denominator].push_back({numerator, 1 / (double)values[i]});
        }
        vector<double> out;
        for (auto x : queries)
        {
            unordered_map<char, int> umap;
            for (auto y : x[0])
                umap[y]++;
            for (auto y : x[1])
                umap[y]--;
            string numerator = "";
            string denominator = "";
            for (auto y : umap)
                if (y.second > 0)
                    numerator += y.first;
                else if (y.second < 0)
                    denominator += y.first;
            if (graph.find(numerator) != graph.end())
            {
                vector<pair<string, double>> list;
                bool found = false;
                for (auto t : list)
                {
                    if (t.first.compare(denominator) == 0)
                    {
                        found = true;
                        out.push_back(t.second);
                        break;
                    }
                }
                if (!found)
                    out.push_back(-1.0);
            }
            else
                out.push_back(-1.0);
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<string>> equations = {
        {"a", "b"},
        {"b", "c"},
    };
    vector<double> values = {
        2.0,
        3.0,
    };
    vector<vector<string>> queries = {
        {"a", "c"},
        {"b", "a"},
        {"a", "e"},
    };
    vector<double> out = sol->calcEquation(equations, values, queries);
    for (auto x : out)
        cout << x << endl;
    return 0;
}