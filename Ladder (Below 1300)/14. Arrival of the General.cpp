#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    int lowIndex=-1,highIndex=n;
    int lowest,highest;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // if(i==0){
        //     lowIndex = 0;
        //     highIndex = 0;
        //     lowest = arr[0];
        //     highest = arr[0];
        // }
        // else{
            
        // }
    }
    lowest = 101;
    highest = -1;
    lowIndex = -1;
    highIndex = n;
    // cout<<"LOWEST : "<<lowest<<endl;
    // cout<<"HIGHEST : "<<highest<<endl;
    // cout<<"highIndex : "<<highIndex<<endl;
    // cout<<"lowIndex : "<<lowIndex<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==highest){
            // cout<<"FOUND SAME HIGHEST"<<endl;
            if(i<highIndex){
                highIndex = i;
                // cout<<"highIndex : "<<highIndex<<endl;
            }
        }
        else if(arr[i]>highest){
            highIndex = i;
            highest = arr[i];
            // cout<<"highIndex : "<<highIndex<<endl;
        }

        if(arr[i]==lowest){
            // cout<<"FOUND SAME LOWEST"<<endl;
            if(i>lowIndex){
                lowIndex = i;
                // cout<<"lowIndex : "<<lowIndex<<endl;
            }
        }
        else if(arr[i]<lowest){
            lowIndex = i;
            lowest = arr[i];
            // cout<<"lowIndex : "<<lowIndex<<endl;
        }
        
    }
    if(highIndex>lowIndex){
        cout<<n-lowIndex-2+highIndex;
    }
    else cout<<n-lowIndex-1+highIndex;
    return 0;
}