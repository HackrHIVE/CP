#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k)
    {
        cout << "In minNumberOfSemesters()\n";
        unordered_set<int> noInwards;
        for (int i = 1; i <= n; i++)
            noInwards.insert(i);
        vector<vector<int>> adjList(n + 1);
        for (auto x : dependencies)
            adjList[x[0]].push_back(x[1]);
        cout << "AdjList ready.\n";
        for (auto x : noInwards)
        {
            int el = x;
            for (int j = 1; j <= n; j++)
            {
                if (find(adjList[j].begin(), adjList[j].end(), el) == adjList[j].end())
                {
                    noInwards.erase(el);
                }
            }
        }
        cout << "noInwards ready.\n";
        queue<int> myQ;
        for (auto x : noInwards)
            myQ.push(x);
        cout << "myQ ready.\n";
        int sem = 0;
        vector<bool> visited(n, false);
        int tempK = k;
        while (!myQ.empty())
        {
            cout << "in while\n";
            if (tempK == 0)
            {
                sem++;
                cout << "new sem : " << sem << endl;
                tempK = k;
            }
            int el = myQ.front();
            cout << "new front : " << el << endl;
            if (!visited[el])
            {
                for (auto x : adjList[el])
                    myQ.push(x);
                visited[el] = true;
                tempK--;
            }
            cout << "new temp : " << tempK << endl;
            myQ.pop();
        }
        return sem;
    }
};
int main()
{
    Solution *sol = new Solution();
    int n = 5;
    vector<vector<int>> in = {{2, 1}, {3, 1}, {4, 1}, {1, 5}};
    int k = 2;
    cout << sol->minNumberOfSemesters(n, in, k) << endl;
    return 0;
}