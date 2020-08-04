#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        float out = log10(num) / (float)log10(4);
        return num > 0 && num == pow(4, ceil(out));
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->isPowerOfFour(64) << endl;
    return 0;
}