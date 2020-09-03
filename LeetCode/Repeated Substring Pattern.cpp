#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int len = s.length();
        for (int i = len / 2; i >= 1; i--)
        {
            if (len % i == 0)
            {
                int repeats = len / i;
                string base = s.substr(0, i);
                string temp = "";
                for (int j = 0; j < repeats; j++)
                    temp += base;
                if (temp.compare(s) == 0)
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->repeatedSubstringPattern("ababab") << endl;
    return 0;
}