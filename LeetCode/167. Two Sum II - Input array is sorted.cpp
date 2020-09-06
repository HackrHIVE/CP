#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int lo = 0;
        int hi = n - 1;
        while (lo < hi)
        {
            int tempSum = numbers[lo] + numbers[hi];
            if (tempSum > target)
                hi--;
            else if (tempSum < target)
                lo++;
            else
                return {lo + 1, hi + 1};
        }
        return {};
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {2, 3, 4};
    vector<int> out = sol->twoSum(in, 6);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}