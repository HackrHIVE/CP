#include<iostream>
using namespace std;
int main(){
    string a,b;
    cin>>a;
    cin>>b;
    int x,y;
    for(int i=0;a[i]!=0;i++){
        x = int(a[i])-48;
        y = int(b[i])-48;
        (abs(x-y)==1) ? a[i]='1' : a[i]='0';
    }
    cout<<a;
    return 0;
}