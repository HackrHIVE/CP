#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int out = 0;
        int maxX = -1;
        for (int i = 0; i < n; i++)
        {
            out += arr[i] > maxX && (i + 1 == n || arr[i] > arr[i + 1]);
            maxX = max(maxX, arr[i]);
        }
        cout << "Case #" << j + 1 << ": " << out << endl;
    }
    return 0;
}