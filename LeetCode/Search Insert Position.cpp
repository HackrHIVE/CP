#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> nums, int target)
{
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
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    cout << searchInsert(vector<int>{1, 3, 5, 6}, 0) << endl;
    return 0;
}