#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t;
    int n;
    int count5;
    int count10;
    int count15;
    int *arr;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        count5 = 0;
        count10 = 0;
        count15 = 0;
        bool loophole = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 5)
                count5++;
            else
            {
                int change = arr[i] - 5;
                switch (change)
                {
                case 5:
                {
                    if (count5 > 0)
                        count5--;
                    else
                    {
                        loophole = true;
                        break;
                    }
                }
                break;
                case 10:
                {
                    if (count10 > 0)
                        count10--;
                    else if (count5 > 1)
                        count5 -= 2;
                    else
                    {
                        loophole = true;
                        break;
                    }
                }
                break;
                }
                switch (arr[i])
                {
                case 5:
                    count5++;
                    break;
                case 10:
                    count10++;
                    break;
                case 15:
                    count15++;
                    break;
                }
            }
        }
        if (loophole)
            cout << "NO\n";
        else
            cout << "YES\n";
        delete[] arr;
    }
    return 0;
}