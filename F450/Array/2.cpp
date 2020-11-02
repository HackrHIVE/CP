/*
 * @File: 2.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 22nd October 2020 3:27:48 pm
 * @Last Modified: Thursday, 22nd October 2020 3:27:57 pm
 * @Question: Maximum and minimum of an array using minimum number of comparisons
 */
#include <bits/stdc++.h>
using namespace std;
void naiveApproach(vector<int> &arr)
{
    if (arr.size() == 0)
        return;
    if (arr.size() == 1)
    {
        cout << "Max : " << arr[0] << endl;
        cout << "Min : " << arr[0] << endl;
        return;
    }
    int max, min;
    if (arr[0] >= arr[1])
    {
        min = arr[1];
        max = arr[0];
    }
    else
    {
        min = arr[0];
        max = arr[1];
    }
    for (int i = 2; i < arr.size(); i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    cout << "Max : " << max << endl;
    cout << "Min : " << min << endl;
}
int main()
{
    vector<int> in = {1, 2, 3, 4, 5, 9};
    naiveApproach(in);
    return 0;
}