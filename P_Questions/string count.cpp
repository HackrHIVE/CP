#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int naturalSorted(char *input1)
{
    char *s = input1;
    int n = strlen(s);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (s[i] > s[j])
                arr[i] = max(arr[i], arr[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i]);
    }
    return ans;
}
int main()
{
    // string s;
    // cin >> s;

    // int maxcount = 0;
    // int n = sizeof(s);
    // for (int i = 0; i < n - 1; i++)
    // {
    //     int count = 0;
    //     int temp = s[i];
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int temp2 = s[j];
    //         if (temp2 > temp)
    //         {
    //             count++;
    //         }
    //     }
    //     if (maxcount < count)
    //     {
    //         maxcount = count;
    //     }
    // }
    // cout << maxcount;
    cout << naturalSorted("abcdg");
    return 0;
}