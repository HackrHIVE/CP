#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &nums)
{
    int lo = 0;
    int i = 0;
    int hi = nums.size() - 1;
    while (i <= hi)
    {
        if (nums[i] == 0)
        {
            nums[i] = 1;
            nums[lo] = 0;
            i++;
            lo++;
        }
        else if (nums[i] == 2)
        {
            nums[i] = nums[hi];
            nums[hi] = 2;
            hi--;
        }
        else
            i++;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    vector<int> nums{1, 0, 2, 0, 2, 1, 1, 0, 2};
    sortColors(nums);
    for (auto x : nums)
        cout << x << " ";
    return 0;
}