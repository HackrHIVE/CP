/*
 * @File: Bulls and Cows.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 10th September 2020 11:22:53 pm
 * @Last Modified: Thursday, 10th September 2020 11:31:22 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<char, int> smap;
        unordered_map<char, int> gmap;
        int common = 0;
        int n = secret.length();
        for (int i = 0; i < n; i++)
            if (secret[i] == guess[i])
                common++;
        for (auto x : secret)
            smap[x]++;
        for (auto x : guess)
            gmap[x]++;
        int out = 0;
        for (auto x : gmap)
        {
            if (smap.find(x.first) != smap.end())
            {
                if (x.second > smap[x.first])
                    out += smap[x.first];
                else
                    out += x.second;
            }
        }
        out = out - common;
        return to_string(common) + "A" + to_string(out) + "B";
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->getHint("1123", "0111") << endl;
    return 0;
}