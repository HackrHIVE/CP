#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t;
    string temp;
    cin >> t;
    while (t--)
    {
        cin >> temp;
        int index = 0;
        int out = 0;
        while (index < temp.length())
        {
            if ((temp[index] == 'x' && temp[index + 1] == 'y') ||
                (temp[index] == 'y' && temp[index + 1] == 'x'))
            {
                out++;
                index++;
            }
            index++;
        }
        cout<<out<<endl;
    }
    return 0;
}