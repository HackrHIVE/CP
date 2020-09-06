#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    int max = sum;
    for (int i = 0; i < n - k; i++)
    {
        sum -= arr[i];
        sum += arr[i + k];
        if (max < sum)
            max = sum;
    }
    cout << max << endl;
    return 0;
}