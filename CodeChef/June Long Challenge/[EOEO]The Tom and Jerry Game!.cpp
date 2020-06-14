#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t;
    long long int ts;
    long long int js;
    cin >> t;
    while (t--)
    {
        cin >> ts;
        js = ts / 2;
        if (ts % 2 != 0)
            cout << js << endl;
        else
        {
            while (ts % 2 == 0)
            {
                ts /= 2;
                js /= 2;
            }
            cout << js << endl;
        }
    }
    return 0;
}