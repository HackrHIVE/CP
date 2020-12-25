/*
 * @File: Decoded String at Index.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Sunday, 20th December 2020 4:28:02 pm
 * @Last Modified: Sunday, 20th December 2020 4:32:28 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeAtIndex(string S, int K)
    {
        size_t decoded_size = 0;
        string res = "";

        for (auto a : S)
        {
            if (isdigit(a))
                decoded_size *= a - '0';
            else
                decoded_size++;
        }

        for (int i = S.size() - 1; i >= 0; i--)
        {
            K %= decoded_size;

            if (!isdigit(S[i]) && K == 0)
                return res + S[i];

            if (isdigit(S[i]))
                decoded_size /= S[i] - '0';
            else
                decoded_size--;
        }

        return res;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->decodeAtIndex("leet2code3", 10) << endl;
    return 0;
}