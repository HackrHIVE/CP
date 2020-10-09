#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 7;
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    /*
    O(1) Space
    O(N) Time
    */
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int leftSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum -= arr[i];
        if (sum == leftSum)
        {
            cout << i << endl;
            break;
        }
        leftSum += arr[i];
    }

    /*
    Complexity for code below
    O(N) Space
    O(N) Time
    */
    /*
    int *left = new int[n];
    int *right = new int[n];
    left[0] = 0;
    right[n - 1] = 0;
    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] + arr[i - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] + arr[i + 1];
    for (int i = 0; i < n; i++)
    {
        if (left[i] == right[i])
        {
            cout << i << endl;
            break;
        }
    }
    */
    return 0;
}