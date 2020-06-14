#include<iostream>
using namespace std;
class Solution{
    public:
    int arr[10000];
    Solution(){
        for(int i=0;i<10000;i++)arr[i] = 0;
    }
    int fact(int x){
        if(x>2){
            if(arr[x]!=0)
                return arr[x];
            else{
                int temp = x*fact(x-1);
                arr[x] = temp;
                return temp;
            }
        }
        return x;
    }
};
int main(){
    int t,n;
    cin>>t;
    Solution obj;
    while(t--){
        cin>>n;
        cout<<obj.fact(n)<<endl;
    }
    return 0;
}