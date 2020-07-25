#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        stack<int> s;
        bool carry = true;
        int i = digits.size() - 1;
        while (i >= 0)
        {
            if (carry)
            {
                if (digits[i] == 9)
                {
                    s.push(0);
                    carry = true;
                }
                else
                {
                    s.push(digits[i] + 1);
                    carry = false;
                }
            }
            else
                s.push(digits[i]);
            i--;
        }
        if (carry)
            s.push(1);
        vector<int> out;
        while (!s.empty())
        {
            out.push_back(s.top());
            s.pop();
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {0};
    vector<int> out = sol->plusOne(in);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}