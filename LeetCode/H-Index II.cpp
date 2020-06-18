#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        if (citations.size() == 0)
            return 0;
        int lo = 0;
        int hi = citations.size() - 1;
        int mid;
        int outH = INT_MIN;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            int tempH = citations.size() - mid;
            if (citations[mid] >= tempH)
            {
                //OK , we can go forward with this and move onto left side now. (to increase h)
                if (outH < tempH)
                    outH = tempH;
                hi = mid - 1;
            }
            else
            {
                //Oops, we gotta move onto right side now. (to reduce h)
                lo = mid + 1;
            }
        }
        if (outH == INT_MIN)
            return 0;
        return outH;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    Solution *sol = new Solution();
    vector<int> in = {0, 1, 3, 5, 6, 7, 8};
    cout << sol->hIndex(in) << endl;
    return 0;
}