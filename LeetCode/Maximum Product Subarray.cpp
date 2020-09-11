#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int maxSub = nums[0];
        int minSub = nums[0];
        int maxProductSub = nums[0];

        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(minSub, maxSub);
            maxSub = max(maxSub * nums[i], nums[i]);
            minSub = min(minSub * nums[i], nums[i]);
            cout << "max: " << maxSub << endl;
            cout << "min: " << minSub << endl;
            maxProductSub = max(maxProductSub, maxSub);
        }

        cout << "max: " << maxSub << endl;
        cout << "min: " << minSub << endl;
        return maxProductSub;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> arr = {2, 3, -2, 4};
    cout << sol->maxProduct(arr) << endl;
    return 0;
}