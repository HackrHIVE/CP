#include<iostream>
using namespace std;
int main(){
    char *arr = new char[1000];
    cin>>arr;
    if(int(arr[0])>=97 && int(arr[0])<=122)
        arr[0] = (char)(int(arr[0])-32);
    cout<<arr;
    delete[] arr;
    return 0;
}
