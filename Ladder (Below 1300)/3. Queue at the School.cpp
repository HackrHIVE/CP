#include<iostream>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    string input;
    cin>>input;
    while(t--){
        for(int i=0;i<n-1;i++){
            if(input[i]=='B' && input[i+1]=='G'){
                input[i] = 'G';
                input[i+1] = 'B';
                i++;
            }
        }
    }
    cout<<input;
    return 0;
}
