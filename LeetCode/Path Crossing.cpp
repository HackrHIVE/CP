#include <bits/stdc++.h>
using namespace std;
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
class Solution
{
public:
    bool goOn(string path, int index, int x, int y, unordered_map<pair<int, int>, bool, hash_pair> &vis)
    {
        if (vis.find({x, y}) != vis.end())
            return true;
        if (index == path.size())
            return false;
        vis[{x, y}] = true;
        if (index == path.size())
            return false;
        if (path[index] == 'N')
            y++;
        if (path[index] == 'S')
            y--;
        if (path[index] == 'E')
            x++;
        if (path[index] == 'W')
            x--;
        return goOn(path, index + 1, x, y, vis);
    }
    bool isPathCrossing(string path)
    {
        unordered_map<pair<int, int>, bool, hash_pair> vis;
        return goOn(path, 0, 0, 0, vis);
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->isPathCrossing("SN") << endl;
    return 0;
}