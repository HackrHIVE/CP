/*
 * @File: 171. Excel Sheet Column Number.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 9th September 2020 9:37:57 pm
 * @Last Modified: Wednesday, 9th September 2020 10:17:32 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int titleToNumber(string s)
    {
        int out = 0;
        bool mul = false;
        for (auto x : s)
        {
            int y = x - 64;
            if (mul)
                out *= 26;
            mul = true;
            out += y;
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->titleToNumber("AAA") << endl;
    return 0;
}