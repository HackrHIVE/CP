#include<bits/stdc++.h>
using namespace std;
struct Time{
    int s,e;
    int order;
    char jobHandler;
};
bool cmpByStartingTime(Time x,Time y){
    return x.s<y.s;
}
bool cmpByOrder(Time x,Time y){
    return x.order<y.order;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    bool j=false,c=false;
    bool inevitableHasHappened = false;
    int jEnd = 0,cEnd = 0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        vector <Time> arr(n);
        for(int j=0;j<n;j++){
            cin>>arr[j].s>>arr[j].e;
            arr[j].order = j;
        }
        c = false;
        j = false;
        cEnd = 0;
        jEnd = 0;
        inevitableHasHappened = false;
        sort(arr.begin(),arr.end(),cmpByStartingTime);
        arr[0].jobHandler = 'C';
        c = true;
        cEnd = arr[0].e;
        for(int j=1;j<n;j++){
            if(arr[j].s<cEnd && arr[j].s<jEnd){
                inevitableHasHappened = true;
                break;
            }
            if(arr[j].s>=cEnd){
                arr[j].jobHandler = 'C';
                cEnd = arr[j].e;
                continue;
            }
            else if(arr[j].s>=jEnd){
                arr[j].jobHandler = 'J';
                jEnd = arr[j].e;
                continue;
            }
        }
        if(inevitableHasHappened){
            cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
            continue;
        }
        sort(arr.begin(),arr.end(),cmpByOrder);
        cout<<"Case #"<<i<<": ";
        for(int j=0;j<n;j++) cout<<arr[j].jobHandler;
        cout<<endl;
    }
    return 0;
}
