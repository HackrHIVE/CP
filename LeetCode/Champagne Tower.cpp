/*
 * @File: Champagne Tower.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Monday, 26th October 2020 10:07:08 pm
 * @Last Modified: Monday, 26th October 2020 10:21:09 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        const int kRows = 100;
        double dp[kRows][kRows] = {};
        dp[0][0] = poured;
        for (int i = 0; i < kRows - 1; ++i)
            for (int j = 0; j <= i; ++j)
                if (dp[i][j] > 1)
                {
                    dp[i + 1][j] += (dp[i][j] - 1) / 2.0;
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;
                    dp[i][j] = 1.0;
                }
        return std::min(1.0, dp[query_row][query_glass]);
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->champagneTower(25, 6, 1) << endl;
    return 0;
}