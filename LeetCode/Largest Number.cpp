/*
 * @File: Largest Number.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Friday, 25th September 2020 9:40:22 pm
 * @Last Modified: Friday, 25th September 2020 9:48:25 pm
 */
#include <bits/stdc++.h>
using namespace std;
bool compare(int &x, int &y)
{
    long long int xy = stoll(to_string(x) + to_string(y));
    long long int yx = stoll(to_string(y) + to_string(x));
    return xy >= yx;
}
string largestNumber(const vector<int> &nums)
{
    int zero = 0;
    for (auto x : nums)
        if (x == 0)
            zero++;
    if (zero == nums.size())
        return "0";
    string ans = "";
    vector<int> B(nums);
    sort(B.begin(), B.end(), compare);
    cout << "sorted\n";
    for (auto val : B)
        ans += to_string(val);
    return (ans[0] == '0') ? "0" : ans;
}
int main()
{
    vector<int> in = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << largestNumber(in) << endl;
    return 0;
}