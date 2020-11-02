/*
 * @File: Rotate Array.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 15th October 2020 7:05:07 pm
 * @Last Modified: Thursday, 15th October 2020 7:20:25 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        k = k % size;
        vector<int> temp(k);
        int index = 0;
        for (int i = size - k; i < size; i++)
            temp[index++] = nums[i];
        for (int i = size - 1; i >= k; i--)
            nums[i] = nums[i - k];
        for (int i = 0; i < k; i++)
            nums[i] = temp[i];
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Solution *sol = new Solution();
    sol->rotate(arr, 3);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}