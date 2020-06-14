#include <bits/stdc++.h>
using namespace std;

int minDays(vector<int> bloomDay, int m, int k)
{
    if (m * k > bloomDay.size())
        return -1;
    
    vector<int> sorted = bloomDay;
    sort(sorted.begin(),sorted.end());

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    cout << minDays(vector<int>{7, 7, 7, 7, 12, 7, 7}, 2, 3) << endl;
    return 0;
}