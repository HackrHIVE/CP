#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> umap;
    umap[0] = 1;
    umap[1] = 5;
    umap[2] = 3;
    umap[3] = 4;
    umap[4] = 6;
    map<int,int>::iterator it = umap.begin();
    int temp = 0;
    while(it != umap.end() && temp+1<umap.size()){
        cout<<it->first<<" "<<it->second<<endl;
        temp++;
        it++;
    }
    return 0;
}