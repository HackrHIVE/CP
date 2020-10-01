/*
 * @File: Max Sum SubArray.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 29th September 2020 5:49:48 pm
 * @Last Modified: Tuesday, 29th September 2020 6:19:42 pm
 * @Type: Fixed Window Size Problem
 */
#include <bits/stdc++.h>
using namespace std;
int findMaxSumSubArray(vector<int> &arr, int k)
{
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < k; i++)
        currentSum += arr[i];
    maxSum = currentSum;
    int n = arr.size();
    for (int i = k; i < n; i++)
    {
        currentSum -= arr[i - k];
        currentSum += arr[i];
        if (maxSum < currentSum)
            maxSum = currentSum;
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {1, -2, 3, -9, 2, 1};
    cout << findMaxSumSubArray(arr, 3) << endl;
    return 0;
}