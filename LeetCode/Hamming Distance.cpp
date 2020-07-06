#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> decToBin(int x)
    {
        stack<bool> s;
        while (x != 0)
        {
            (x % 2 == 0) ? s.push(false) : s.push(true);
            x /= 2;
        }
        vector<bool> out;
        while (!s.empty())
        {
            bool y = s.top();
            out.push_back(y);
            s.pop();
        }
        return out;
    }
    int xorMethod(int x, int y)
    {
        int z = x ^ y;
        int out = 0;
        while (z)
        {
            out += (z & 1);
            z = z >> 1;
        }
        return out;
    }
    int hammingDistance(int x, int y)
    {
        return xorMethod(x, y);
        vector<bool> first = decToBin(x);
        for (auto u : first)
            cout << u << " ";
        cout << endl;
        vector<bool> sec = decToBin(y);
        for (auto u : sec)
            cout << u << " ";
        cout << endl;
        int out = 0;
        if (first.size() != sec.size())
        {
            if (first.size() > sec.size())
            {
                int startingI_s = 0;
                int startingI_f = first.size() - sec.size();
                int is = 0;
                while (is < startingI_f)
                {
                    if (first[is++])
                        out++;
                }
                while (startingI_f < first.size() && startingI_s < sec.size())
                {
                    if (first[startingI_f] != sec[startingI_s])
                        out++;
                    startingI_s++;
                    startingI_f++;
                }
            }
            else
            {
                int startingI_f = 0;
                int startingI_s = sec.size() - first.size();
                int is = 0;
                while (is < startingI_s)
                {
                    if (sec[is++])
                        out++;
                }
                while (startingI_f < first.size() && startingI_s < sec.size())
                {
                    if (first[startingI_f] != sec[startingI_s])
                        out++;
                    startingI_s++;
                    startingI_f++;
                }
            }
        }
        else
        {

            int startingI_f = 0;
            int startingI_s = 0;
            while (startingI_f < first.size() && startingI_s < sec.size())
            {
                if (first[startingI_f] != sec[startingI_s])
                    out++;
                startingI_s++;
                startingI_f++;
            }
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->hammingDistance(93, 73) << endl;
    return 0;
}