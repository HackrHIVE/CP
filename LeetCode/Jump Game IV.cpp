#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        queue<int> q{{0}};
        const int n = arr.size();
        vector<int> visited(n, 0);
        visited[0] = 1;
        unordered_map<int, vector<int>> equals;
        for (int i = 0; i < n; i++)
            equals[arr[i]].push_back(i);
        for (int step = 0; !q.empty(); step++)
        {
            for (int i = q.size(); i > 0; i--)
            {
                auto cur = q.front();
                q.pop();
                if (cur == n - 1)
                    return step;
                auto &nexts = equals[arr[cur]];
                nexts.push_back(cur - 1);
                nexts.push_back(cur + 1);
                for (int next : nexts)
                    if (next >= 0 && next < n && !visited[next])
                        q.push(next), visited[next] = 1;
                nexts.clear();
            }
        }
        return n - 1;
    }
};
int main()
{
    Solution *sol = new Solution();
    // vector<int> in = {
    //     51, 64, -15, 58, 98, 31, 48, 72, 78, -63, 92, -5, 64, -64, 51, -48, 64, 48,
    //     -76, -86, -5, -64, -86, -47, 92, -41, 58, 72, 31, 78, -15, -76, 72, -5, -97,
    //     98, 78, -97, -41, -47, -86, -97, 78, -97, 58, -41, 72, -41, 72, -25, -76, 51,
    //     -86, -65, 78, -63, 72, -15, 48, -15, -63, -65, 31, -41, 95, 51, -47, 51, -41, -76,
    //     58, -81, -41, 88, 58, -81, 88, 88, -47, -48, 72, -25, -86, -41, -86, -64, -15, -63};
    vector<int> in = {-76, 3, 66, -32, 64, 2, -19, -8, -5, -93, 80, -5, -76, -78, 64, 2, 16};
    cout << sol->minJumps(in) << endl;
    return 0;
}