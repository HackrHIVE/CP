/*
 * @File: 1.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 22nd October 2020 3:26:47 pm
 * @Last Modified: Thursday, 22nd October 2020 3:27:11 pm
 * @Question: Reverse a String
 */
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        char sRev[s.size()];
        int i = s.size() - 1;
        for (int j = 0; j < s.size(); j++)
            sRev[j] = s[i--];
        cout << sRev << endl;
    }
    return 0;
}