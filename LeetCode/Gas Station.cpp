/*
 * @File: Gas Station.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 24th September 2020 12:24:54 am
 * @Last Modified: Thursday, 24th September 2020 12:42:51 am
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(vector<int> &gas, vector<int> &cost, int start)
    {
        int n = gas.size();
        int fuel = 0;
        int index = start;
        while (index < n)
        {
            fuel += gas[index] - cost[index];
            if (fuel < 0)
                return false;
            index++;
        }
        index = 0;
        while (index < start)
        {
            fuel += gas[index] - cost[index];
            if (fuel < 0)
                return false;
            index++;
        }
        return true;
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            if (gas[i] >= cost[i])
            {
                if (isValid(gas, cost, i))
                    return i;
            }
        }
        return -1;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << sol->canCompleteCircuit(gas, cost) << endl;
    return 0;
}