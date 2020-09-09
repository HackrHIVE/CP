/*
 * @File: 121. Best Time to Buy and Sell Stock.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 9th September 2020 8:54:56 pm
 * @Last Modified: Wednesday, 9th September 2020 9:43:44 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minVal = INT_MAX;
        int maxProfit = 0;
        for (auto x : prices)
        {
            if (x < minVal)
                minVal = x;
            else if (x - minVal > maxProfit)
                maxProfit = x - minVal;
        }
        return maxProfit;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> arr = {7, 6, 4, 3, 1};
    cout << sol->maxProfit(arr) << endl;
    return 0;
}