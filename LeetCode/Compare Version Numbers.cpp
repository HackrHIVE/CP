#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> rev1;
        vector<int> rev2;
        istringstream f(version1);
        istringstream g(version2);
        string s;
        while (getline(f, s, '.'))
            rev1.push_back(stoi(s));
        while (getline(g, s, '.'))
            rev2.push_back(stoi(s));
        while (rev1.size() > rev2.size())
            rev2.push_back(0);
        while (rev1.size() < rev2.size())
            rev1.push_back(0);
        int index = 0;
        while (index < rev1.size())
        {
            if (rev1[index] > rev2[index])
                return 1;
            else if (rev1[index] < rev2[index])
                return -1;
            index++;
        }
        return 0;
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << sol->compareVersion("1.0", "1.0.0") << endl;
    return 0;
}