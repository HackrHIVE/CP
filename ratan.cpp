#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> *getdfs(vector<vector<int>> arr, int n, int st, int ed, bool *vis)
{
    // vector<int>ans;
    vis[st] = true;
    if (st == ed)
    {
        vector<int> *output = new vector<int>();
        output->push_back(ed);
        return output;
        // ans.pb(ed);
        // return ans;
    }
    //  for(int i=0;i<n;i++)
    for (auto i : arr[st])
    {
        if (i == st)
            continue;
        //  if(arr[st][i]==1){
        if (vis[i] == true)
            continue;
        //vis[i]=true;
        vector<int> *smallpath = getdfs(arr, n, i, ed, vis);
        if (smallpath != NULL)
        {
            smallpath->push_back(st);
            return smallpath;
        }
    }

    return NULL;
}

int main()
{
    int v, e; //tempX, tempY;
    cin >> v >> e;
    /*
    int *arr=new int[v];
    for(int i=0;i<v;i++){
        arr[i]=new int[v];
        for(int j=0;j<v;j++)
            arr[i][j]=0;
    }*/
    vector<vector<int>> edge(v);
    int v1, v2;
    while (e--)
    {
        cin >> v1 >> v2;
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
        //  edge[v1][v2] = 1;
        // edge[v2][v1] = 1;
    }
    int st, ed;
    cin >> st >> ed;
    bool *vis = new bool[v];
    for (int i = 0; i < v; i++)
        vis[i] = false;
    vector<int> *vec = getdfs(edge, v, st, ed, vis);

    if (vec != NULL)
        for (int i = 0; i < vec->size(); i++)
            cout << vec->at(i) << " ";

    return 0;
}