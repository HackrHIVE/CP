#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,temp;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        int sum = 0;
        int rowCount = 0,colCount = 0;
        vector<set<int> > setVec(n);
        for(int j=0;j<n;j++){
            set <int> setty;
            for(int k=0;k<n;k++){
                cin>>temp;
                setVec[k].insert(temp);
                if(k==j) sum += temp;
                setty.insert(temp);
            }
            if(setty.size()==n) continue;
            else rowCount++;
        }
        for(int j=0;j<n;j++){
            if(setVec[j].size()==n) continue;
            colCount++;
        }
        cout<<"Case #"<<i<<": "<<sum<<" "<<rowCount<<" "<<colCount<<endl;
    }
    return 0;
}
