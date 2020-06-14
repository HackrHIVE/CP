#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t,n;
    int counter;
    cin>>t;
    while(t--){
        cin>>n;
        bool oddOrNot = (n%2 != 0);
        counter = 1;
        for(int i=0;i<n;i++){
            if(oddOrNot) for(int j=0;j<n;j++) cout<<counter++<<" ";
            else if(i%2 == 0) for(int j=0;j<n;j++) cout<<counter++<<" ";
            else for(int j=0;j<n;j++) cout<<counter--<<" ";
            cout<<endl;

            if(!oddOrNot){
                if(i%2 == 0) counter += n-1;
                else counter += n+1;
            }

        }
    }
    return 0;
}