#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for (int index = 1; index < rowIndex + 1; index++)
            ans[index] = (long)ans[index - 1] * (rowIndex - index + 1) / index;
        return ans;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> out = sol->getRow(3);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}