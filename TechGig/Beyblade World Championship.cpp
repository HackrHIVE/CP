#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n;
    int wins;
    int minI;
    int *arr;
    int *opp;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        arr = new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        opp = new int[n];
        for(int i=0;i<n;i++) cin>>opp[i];
        minI = 0;
        wins = 0;
        sort(arr,arr+n);
        sort(opp,opp+n);
        for(int i=0;i<n;i++){
            if(arr[i]>opp[minI]){
                wins++;
                minI++;
            }
        }
        delete []arr;
        delete []opp;
        cout<<wins<<endl;
    }
    return 0;
}
/*
3 6 7 5 3 5 6 2 9 1 
2 7 0 9 3 6 0 6 2 6 

1 2 3 3 5 5 6 6 7 9
0 0 2 2 3 6 6 6 7 9

1 2 3 3 5 - - - 7 9
0 0 2 2 3 - - - 6 7
*/