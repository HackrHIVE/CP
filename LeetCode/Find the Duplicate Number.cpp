#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (auto x : nums)
            umap[x]++;
        for (auto x : umap)
            if (x.second > 1)
                return x.first;
        return -1;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    Solution *sol = new Solution();
    vector<int> in = {26, 2, 9, 20, 31, 7, 14, 32, 37, 15, 29, 6, 12, 38, 48, 22, 19, 45, 42, 40, 1, 12, 25, 36, 39, 30, 35, 4, 27, 12, 49, 16, 47, 3, 44, 41, 8, 17, 21, 23, 10, 43, 12, 34, 24, 28, 33, 13, 46, 11};
    cout << sol->findDuplicate(in) << endl;
    return 0;
}