/*
 * @File: Length of Last Word.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 16th September 2020 9:40:13 pm
 * @Last Modified: Wednesday, 16th September 2020 9:54:32 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (s.length() > i + 1)
                {
                    if (s[i + 1] != ' ')
                        count = 0;
                }
            }
            else
                count++;
        }
        return count;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->lengthOfLastWord("a ") << endl;
    return 0;
}