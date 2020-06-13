#include <bits/stdc++.h>
using namespace std;
int knapsackWithTabulation(vector<int> wt, vector<int> val, int W, int n)
{
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (wt[j - 1] > i)
            {
                //Item weight is greater than knapsack capacity.
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                //As item weight is less than or equal to knapsack capacity, we have 2 options , either add this item or skip.
                dp[i][j] = max(dp[i][j - 1], val[i - 1] + dp[i][j - 1]);
            }
        }
    }
    for (auto x : dp)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return dp[W][n];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int W = 11, n = 5;
    vector<int> wt = {1, 2, 5, 6, 7};
    vector<int> val = {1, 6, 18, 22, 28};
    cout << knapsackWithTabulation(wt, val, W, n) << endl;
    return 0;
}