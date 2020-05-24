#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int> > out;
        
    int i=0,j=0;
    while(i<A.size() && j<B.size()){
        int lower = max(A[i][0], B[j][0]);
        int upper = min(A[i][1], B[j][1]);
        if(lower <= upper) out.push_back(vector<int>{lower,upper});
        if(A[i][1] < B[j][1]) i++;
        else j++;
    }
    
    return out;
}
int main(){
    vector<vector<int>> A;
    A.push_back(vector<int>{0,4});
    A.push_back(vector<int>{7,8});
    A.push_back(vector<int>{12,19});
    vector<vector<int>> B;
    B.push_back(vector<int>{0,10});
    B.push_back(vector<int>{14,15});
    B.push_back(vector<int>{18,20});
    
    /*
    [[0,4],[7,8],[12,19]]
    [[0,10],[14,15],[18,20]]    
    */

    vector<vector<int> > out = intervalIntersection(A,B);
    for(int i=0;i<out.size();i++){
        cout<<out[i][0]<<" : "<<out[i][1]<<endl;
    }
    return 0;
}