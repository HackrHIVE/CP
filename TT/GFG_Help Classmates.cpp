/*
 * @File: GFG_Help Classmates.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Sunday, 13th September 2020 7:08:13 pm
 * @Last Modified: Sunday, 13th September 2020 8:09:58 pm
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> help_classmate(vector<int> array, int n)
{
    vector<int> out;
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                found = true;
                out.push_back(array[j]);
                break;
            }
        }
        if (!found)
            out.push_back(-1);
    }

    return out;
}
int main()
{
    int t;
    long int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> out = help_classmate(arr, n);
        for (auto x : out)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}