#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> out;
    bool jaaMereSher(unordered_map<string, set<string>> &umap, string source, int steps, int totalTickets, vector<string> outS)
    {
        while (umap[source].size() != 0)
        {
            out.push_back(source);
            steps++;
            set<string>::iterator it = umap[source].begin();
            string tempSource = *it;
            umap[source].erase(tempSource);
            source = tempSource;
        }
        steps++;
        outS.push_back(source);
        if (steps == totalTickets)
            return true;

        return false;
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, set<string>> umap;
        for (auto x : tickets)
        {
            string from = x[0];
            string to = x[1];
            umap[from].insert(to);
        }
        for (auto x : umap)
        {
            cout << x.first << " ";
            for (auto y : x.second)
                cout << y << " ";
            cout << endl;
        }
        vector<string> outS;
        string source = "JFK";
        jaaMereSher(umap, source, 0, tickets.size(), outS);
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<string>> in = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> out = sol->findItinerary(in);
    for (auto x : out)
        cout << x << endl;
    return 0;
}