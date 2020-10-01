/*
 * @File: Selection.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 29th September 2020 10:06:27 pm
 * @Last Modified: Tuesday, 29th September 2020 10:10:24 pm
 * @Time Complexity: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    int min;
    while (i < n)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);
        i++;
    }
}
int main()
{
    vector<int> arr = {8, 69, 4, 7, 9, 2, 6};
    selectionSort(arr);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}