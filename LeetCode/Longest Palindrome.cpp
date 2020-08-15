/*
 * @File: Longest Palindrome.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Friday, 14th August 2020 11:53:33 pm
 * @Last Modified: Friday, 14th August 2020 11:53:44 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int n = s.length();
        bool *flag = new bool[128];
        memset(flag, false, 128);
        int count = 0;
        for (int i = 0; i < n; i++)
            if ((flag[s[i]] ^= true) == false)
                count += 2;
        delete[] flag;
        return count == n ? count : count + 1;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->longestPalindrome("abccccdd") << endl;
    return 0;
}