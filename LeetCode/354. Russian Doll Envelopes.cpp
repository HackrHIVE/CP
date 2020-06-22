#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool custom(vector<int> x, vector<int> y)
    {
        return x[0] < y[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.size() == 0)
            return 0;
        int n = envelopes.size();
        vector<int> mlp(n, 0);
        sort(envelopes.begin(), envelopes.end(), custom);
        int outMax = 0;
        for (int i = 0; i < n; i++)
        {
            int tempMax = 0;
            for (int j = 0; j < i; j++)
            {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                {
                    tempMax = max(mlp[j], tempMax);
                }
            }
            mlp[i] = tempMax + 1;
            outMax = max(mlp[i], outMax);
        }
        return outMax;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    Solution *sol = new Solution();
    vector<vector<int>> in = {{7, 8}, {12, 16}, {12, 5}, {1, 8}, {4, 19}, {3, 15}, {4, 10}, {9, 16}};
    cout << sol->maxEnvelopes(in) << endl;
    return 0;
}