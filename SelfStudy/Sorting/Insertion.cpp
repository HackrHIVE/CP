/*
 * @File: Insertion.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 29th September 2020 11:48:29 pm
 * @Last Modified: Tuesday, 29th September 2020 11:52:57 pm
 * @Time Complexity: O(n) Best Case , (n^2) Worst Case , (n^2) Average Case
 * @Comment: Better than Bubble and Selection Sort
 */
#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int index = i;
        while (arr[index - 1] > value && index > 0)
        {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }
}
int main()
{
    vector<int> arr = {7, 9, 2, 0, 2, 3, 7, 5};
    insertionSort(arr);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}