#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
            arr[i] = new int[n];

        

        for (int i = 0; i < n; i++)
            delete[] arr[i];
        delete[] arr;
    }
    return 0;
}