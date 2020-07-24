#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> neg;
    vector<int> pos;
    for (auto x : arr)
        (x < 0) ? neg.push_back(x) : pos.push_back(x);
    int i = 0;
    for (i = 0; i < neg.size(); i++)
        arr[i] = neg[i];
    for (int j = 0; i < n; j++, i++)
        arr[i] = pos[j];
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}