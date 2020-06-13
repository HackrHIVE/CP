#include<bits/stdc++.h>
using namespace std;
int knapsackWithMemoization(vector<int> wt, vector<int> val, int W, int n, vector<vector<int>> &dp)
{
    if (n == 0 || W <= 0)
        return 0;
    if (dp[W][n - 1] != -1)
        return dp[W][n - 1];
    if (wt[n - 1] > W)
        return dp[W][n - 1] = knapsackWithMemoization(wt, val, W, n - 1, dp);
    else
        return dp[W][n - 1] = max(knapsackWithMemoization(wt, val, W, n - 1, dp), val[n - 1] + knapsackWithMemoization(wt, val, W - wt[n - 1], n - 1, dp));
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int W = 11, n = 5;
    vector<int> wt = {1, 2, 5, 6, 7};
    vector<int> val = {1, 6, 18, 22, 28};
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    cout << knapsackWithMemoization(wt, val, W, n, dp) << endl;
    return 0;
}