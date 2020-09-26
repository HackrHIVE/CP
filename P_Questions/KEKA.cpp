#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int unit = n % 10;
    int tens = (n - unit) / 10;
    vector<int> output(10, 0);
    int index = 0;
    if (tens > 0)
    {
        if (tens >= 5)
        {
            output[4] = 1;
            tens -= 5;
        }
        while (tens > 0)
        {
            output[index++] = 1;
            tens--;
        }
    }
    index = 9;
    if (unit >= 5)
    {
        output[5] = 1;
        unit -= 5;
    }
    while (unit > 0)
    {
        output[index--] = 1;
        unit--;
    }
    for (auto x : output)
        cout << x << " ";
    cout << endl;
    return 0;
}