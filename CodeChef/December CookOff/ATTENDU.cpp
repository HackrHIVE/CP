#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t;
    int n;
    char *arr;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int present = 0;
        arr = new char[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            present += arr[i] - 48;
        }
        int remaining = 120 - n;
        int atMax = remaining + present;
        if (atMax >= 90)
            cout << "YES\n";
        else
            cout << "NO\n";
        delete[] arr;
    }
    return 0;
}