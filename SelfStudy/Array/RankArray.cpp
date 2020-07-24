#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<int> od;
    unordered_map<int, int> imap;
    for (int i = 0; i < n; i++)
    {
        od.insert(arr[i]);
        imap[arr[i]] = i;
    }
    int rank = 1;
    for (auto x : od)
        arr[imap[x]] = rank++;
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}