#include<iostream>
using namespace std;
bool checkPrime(int x){
    int m = x/2;
    for(int  i= 2; i <= m; i++) if(x % i == 0) return false;
    return true;
}
int main(){
    int m,n;
    cin>>n>>m;
    int next = -1;
    for(int i=n+1;i<=m;i++){
        if(checkPrime(i)){
            next = i;
            break;
        }
    }
    if(next!=-1) (next==m) ? cout<<"YES" : cout<<"NO";
    else cout<<"NO";
    return 0;
}