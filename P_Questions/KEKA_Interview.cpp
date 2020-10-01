#include <bits/stdc++.h>
using namespace std;
void spiral(vector<int> &A)
{
    int n = sqrt(A.size());
    vector<vector<int>> B(n, vector<int>(n, 0));
    int index = 0;
    int r1 = 0;
    int r2 = n - 1;
    int c1 = 0;
    int c2 = n - 1;
    while (r1 <= r2 && c1 <= c2 && index < A.size())
    {
        for (int i = c1; i <= c2; i++)
            B[r1][i] = A[index++];
        r1++;
        for (int i = r1; i <= r2; i++)
            B[i][c2] = A[index++];
        c2--;
        for (int i = c2; i >= c1; i--)
            B[r2][i] = A[index++];
        r2--;
        for (int i = r2; i >= r1; i--)
            B[i][c1] = A[index++];
        c1++;
    }
    for (auto x : B)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}
void findMaxAverage(vector<float> &nums)
{
    double maxOut = INT_MIN;
    for (int j = 2; j < nums.size(); j++)
    {
        double max_sum = accumulate(nums.begin(), nums.begin() + j, 0);
        double prev_sum = max_sum;
        for (auto i = j; i < nums.size(); ++i)
        {
            double next_sum = prev_sum - nums[i - j] + nums[i];
            max_sum = max(max_sum, next_sum);
            prev_sum = next_sum;
        }
        maxOut = max(max_sum / j, maxOut);
        cout << maxOut << endl;
    }
    cout << maxOut << endl;
}
int main()
{
    vector<int> in = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    spiral(in);
    return 0;
}