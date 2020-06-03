#include<bits/stdc++.h>
using namespace std;
bool canBeEqual(vector<int> target, vector<int> arr) {
    unordered_map<int,int> umap1;
    unordered_map<int,int> umap2;
    
    for(auto x: target) umap1[x]++;
    for(auto x: arr) umap2[x]++;
    
    unordered_map<int,int>::iterator it = umap1.begin();

    while(it != umap1.end()){
        cout<<it->first<<endl;
        if(umap2.find(it->first) != umap2.end()){
            if(umap2[it->first] == it->second){
                it++;
                continue;
            }
            else return false;
        }
        else return false;
        it++;
    }
    
    return true;
}
int main(){
    cout<<canBeEqual(vector<int>{1,2,3,4},vector<int>{2,4,1,3})<<endl;
    return 0;
}