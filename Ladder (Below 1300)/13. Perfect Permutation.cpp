#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%2==0){
        for(int i=1;i<=n;i++){
            (i%2==0) ? cout<<i-1<<" " : cout<<i+1<<" ";
        }
    }
    else cout<<"-1";
    return 0;
}