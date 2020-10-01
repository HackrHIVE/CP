#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myAtoi(string str)
    {
        int i = 0;
        int ans = 0;
        int n = str.length();
        bool positive = true;
        while (str[i] == ' ')
            i++;
        if (str[i] == '-')
        {
            positive = false;
            i++;
        }
        else if (str[i] == '+')
            i++;
        else if (!isdigit(str[i]))
            return 0;
        while (i < n && isdigit(str[i]))
        {
            int digit = str[i] - '0';
            if (!positive)
                digit *= -1;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10))
                return INT_MAX;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < INT_MIN % 10))
                return INT_MIN;
            ans = ans * 10 + digit;
            i++;
        }
        return ans;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->myAtoi("42") << endl;
    return 0;
}