#include <bits/stdc++.h>
using namespace std;
bool solveSubset(vector<int> &arr, int target)
{
    vector<vector<bool>> dp(target + 1, vector<bool>(arr.size() + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= target; i++)
        dp[i][0] = false;
    for (int i = 0; i <= arr.size(); i++)
        dp[0][i] = true;

    for (int i = 1; i <= target; i++)
    {
        for (int j = 1; j <= arr.size(); j++)
        {
            if (i >= arr[j - 1])
                dp[i][j] = dp[i][j - 1] || dp[i - arr[j - 1]][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[target][arr.size()];
}
bool equalSumPartition(vector<int> &arr)
{
    int sum = 0;
    for (auto x : arr)
        sum += x;
    if (sum % 2 != 0)
        return false;

    return solveSubset(arr, sum / 2);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    vector<int> arr = {1, 5, 11, 5};
    cout << equalSumPartition(arr) << endl;
    return 0;
}