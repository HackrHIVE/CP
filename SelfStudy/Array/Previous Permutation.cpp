#include <bits/stdc++.h>
using namespace std;
vector<int> prevPermOpt1(vector<int> &A)
{
    int n = A.size();
    for (int i = 0; i < n - 1; i++)
    {
        int maxDigit = -1;
        int maxVal = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[i] && A[j] > maxVal)
            {
                cout << "Found\ti:" << i << "\tj:" << j << endl;
                maxDigit = j;
                maxVal = A[j];
            }
        }
        if (maxDigit != -1)
        {
            cout << i << " " << maxDigit << endl;
            swap(A[i], A[maxDigit]);
            return A;
        }
    }
    return A;
}
int main()
{
    vector<int> arr = {3, 1, 3, 4};
    prevPermOpt1(arr);
    for (auto x : arr)
        cout << x;
    cout << endl;
    return 0;
}