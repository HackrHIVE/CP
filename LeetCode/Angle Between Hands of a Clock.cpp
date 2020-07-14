#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        cout << "Hour : " << hour << "\tMinutes : " << minutes << endl;
        double angleH = ((hour % 12) * 30.0f) + ((minutes / (double)60) * 30.0f);
        double angleM = minutes / (double)60 * 360.0f;
        cout << "angleH : " << angleH << endl;
        cout << "angleM : " << angleM << endl;
        double one = angleH - angleM;
        double two = angleM - angleH;
        if (one < 0)
            one += 360;
        if (two < 0)
            two += 360;
        return (one <= two) ? one : two;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->angleClock(12, 30) << endl;
    return 0;
}