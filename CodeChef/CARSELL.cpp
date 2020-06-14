#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
	int t,n,temp;
	long long int profit;
	cin>>t;
	while(t--){
		cin>>n;
		vector <int> arr;
		for(int i=0;i<n;i++){
			cin>>temp;
			arr.push_back(temp);
		}
		profit = 0;
		sort(arr.begin(),arr.end(),greater<int>());
		for(int i=0;i<n;i++){
			if(arr[i]-i>0 ){
				arr[i] -= i;
				profit = profit%mod + arr[i]%mod;
//				profit += arr[i];	
			}
		}
		cout<<profit%mod<<endl;
	}
	return 0;
}
