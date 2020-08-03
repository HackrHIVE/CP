#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int lo = 0;
        int hi = s.length() - 1;
        while (lo < hi)
        {
            bool loA = (s[lo] >= 65 && s[lo] <= 90) || (s[lo] >= 97 && s[lo] <= 122) || (s[lo] >= 48 && s[lo] <= 57);
            bool hiA = (s[hi] >= 65 && s[hi] <= 90) || (s[hi] >= 97 && s[hi] <= 122) || (s[hi] >= 48 && s[hi] <= 57);
            if (loA && hiA)
            {
                if (s[lo] >= 97)
                    s[lo] = 65 + (s[lo] - 97);
                if (s[hi] >= 97)
                    s[hi] = 65 + (s[hi] - 97);
                if (s[lo] == s[hi])
                {
                    lo++;
                    hi--;
                }
                else
                    return false;
            }
            if (!loA)
                lo++;
            if (!hiA)
                hi--;
        }

        return true;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->isPalindrome("ab2a") << endl;
    return 0;
}