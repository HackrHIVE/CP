#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bSearch(vector<int> &arr, int val)
    {
        int lo = 0;
        int hi = arr.size() - 1;
        int mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (arr[mid] == val)
            {
                while (mid > 0)
                    if (arr[mid - 1] == val)
                        mid--;
                    else
                        break;
                return mid;
            }
            if (arr[mid] > val)
            {
                if (mid > 0)
                    if (arr[mid - 1] < val)
                        return mid;
                hi = mid - 1;
            }
            else if (arr[mid] < val)
                lo = mid + 1;
        }
        return mid;
    }
    int hIndex(vector<int> &citations)
    {
        if (citations.size() == 0)
            return 0;
        if (citations.size() == 1)
            return citations[0] == 0 ? 0 : 1;
        vector<int> arr = citations;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int N = n;
        while (n > 0)
        {
            int index = bSearch(arr, n);
            int count = N - index;
            if (count >= n)
                break;
            n--;
        }
        return n > arr[N - 1] ? 0 : n;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {7, 10, 10, 1, 1};
    cout << sol->hIndex(in) << endl;
    return 0;
}