#include <bits/stdc++.h>
using namespace std;
    class Solution
    {
    public:
        bool isValid(string s)
        {
            stack<char> st;
            if (s[0] == '(' || s[0] == '[' || s[0] == '{')
                st.push(s[0]);
            int i = 1;
            int balance = st.size() > 0 ? 1 : -1;
            while (i < s.length() && balance >= 0)
            {
                char x = s[i++];
                if (x == ')')
                {
                    if (st.empty())
                        return false;
                    char top = st.top();
                    if (top == '(')
                    {
                        st.pop();
                        balance--;
                        cout << "( matched\n";
                    }
                    else
                        return false;
                    continue;
                }
                if (x == ']')
                {
                    if (st.empty())
                        return false;
                    char top = st.top();
                    if (top == '[')
                    {
                        st.pop();
                        balance--;
                        cout << "[ matched\n";
                    }
                    else
                        return false;
                    continue;
                }
                if (x == '}')
                {
                    if (st.empty())
                        return false;
                    char top = st.top();
                    if (top == '{')
                    {
                        st.pop();
                        balance--;
                        cout << "{ matched\n";
                    }
                    else
                        return false;
                    continue;
                }
                st.push(x);
                balance++;
            }
            return balance == 0 && st.empty();
        }
    };
int main()
{
    Solution *sol = new Solution();
    cout << sol->isValid("(){}}{") << endl;
    return 0;
}