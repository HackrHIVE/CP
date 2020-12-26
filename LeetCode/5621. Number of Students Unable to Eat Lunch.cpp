/*
 * @File: 5621. Number of Students Unable to Eat Lunch.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Saturday, 26th December 2020 8:01:05 pm
 * @Last Modified: Saturday, 26th December 2020 8:25:51 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int sandwichIndex = 0;
        int continuousDecline = 0;
        queue<int> q;
        for (int i = 0; i < students.size(); i++)
            q.push(i);
        while (sandwichIndex < sandwiches.size() && continuousDecline < q.size() && !q.empty())
        {
            int oldSize = q.size();
            int front = q.front();
            q.pop();
            if (students[front] == sandwiches[sandwichIndex])
            {
                continuousDecline = 0;
                sandwichIndex++;
            }
            else
            {
                q.push(front);
                if (oldSize == q.size())
                    continuousDecline++;
            }
        }
        return q.size();
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    cout << sol->countStudents(students, sandwiches) << endl;
    return 0;
}