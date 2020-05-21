/*
https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/pop-up-orientation-de6cf0ee/
*/
#include<iostream>
using namespace std;
int main(){
    int t;
    int x,y,l,m,a,b;
    cin>>t;
    while(t--){
        cin>>x>>y>>l>>m>>a>>b;
        if(x-a>=l && b>=m){
            cout<<"bottom-right";
        }
        else if(a>=l && b>=m){
            cout<<"bottom-left";
        }
        else if(x-a>=l && y-b>=m){
            cout<<"top-right";
        }
        else if(a>=l && y-b>=m){
            cout<<"top-left";
        }
        cout<<endl;
    }
    return 0;
}