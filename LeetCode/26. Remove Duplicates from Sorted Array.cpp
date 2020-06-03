#include<bits/stdc++.h>
using namespace std;
void fun(vector<int>& n){
    bool found = false;
    for(int i=0;i<n.size()-1;i++){
        if(n[i] == n[i+1]){
            cout<<"Erasing : "<<n[i]<<endl;
            n.erase(n.begin()+i);
            found = true;
            break;
        }
    }
    for(auto x: n) cout<<x<<" ";
    cout<<endl;
    if(found) fun(n);
}
int removeDuplicates(vector<int> nums) {
    fun(nums);
    return nums.size()+1;
}
int main(){
    cout<<removeDuplicates(vector<int>{1,1,2});
    return 0;
}