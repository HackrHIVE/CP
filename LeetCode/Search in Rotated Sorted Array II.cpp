#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int r = nums.size() - 1, l = 0, mid = r / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if ((l == r) && (nums[l] != target))
                return false;

            if ((target == nums[mid]) || (target == nums[l]) || (target == nums[r]))
                return true;

            if ((target >= nums[r]) && (target < nums[mid]))
                r = mid - 1;

            else if ((target <= nums[l]) && (target > nums[mid]))
                l = mid + 1;

            else if ((target <= nums[l]) || (target >= nums[r]))
            {
                if (nums[mid] <= nums[r])
                {
                    r -= 1;
                    l += 1;
                }
                else
                    l = mid + 1;
            }
            else
            {
                if (target < nums[mid])
                    r = mid - 1;
                else if (target > nums[mid])
                    l = mid + 1;
            }
        }
        return false;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << sol->search(arr, target) << endl;
    return 0;
}