/*
 * @File: Merge.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 30th September 2020 12:24:16 am
 * @Last Modified: Thursday, 1st October 2020 9:52:46 pm
 */
#include <bits/stdc++.h>
using namespace std;
void mergeBoth(vector<int> &arr, int lo, int mid, int hi)
{
    int sizeL = mid - lo + 1;
    int sizeR = hi - mid;
    int *arrL = new int[sizeL];
    int *arrR = new int[sizeR];
    for (int i = 0; i < sizeL; i++)
        arrL[i] = arr[i + lo];
    for (int i = 0; i < sizeR; i++)
        arrR[i] = arr[i + mid + 1];
    int loL = 0;
    int loR = 0;
    int index = lo;
    while (loL < sizeL && loR < sizeR)
    {
        if (arrL[loL] <= arrR[loR])
            arr[index++] = arrL[loL++];
        else
            arr[index++] = arrR[loR++];
    }
    while (loL < sizeL)
        arr[index++] = arrL[loL++];
    while (loR < sizeR)
        arr[index++] = arrR[loR++];
    delete[] arrL;
    delete[] arrR;
}
void mergeSort(vector<int> &arr, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        mergeBoth(arr, lo, mid, hi);
    }
}
int main()
{
    vector<int> arr = {8, 69, 4, 7, 9, 2, 6, 5};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}