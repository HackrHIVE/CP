/*
 * @File: 775. Global and Local Inversions.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Friday, 2nd October 2020 12:01:21 pm
 * @Last Modified: Friday, 2nd October 2020 12:42:31 pm
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIdealPermutation(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (abs(A[i] - i) > 1)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> arr = {1};
    cout << sol->isIdealPermutation(arr) << endl;
    return 0;
}