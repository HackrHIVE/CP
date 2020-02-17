#include<iostream>
using namespace std;
int nextIndex(int i,int size){
    if(i+1<size) return i+1;
    return 0;
}
int breakArr(int *arr,int k,int size){
    if(size==k) return k;
    int elCount = 0;
    int sum = 0;
    int max = arr[0];
    for(int i=0;i<size;i++){
        int index = i;
        while(elCount!=k){
            if(max<arr[index]) max = arr[index];
            elCount++;
            index = nextIndex(index,size);
        }
        sum += max;
        elCount = 0;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    
    for(int i=0;i<n;i++) arr[i]=i+1;
    int k;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>k;
        sum += breakArr(arr,k,n);
    }
    cout<<sum;
    return 0;
}
