#include <bits/stdc++.h>
using namespace std;
bool optimized(int &x, int &y, int &k, long int &n)
{

    bool flag = false;
    if (x > y)
    {
        while (x >= 0 && y <= n)
        {
            if (x == y)
            {
                flag = true;
                break;
            }
            x -= k;
            y += k;
        }
    }
    else
    {
        while (y >= 0 && x <= n)
        {
            if (x == y)
            {
                flag = true;
                break;
            }
            y -= k;
            x += k;
        }
    }
    return flag;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t;
    int x, y, k;
    long int n;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> k >> n;
        if (optimized(x, y, k, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}