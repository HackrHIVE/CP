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
    int *ar = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (i < k)
            ar[i] = arr[n - k + i];
        else
            ar[i] = arr[i - k];
    }
    cout << "New Array after " << k << " cirular rotations\n";
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