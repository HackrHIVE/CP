#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> out;
        unordered_map<int, int> umap;
        for (auto x : nums)
            umap[x]++;
        for (auto x : umap)
        {
            if (x.second == 1)
                out.push_back(x.first);
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {1, 2, 1, 3, 2, 5};
    vector<int> out = sol->singleNumber(in);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}