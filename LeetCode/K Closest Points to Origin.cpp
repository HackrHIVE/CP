#include<bits/stdc++.h>
using namespace std;
bool sortMyWayBitch(vector<int> x,vector<int> y){
    int disX = (x[0]*x[0])+(x[1]*x[1]);
    int disY = (y[0]*y[0])+(y[1]*y[1]);

    return disX < disY;
}
vector<vector<int>>kClosest(vector<vector<int>>points,int K){
    sort(points.begin(),points.end(),sortMyWayBitch);
    vector<vector<int>> out(points.begin(),points.begin()+K);
    return out;
}
int main(){
    vector<vector<int>> out = kClosest(
        vector<vector<int>>{{8,-1},{-4,10},{0,1},{7,-8},
        {-3,-10},{-2,-3},{0,3}},6);

    for(auto x: out){
        cout<<x[0]<<":"<<x[1]<<endl;
    }
    return 0;
}