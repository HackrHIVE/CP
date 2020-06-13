#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> wt, vector<int> val, int W, int n)
{
    if (n == 0 || W <= 0)
        return 0;
    if (wt[n - 1] > W)
        return knapsack(wt, val, W, n - 1);
    else
        return max(knapsack(wt, val, W, n - 1), val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1));
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int W = 11, n = 5;
    vector<int> wt = {1, 2, 5, 6, 7};
    vector<int> val = {1, 6, 18, 22, 28};
    cout << knapsack(wt, val, W, n) << endl;
    return 0;
}