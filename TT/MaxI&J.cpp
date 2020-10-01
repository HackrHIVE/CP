#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int index = 0;
    int max = 0;
    int invertIndex = n - 1;
    while (index < n - 1)
    {
        if (index >= invertIndex)
        {
            invertIndex = n - 1;
            index++;
            continue;
        }
        if (arr[index] > arr[invertIndex])
        {
            max = invertIndex - index;
            break;
        }
        else
            invertIndex--;
    }
    cout << max;
    return 0;
}
