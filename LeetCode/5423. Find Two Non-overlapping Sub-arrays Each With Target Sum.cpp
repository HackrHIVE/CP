#include <bits/stdc++.h>
using namespace std;
int mintargetOfLengths(vector<int> arr, int target)
{
    int n = arr.size();

    vector<int> total;
    int last = -1;
    for (int j = 0; j < arr.size(); j++)
    {

        int currtarget = 0;
        int res = 0;
        unordered_map<int, int> prevtarget;
        if(j > last) for (int i = j; i < n; i++)
        {
            currtarget += arr[i];
            res++;

            if (currtarget == target)
            {
                currtarget = 0;
                total.push_back(res++);
                last = i;
                break;
            }

            prevtarget[currtarget]++;
        }
    }

    if (total.size() < 2)
        return -1;

    if (total.size() == 2)
        return total[0] + total[1];

    sort(total.begin(), total.end());

    return total[0] + total[1];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    cout << mintargetOfLengths(vector<int>{1,6,1}, 7) << endl;
    return 0;
}