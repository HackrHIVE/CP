#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int row = A.size();
        if (row == 0)
            return A;
        int col = A[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                A[i][j] = 1 - A[i][j];
            int j = 0, k = col - 1;
            while (j < k)
                swap(A[i][j++], A[i][k--]);
        }
        return A;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> in = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
    vector<vector<int>> out = sol->flipAndInvertImage(in);
    for (auto x : out)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}