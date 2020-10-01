/*
 * @File: 713. Subarray Product Less Than K.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 29th September 2020 6:48:02 pm
 * @Last Modified: Tuesday, 29th September 2020 7:23:47 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int start = 0;
        int end = 0;
        int product = 1;
        int n = nums.size();
        int count = 0;
        while (end < n && start < n)
        {
            if (product < k)
                product *= nums[end];
            if (product < k)
                count += ++end - start;
            else
            {
                product /= nums[start];
                start++;
                if (product < k)
                    count += ++end - start;
            }
        }
        return count;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {10, 5, 2, 6};
    cout << sol->numSubarrayProductLessThanK(in, 100) << endl;
    return 0;
}