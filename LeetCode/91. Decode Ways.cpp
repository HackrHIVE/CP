/*
 * @File: 91. Decode Ways.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 29th October 2020 1:02:08 pm
 * @Last Modified: Thursday, 29th October 2020 1:30:10 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numDecodingsDP(string s)
    {
        vector<int> cost(s.size() + 2, 0);

        cost[1] = 1;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '0')
                cost[i + 2] += cost[i + 1];
            if (i)
            {
                int twodigit = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (twodigit >= 10 && twodigit <= 26)
                    cost[i + 2] += cost[i];
            }
        }

        return cost.back();
    }
    int numDecodings(string s)
    {
        int count = 0;
        vector<int> pairs;
        waysTotal(s, count, 0, pairs);
        return count;
    }
    void waysTotal(string s, int &count, int index, vector<int> pairs)
    {
        if (s.length() == index)
        {
            for (auto x : pairs)
                cout << x << " ";
            cout << endl;
            count++;
            return;
        }
        if (s[index] == 48)
            return;
        if (s.length() > index + 1)
        {
            int num = s[index] - 48;
            if (num == 0)
                return;
            num *= 10;
            num += s[index + 1] - 48;
            if (num <= 26)
            {
                pairs.push_back(num);
                waysTotal(s, count, index + 2, pairs);
                pairs.pop_back();
            }
            if (s[index + 1] != 48)
            {
                pairs.push_back(s[index] - 48);
                waysTotal(s, count, index + 1, pairs);
                pairs.pop_back();
            }
        }
        else
        {
            pairs.push_back(s[index] - 48);
            waysTotal(s, count, index + 1, pairs);
        }
    }
};
int main()
{
    Solution *sol = new Solution();
    string in;
    cin >> in;
    cout << sol->numDecodingsDP(in) << endl;
    return 0;
}