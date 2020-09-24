#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> umap;
        for (auto x : s)
            umap[x]++;
        for (auto x : t)
            umap[x]--;
        for (auto x : umap)
        {
            if (x.second != 0)
                return x.first;
        }
        return ' ';
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->findTheDifference("abcd", "abcde") << endl;
    return 0;
}