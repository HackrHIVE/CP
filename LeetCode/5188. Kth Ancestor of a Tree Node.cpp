#include <bits/stdc++.h>
using namespace std;
class TreeAncestor1 {
public:
    vector<int> parents;
    TreeAncestor1(int n, vector<int> parent)
    {
        parents = parent;
    }

    int getKthAncestor(int node, int k)
    {
        while (node > 0 && k > 0)
        {
            node = parents[node];
            k--;
        }
        if (k > 0)
            return -1;
        return node;
    }
};
class TreeAncestor
{
public:
    vector<vector<int>> parents;
    TreeAncestor(int n, vector<int> parent)
    {
        for (int i = 0; i < parent.size(); i++)
        {
            int x = parent[i];
            vector<int> temp;
            temp.push_back(i);
            if (i != 0)
                temp.insert(temp.end(), parents[x].begin(), parents[x].end());

            parents.push_back(temp);
        }
        for (auto x : parents)
        {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
    }

    int getKthAncestor(int node, int k)
    {
        if (parents[node].size() <= k)
            return -1;
        return parents[node][k];
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    TreeAncestor1 *obj = new TreeAncestor1(9, vector<int>{-1, 0, 0, 1, 1, 2, 2, 3, 3});
    cout << obj->getKthAncestor(3, 1) << endl;
    cout << obj->getKthAncestor(5, 2) << endl;
    cout << obj->getKthAncestor(6, 3) << endl;
    cout << obj->getKthAncestor(3, 1) << endl;
    cout << obj->getKthAncestor(3, 3) << endl;
    return 0;
}