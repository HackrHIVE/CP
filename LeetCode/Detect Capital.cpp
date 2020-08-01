#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int cap = 0;
        for (auto x : word)
            if (x >= 65 && x <= 90)
                cap++;
        return (cap == word.length() || (cap == 1 && word[0] >= 65 && word[0] <= 90) || cap == 0);
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->detectCapitalUse("FlaG") << endl;
    return 0;
}