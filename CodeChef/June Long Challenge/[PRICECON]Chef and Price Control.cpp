#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t;
    cin>>t;
    int n,k;
    long int loss;
    int *arr;
    while(t--){
        cin>>n>>k;
        arr = new int[n];
        loss = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i] > k) loss += (arr[i]-k);
        }
        cout<<loss<<endl;
        delete []arr;
    }
    return 0;
}