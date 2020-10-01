#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int lowDecimal = 0;
        int lowNum = low;
        while (lowNum > 9)
        {
            lowNum = lowNum / 10;
            lowDecimal++;
        }
        cout << lowNum << endl;
        cout << lowDecimal << endl;
        int highDecimal = 0;
        int highNum = high;
        while (highNum > 9)
        {
            highNum = highNum / 10;
            highDecimal++;
        }
        cout << highNum << endl;
        cout << highDecimal << endl;
        vector<int> outVec;
        for (int i = lowDecimal; i <= highDecimal; i++)
        {
            int out = lowNum;
            for (int j = )
        }
        for (int i = 0; i < lowDecimal; i++)
        {
            out *= 10;
            out += ++lowNum;
        }
        cout << out << endl;
        return {};
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> out = sol->sequentialDigits(100, 300);
    // for (auto x : out)
    //     cout << x << " ";
    // cout << endl;
    return 0;
}