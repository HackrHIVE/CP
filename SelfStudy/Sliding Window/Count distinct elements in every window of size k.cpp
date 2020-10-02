/*
 * @File: Count distinct elements in every window of size k.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Friday, 2nd October 2020 10:34:11 pm
 * @Last Modified: Friday, 2nd October 2020 10:45:31 pm
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> umap;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (umap[arr[i]] == 0)
            count++;
        umap[arr[i]]++;
    }
    cout << count << endl;
    for (int i = 0; i < n - k; i++)
    {
        int toBeDiscarded = arr[i];
        int toBeAdded = arr[i + k];
        umap[toBeDiscarded]--;
        if (umap[toBeDiscarded] == 0)
            count--;
        umap[toBeAdded]++;
        if (umap[toBeAdded] == 1)
            count++;
        cout << count << endl;
    }

    delete[] arr;
    return 0;
}