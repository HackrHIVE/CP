#include <bits/stdc++.h>
using namespace std;
int solveSubset(vector<int> &arr, int target)
{
    vector<vector<int>> dp(target + 1, vector<int>(arr.size() + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= target; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= arr.size(); i++)
        dp[0][i] = 1;

    for (int i = 1; i <= target; i++)
    {
        for (int j = 1; j <= arr.size(); j++)
        {
            if (i >= arr[j - 1])
                dp[i][j] = max(dp[i][j - 1], 1+dp[i - arr[j - 1]][j - 1]);
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    for (auto x : dp)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return dp[target][arr.size()];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    vector<int> in = {1, 2, 3, 4};
    int target = 3;
    cout << solveSubset(in, target) << endl;
    return 0;
}