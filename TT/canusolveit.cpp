#include<iostream>
#include<algorithm>
using namespace std;
//struct arrayX{
//    int index;
//    int value;
//};
//bool compare(arrayX x,arrayX y){
//    return x.index>y.index && x.value>=y.value;
//}
int main(){
    int t,n,temp;
    cin>>t;
    while(t--){
//        cin>>n;
//        arrayX *arr = new arrayX[n];
//        for(int i=0;i<n;i++){
//            cin>>arr[i].value;
//            arr[i].index = i;
//        }
//        sort(arr,arr+n,compare);
//        cout<<abs(arr[0].index-arr[n-1].index)+abs(arr[0].value-arr[n-1].value)<<endl;  
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int max=0;
        for(int i=0;i<n;i++){
        	for(int j=i;j<n;j++){
        		if(i==j) continue;
        		temp = abs(j-i)+abs(arr[j]-arr[i]);
        		if(temp>max) max = temp;
			}
		}
		cout<<max<<endl;
    }
    return 0;
}
