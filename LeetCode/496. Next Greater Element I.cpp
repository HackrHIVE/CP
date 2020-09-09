/*
 * @File: 496. Next Greater Element I.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 10th September 2020 12:46:11 am
 * @Last Modified: Thursday, 10th September 2020 1:03:41 am
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> umap;
        int n = nums2.size();
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            while (j < n)
                if (nums2[j] < nums2[i])
                    j++;
                else
                    break;
            if (j == n)
                umap[nums2[i]] = -1;
            else
                umap[nums2[i]] = nums2[j];
        }
        if (n > 0)
            umap[nums2[n - 1]] = -1;
        vector<int> out;
        for (int i = 0; i < nums1.size(); i++)
            out.push_back(umap[nums1[i]]);
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> vec1 = {};
    vector<int> vec2 = {};
    vector<int> out = sol->nextGreaterElement(vec1, vec2);
    for (auto x : out)
        cout << x << " ";
    cout << endl;
    return 0;
}