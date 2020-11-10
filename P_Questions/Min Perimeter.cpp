#include <bits/stdc++.h>
using namespace std;
int minGridPerimeter(int input1)
{
    long long q, sum = 0, unit = -1;
    while (input1 > sum)
    {
        unit++;
        sum += 12 * (1L << unit);
    }
    return (unit + 1) * 8;
}

int main()
{
    int a;
    cin >> a;
    int p = minGridPerimeter(a);
    cout << "Perimeter:" << p << endl;
    return 0;
}