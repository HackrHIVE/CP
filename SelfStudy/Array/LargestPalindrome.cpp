#include <iostream>
#include <vector>
using namespace std;
bool checkPal(int n)
{
    vector<int> num;
    while (n > 9)
    {
        num.push_back(n % 10);
        n = n / 10;
    }
    num.push_back(n);
    int size = num.size();
    int i;
    for (i = 0; i < size / 2; i++)
    {
        if (num[i] == num[size - i - 1])
            continue;
        else
            break;
    }
    return i == size / 2;
}
int main()
{
    int n;
    cin >> n;
    int maxPal = INT_MIN;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (auto x : arr)
        if (checkPal(x))
            maxPal = max(maxPal, x);
    if (maxPal == INT_MIN)
        cout << "No Palindrome present in the array\n";
    else
        cout << "Largest Palindrome is " << maxPal << endl;
    return 0;
}