/*
 * @File: 5505. Maximum Sum Obtained of Any Permutation.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 19th September 2020 8:24:18 pm
 * @Last Modified: Saturday, 19th September 2020 8:33:29 pm
 */
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
class Solution
{
public:
    static bool dec(int x, int y)
    {
        return x > y;
    }
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        int n = nums.size();
        vector<int> sumVec(n + 1, 0);
        sort(nums.begin(), nums.end(), dec);
        for (auto x : requests)
        {
            sumVec[x[0]]++;
            sumVec[x[1] + 1]--;
        }
        for (int i = 1; i <= n; i++)
            sumVec[i] += sumVec[i - 1];
        sort(sumVec.begin(), sumVec.end(), dec);
        int outSum = 0;
        for (int i = 0; i < n; i++)
            outSum = outSum % mod + ((sumVec[i] % mod) * (nums[i] % mod)) % mod;
        return outSum;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {1, 2, 3, 4, 5, 10};
    vector<vector<int>> query = {{0, 2}, {1, 3}, {1, 1}};
    cout << sol->maxSumRangeQuery(in, query) << endl;
    return 0;
}