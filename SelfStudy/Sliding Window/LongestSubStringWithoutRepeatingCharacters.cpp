/*
 * @File: LongestSubStringWithoutRepeatingCharacters.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 29th September 2020 6:20:35 pm
 * @Last Modified: Tuesday, 29th September 2020 6:45:39 pm
 * @Type: Dynamic Window Size Problem with Auxiliary Data Structure
 */
#include <bits/stdc++.h>
using namespace std;
int findLongestSubStringWithoutRepeatingCharacters(string s)
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
            for (int i = start; i < end; i++)
                cout << s[i];
            cout << endl;
        }
        else
        {
            uset.erase(s[start]);
            start++;
        }
    }
    return size;
}
int main()
{
    cout << findLongestSubStringWithoutRepeatingCharacters("abcabcbb") << endl;
    return 0;
}