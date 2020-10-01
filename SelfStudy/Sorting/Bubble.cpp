/*
 * @File: Bubble.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 29th September 2020 10:13:55 pm
 * @Last Modified: Tuesday, 29th September 2020 11:32:06 pm
 * @Time Complexity: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    bubbleSort(arr);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}