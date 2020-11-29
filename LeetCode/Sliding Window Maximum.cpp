/*
 * @File: Sliding Window Maximum.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Sunday, 29th November 2020 12:20:39 pm
 * @Last Modified: Sunday, 29th November 2020 12:41:04 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        vector<int> out(arr.size() - k + 1);
        deque<int> window;

        for (int i = 0; i < arr.size(); i++)
        {
            while (window.size() > 0 && window.front() <= i - k)
                window.pop_front();
            while (window.size() > 0 && arr[window.back()] < arr[i])
                window.pop_back();

            window.push_back(i);
            if (i >= k - 1)
                out[i - k + 1] = arr[window.front()];
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> out = sol->maxSlidingWindow(in, k);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}