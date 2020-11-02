#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 1.0)
            return x;
        double out = 1.0;
        while (n > 0)
        {
            out *= x;
            n--;
        }
        while (n < 0)
        {
            out /= x;
            n++;
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->myPow(10000, -2147483647) << endl;
    return 0;
}