#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
            {
            }
            else if (nums[lo] > target && nums[mid] > target)
            {
                mid = lo + 1;
                continue;
            }
            else if(nums[hi])
        }
    }
};
int main()
{
    Solution *sol = new Solution();
    return 0;
}
/*
4 5 6 7 0 1 2
0 1 2 3 4 5 6
*/