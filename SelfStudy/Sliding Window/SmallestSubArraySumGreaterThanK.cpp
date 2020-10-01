/*
 * @File: SmallestSubArraySumGreaterThanK.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 29th September 2020 6:07:14 pm
 * @Last Modified: Tuesday, 29th September 2020 6:20:01 pm
 * @Type: Dynamic Window Size Problem
 */
#include <bits/stdc++.h>
using namespace std;
int findSmallestSubArrayWithSum(vector<int> &arr, int k)
{
    int start = 0;
    int end = 0;
    int n = arr.size();
    int sum = 0;
    int size = INT_MAX;
    while (end < n)
    {
        sum += arr[end];
        if (sum >= k)
        {
            size = min(size, end - start + 1);
            if (size == 1)
                return size;
            sum -= arr[start++];
        }
        end++;
    }
    return size;
}
int main()
{
    vector<int> arr = {4, 2, 2, 7, 1, 8, 2, 1, 0};
    cout << findSmallestSubArrayWithSum(arr, 8) << endl;
    return 0;
}