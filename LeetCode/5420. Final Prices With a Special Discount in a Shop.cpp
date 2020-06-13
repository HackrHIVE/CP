#include <bits/stdc++.h>
using namespace std;
vector<int> finalPrices(vector<int> prices)
{
    vector<int> out;
    for (int i = 0; i < prices.size(); i++)
    {
        int temp = -1;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[j] <= prices[i])
            {
                temp = prices[j];
                break;
            }
        }
        if (temp == -1)
        {
            out.push_back(prices[i]);
            continue;
        }
        else
            out.push_back(prices[i] - temp);
    }
    return out;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    vector<int> out = finalPrices(vector<int>{10,1,1,6});
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}