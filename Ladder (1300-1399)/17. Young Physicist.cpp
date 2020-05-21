#include<iostream>
using namespace std;
struct Forces{
    int x,y,z;
};
int main(){
    int n;
    cin>>n;
    int sumX=0,sumY=0,sumZ=0;
    Forces *arr = new Forces[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y>>arr[i].z;
        sumX += arr[i].x;
        sumY += arr[i].y;
        sumZ += arr[i].z;
    }
    delete[] arr;
    if(sumX == 0 && sumY == 0 && sumZ == 0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
