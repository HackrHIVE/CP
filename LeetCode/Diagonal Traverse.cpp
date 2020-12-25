/*
 * @File: Diagonal Traverse.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Friday, 25th December 2020 6:40:32 pm
 * @Last Modified: Friday, 25th December 2020 7:08:25 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return {};
        int m = matrix[0].size();
        vector<int> out(n * m, 0);
        bool upward = true;
        int i = 0, j = 0;
        int index = 0;
        while (i < n && j < m)
        {

            out[index++] = matrix[i][j];
            cout << matrix[i][j] << " => ";
            if (upward)
            {
                cout << i << "," << j << " was going up\n";
                if (i == 0 || j == m - 1)
                {
                    upward = !upward;
                    j == m - 1 ? i++ : j++;
                }
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                cout << i << "," << j << " was going down\n";
                if (i == n - 1 || j == 0)
                {
                    upward = !upward;
                    i == n - 1 ? j++ : i++;
                }
                else
                {
                    i++;
                    j--;
                }
            }
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> in = {
        {1, 2, 3, 10},
        {4, 5, 6, 11},
        {7, 8, 9, 12},
    };
    vector<int> out = sol->findDiagonalOrder(in);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}