#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    long int *req = new long int[n];
    long int *quantity = new long int[n];
    for(long int i=0;i<n;i++) cin>>req[i];
    for(long int i=0;i<n;i++) cin>>quantity[i];
    long int min = INT_MAX,div;
    for(long int i=0;i<n;i++){
        div = quantity[i]/req[i];
        if(div<min) min = div;
    }
    cout<<min<<endl;
    delete [] req;
    delete [] quantity;
    return 0;
}
