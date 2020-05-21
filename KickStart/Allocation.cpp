#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int *arr;
	int n,budget,houses;
	cin>>t;
	for(int j=1;j<=t;j++){
		houses = 0;
		cin>>n>>budget;
		arr = new int[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			if(budget>=arr[i]){
				budget -= arr[i];
				houses++;
			}else break;
		}
		cout<<"Case #"<<j<<": "<<houses<<endl;
		delete []arr;
	}
	return 0;
}
