#include<bits/stdc++.h>
using namespace std;
int findLucky(vector<int>& arr) {
    unordered_map<int,int> mappy;
    for(int i=0;i<arr.size();i++){
        if(mappy.find(arr[i])==mappy.end())  mappy.insert(make_pair(arr[i],1));
        else mappy[arr[i]]++;
    }
    unordered_map<int,int>::iterator it = mappy.begin();
    int max = -1;
    while(it!=mappy.end()){
        if(it->first==it->second){
        	if(max<it->first) max = it->first;
        }
        it++;
    }
    return max;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> x({1,2,2,3,3,3});
    cout<<findLucky(x);
    return 0;
}
