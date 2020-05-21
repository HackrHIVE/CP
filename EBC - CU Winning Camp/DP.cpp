#include<bits/stdc++.h>
using namespace std;
vector<long long int> arr(50,-1);
int calculateFib(int n){
    cout<<"n : "<<n<<endl;
    cout<<"arr : "<<arr[n]<<endl;
    if(arr[n] != -1) return arr[n];

    cout<<"Calculating for n-1 & n-2\n";
    arr[n] = calculateFib(n-1)+calculateFib(n-2);

    return arr[n];
}
int main(){
    int tillWhen;
    cin>>tillWhen;
    arr[0] = 0;
    arr[1] = 1;
    calculateFib(tillWhen-1);
    cout<<arr[tillWhen-1]<<endl;
    return 0;
}
/*
0 1 1 2 3 5
*/