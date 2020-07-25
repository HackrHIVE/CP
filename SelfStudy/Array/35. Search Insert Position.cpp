#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        //Naive - O(N)
        int out = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target)
                break;
            if (nums[i] < target || nums[i] == target)
                out = i;
        }
        if (nums[out] == target || nums[out] > target)
            return out;
        return out + 1;
    }
    int searchInsertOptimized(vector<int> &arr, int target)
    {
        //BinarySearch - O(logN)
        int lo = 0;
        int hi = arr.size() - 1;
        int mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
            {
                if (arr[mid] - 1 == target)
                {
                    if (mid > 0)
                    {
                        if (arr[mid - 1] == target)
                            return mid - 1;
                        return mid;
                    }
                    return mid;
                }
                else
                {
                    hi = mid - 1;
                    continue;
                }
            }
            else if (arr[mid] < target)
            {
                if (arr[mid] + 1 == target)
                    return mid + 1;
                else
                {
                    lo = mid + 1;
                    continue;
                }
            }
        }
        return (arr[mid] < target) ? mid + 1 : mid;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {2, 3, 4, 8, 9};
    cout << sol->searchInsertOptimized(in, 6) << endl;
    return 0;
}