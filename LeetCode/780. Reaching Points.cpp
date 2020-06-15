#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool reachingPoints(long int sx, long int sy, long int tx, long int ty)
    {
        if (sx > tx || sy > ty)
            return false;
        while (tx > 0 && ty > 0)
        {
            cout << "tx : " << tx << "\tty : " << ty << endl;
            if (tx > ty)
            {
                int T = (tx - sx) / ty;
                if (T == 0)
                    T++;
                tx -= ty * T;
            }
            else
            {
                int T = (ty - sy) / tx;
                if (T == 0)
                    T++;
                ty -= tx * T;
            }
            if (sx > tx || sy > ty)
                return false;
            if (tx == sx && ty == sy)
                return true;
        }
        return false;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    Solution *sol = new Solution();
    cout << sol->reachingPoints(35, 13, 455955547, 420098884) << endl;
    return 0;
}