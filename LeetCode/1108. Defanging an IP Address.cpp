#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string defangIPaddr(string s)
    {
        for (int i = 0; s[i] != 0; i++)
        {
            if (s[i] == '.')
            {
                s.insert(i, "\[");
                s.insert(i + 2, "]");
                i += 2;
            }
        }
        return s;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    Solution *sol = new Solution();
    cout << sol->defangIPaddr("192.168.1.1") << endl;
    return 0;
}