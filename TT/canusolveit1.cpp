#include <bits/stdc++.h>
using namespace std;
struct arrayX{
    int val,index;
};
bool compare1(arrayX x,arrayX y){
    return (x.val>y.val && x.index>y.index);
}
bool compare2(arrayX x,arrayX y){
    return (x.val>y.val && x.index<y.index);
}
void printArrayX(arrayX* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i].index<<" : "<<arr[i].val<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,temp;
    cin>>t;
    while(t--){
        cin>>n;
        arrayX *arr = new arrayX[n];
        arrayX *arrTwo = new arrayX[n];
        // int *arr = new int[n];
        for(int i=0;i<n;i++) {
        	cin>>arr[i].val; 
			arr[i].index = i;
			arrTwo[i].index = i;
			arrTwo[i].val = arr[i].val; 
		}
//        cout<<"Arr\n";
//        printArrayX(arr,n);
//        cout<<"ArrTwo\n";
//        printArrayX(arrTwo,n);
        sort(arr,arr+n,compare1);
        sort(arrTwo,arrTwo+n,compare2);
//        cout<<"Arr\n";
//        printArrayX(arr,n);
//        cout<<"ArrTwo\n";
//        printArrayX(arrTwo,n);
        int finalMax = 0;
        int maxX = 0;
        for(int i=n-1;i>1;i--){
        	int temp = abs(arr[0].val - arr[i].val) + abs(arr[0].index - arr[i].index);
        	(temp>maxX)?maxX = temp:maxX = maxX;
		}
        int maxY = 0;
		for(int i=n-1;i>1;i--){
        	int temp = abs(arrTwo[0].val - arrTwo[i].val) + abs(arrTwo[0].index - arrTwo[i].index);
        	(temp>maxY)?maxY = temp:maxY = maxY;
		}
//        int max1 = arr[0].val - arr[n-1].val + arr[0].index - arr[n-1].index;
//        int max2 = arrTwo[0].val - arrTwo[n-1].val - arrTwo[0].index + arrTwo[n-1].index;
//        cout<<maxX<<endl<<maxY<<endl;
        finalMax = (maxX>maxY)?maxX:maxY;
        cout<<finalMax<<endl;
        delete []arr;
    }
    return 0;
}
