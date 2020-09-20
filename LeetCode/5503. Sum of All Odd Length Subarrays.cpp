/*
 * @File: 5503. Sum of All Odd Length Subarrays.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 19th September 2020 8:14:35 pm
 * @Last Modified: Saturday, 19th September 2020 8:24:08 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int outSum = 0;
        for (int k = 1; k <= n; k += 2)
        {
            for (int i = 0; i <= n - k; i++)
            {
                for (int j = i; j < k + i; j++)
                    outSum += arr[j];
            }
        }
        return outSum;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {1, 4, 2, 5, 3};
    cout << sol->sumOddLengthSubarrays(in) << endl;
    return 0;
}