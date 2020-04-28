//#include<bits/stdc++.h>
//using namespace std;
//// int* performOp1(int *arr,int b){
////     for(int i=0;i<b;i++) arr[i] = 1-arr[i];
////     return arr;
//// }
//// int* performOp2(int *arr,int b){
////     int mid;
////     mid = b/2-1;
////     for(int i=0;i<=mid;i++){
////         int temp = arr[b-i];
////         arr[i-b] = arr[i];
////         arr[i] = temp;
////     }
////     return arr;
//// }
//// int* performOp3(int *arr,int b){
////     arr = performOp1(arr,b);
////     arr = performOp2(arr,b);
////     return arr;
//// }
//// int* performOp4(int *arr,int b){
////     return arr;
//// }
//int main(){
//    int t,b;
//    cin>>t>>b;
//    int *arr = new int[b];
//    // int *arr1 = new int[b];
//    // int *arr2 = new int[b];
//    // int *arr3 = new int[b];
//    for(int i=1;i<=t;i++){
//        int input;
//        int index = 0;
//        int query = 1;
//        while(query<=150 && index<b){
//        	cout<<"Query : "<<query<<" --> ";
//            if(query%10 == 1){
//            	cout<<" mischeif\n";
//            cout<<"index : "<<index<<endl;
//            cin>>input;
//            cout<<"input : "<<input<<endl;
//                query++;
//                continue;
//            }
//            cout<<"index : "<<index<<endl;
//            cin>>input;
//            cout<<"input : "<<input<<endl;
//            
//            arr[index] = input;
//            index++;
//            query++;
//        }
//        for(int j=0;j<b;j++) cout<<arr[j];
//        
//        char x;
//        cin>>x;
//        if(x=='Y') continue;
//        else break;
//        delete[] arr;
//        // delete[] arr2;
//        // delete[] arr3;
//        // delete[] arr4;
//    }
//    return 0;
//}

#include<iostream>
using namespace std;
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t,b;
    cin>>t>>b;
    for(int i=1;i<=t;i++){
        int *arr = new int[b];
        int input;
        int index = 0;
        int query = 1;
        while(query<=150 && index<b){
            if(query%10 == 1){
                cout<<index;
                fflush(stdout);
                cin>>input;
                query++;
                continue;
            }
            cout<<index;
            fflush(stdout);
            cin>>input;
            arr[index] = input;
            index++;
            query++;
        }
        for(int j=0;j<b;j++) cout<<arr[j];
        char x;
        fflush(stdout);
        cin>>x;
        if(x=='Y') continue;
        else break;
        delete[] arr;
    }
    return 0;
}
