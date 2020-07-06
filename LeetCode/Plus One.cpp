#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int index = digits.size() - 1;
        stack<int> s;
        while (index >= 0)
        {
            if (digits[index] == 9)
            {
                s.push(0);
                index--;
                if (index < 0)
                    s.push(1);
            }
            else
            {
                s.push(digits[index] + 1);
                index--;
                break;
            }
        }
        while (index >= 0)
        {
            s.push(digits[index--]);
        }
        vector<int> out;
        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            out.push_back(x);
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {9, 9, 1, 9};
    vector<int> out = sol->plusOne(in);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}