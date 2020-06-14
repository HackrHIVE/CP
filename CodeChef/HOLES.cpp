#include<iostream>
#include<cstring>
using namespace std;
int arr[26] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
int main(){
    int t;
    cin>>t;
    int x;
    string in;
    int count;
    while(t--){
        cin>>in;
        count = 0;
        for(int i=0;i<in.length();i++){
            x = (int)in[i]-65;
            count+=arr[x];
        }
        cout<<count<<endl;
    }
    return 0;
}