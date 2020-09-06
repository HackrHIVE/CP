#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countMatch(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int out = 0;
        int n = A.size();
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                int temp = 0;
                for (int i = x; i < n; i++)
                {
                    for (int j = y; j < n; j++)
                    {
                        if (A[i][j] == 1 && B[i - x][j - y])
                            temp++;
                    }
                }
                if (out < temp)
                    out = temp;
            }
        }
        return out;
    }
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        return max(countMatch(A, B), countMatch(B, A));
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> A = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> B = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    cout << sol->largestOverlap(A, B) << endl;
    return 0;
}