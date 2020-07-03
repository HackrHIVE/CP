#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> prisonAfterNDays(vector<int> &cells, int n)
    {
        vector<int> cellS(8);
        n = (n % 14 == 0) ? 14 : n % 14;
        while (n--)
        {
            for (int i = 1; i < 7; i++)
            {
                cellS[i] = (cells[i - 1] == cells[i + 1]) ? 1 : 0;
            }
            cells = cellS;
        }
        return cells;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> in = {1, 0, 0, 1, 0, 0, 1, 0};
    vector<int> out = sol->prisonAfterNDays(in, 1000000000);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}