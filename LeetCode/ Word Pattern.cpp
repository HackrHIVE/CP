/*
 * @File:  Word Pattern.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Monday, 7th September 2020 9:39:29 pm
 * @Last Modified: Monday, 7th September 2020 10:05:33 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        char *token = strtok(const_cast<char *>(str.c_str()), " ");
        vector<string> pats;
        while (token != NULL)
        {
            pats.push_back(string(token));
            token = strtok(NULL, " ");
        }
        if (pats.size() != pattern.length())
            return false;

        unordered_map<char, string> umap;
        unordered_map<string, char> mapu;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (umap.find(pattern[i]) != umap.end())
            {
                if (umap[pattern[i]].compare(pats[i]) != 0)
                    return false;
            }
            else if (mapu.find(pats[i]) != mapu.end())
            {
                if (mapu[pats[i]] != pattern[i])
                    return false;
            }
            umap[pattern[i]] = pats[i];
            mapu[pats[i]] = pattern[i];
        }
        return true;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}