/*
 * @File: 5622. Average Waiting Time.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 26th December 2020 8:27:09 pm
 * @Last Modified: Saturday, 26th December 2020 8:40:20 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        long long int time = 0;
        long long int waitingTime = 0;
        for (vector<int> customer : customers)
        {
            if (customer[0] < time)
                waitingTime += time - customer[0];
            waitingTime += customer[1];
            time = time < customer[0] ? customer[0] + customer[1] : time + customer[1];
        }
        return waitingTime / (double)customers.size();
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> customers = {
        {5, 2},
        {5, 4},
        {10, 3},
        {20, 1},
    };
    cout << sol->averageWaitingTime(customers) << endl;
    return 0;
}