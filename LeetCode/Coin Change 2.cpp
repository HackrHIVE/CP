#include <bits/stdc++.h>
using namespace std;
// vector<int> arr;
// vector<unordered_map<int,int> > sols;
int change(int t, vector<int> coins)
{
    /*
    //BackTracking (TLE)
    if(amount == 0){
        unordered_map<int,int> temp;
        for(auto x:arr) temp[x]++;
        for(auto x:sols){
            if(x == temp){
                return 1;
            }
        }
        sols.push_back(temp);
        return 1;
    }
    else if(amount < 0) return 0;
    int total = 0;
    for (auto x : coins)
    {
        arr.push_back(x);
        total += change(amount-x,coins);
        arr.pop_back();
    }
    return sols.size();
    */
   //DP
    int dp[t + 1] = { 1 };
    for (auto c : coins)
    for (auto j = c; j <= t; ++j){
        dp[j] += dp[j - c];
        cout<<j<<" : "<<dp[j]<<endl;
    }
    return dp[t];
}
int main()
{
    cout << change(5, vector<int>{1,2,5}) << endl;
    return 0;
}
static bool fastio = []() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return false;
}();