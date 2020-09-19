/*
 * @File: House Robber.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Monday, 14th September 2020 10:53:27 pm
 * @Last Modified: Wednesday, 14th September 2020 10:59:52 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; i++)
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        return dp[n];
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {2, 1, 1, 2};
    cout << sol->rob(in) << endl;
    return 0;
}