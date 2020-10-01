/*
 * @File: 3. Longest Substring Without Repeating Characters.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 29th September 2020 5:00:47 pm
 * @Last Modified: Tuesday, 29th September 2020 6:44:48 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> uset;
        int start = 0;
        int end = 0;
        int n = s.length();
        int size = 0;
        while (end < n)
        {
            if (uset.find(s[end]) == uset.end())
            {
                uset.insert(s[end]);
                end++;
                size = max(size, end - start);
            }
            else
            {
                uset.erase(s[start]);
                start++;
            }
        }
        return size;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->lengthOfLongestSubstring("ababzd") << endl;
    return 0;
}