#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cout << "Enter k(number of rotations) : ";
    cin >> k;
    int k1 = k;
    k %= n;
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (i < k)
            ar[n - k + i] = arr[i];
        else
            ar[i - k] = arr[i];
    }
    cout << "New Array after " << k1 << " cirular rotations\n";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << endl;
    delete[] arr;
    return 0;
}

/*
arr => 1 2 3 4 5 6
k => 3
6 1 2 3 4 5
5 6 1 2 3 4
ar  => 4 5 6 1 2 3
*/