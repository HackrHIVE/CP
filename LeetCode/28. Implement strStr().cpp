#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.length() == 0 && needle.length() == 0)
            return 0;
        if (needle.length() == 0 || haystack.length() == 0 || haystack.length() < needle.length())
            return -1;
        vector<int> needleF(26, 0);
        vector<int> window(26, 0);
        for (auto x : needle)
            needleF[x - 97]++;
        int size = haystack.length();
        for (int i = 0; i < size; i++)
            window[haystack[i] - 97]++;
        
        return 0;
    }
};
int main()
{
    Solution *sol = new Solution();
    return 0;
}