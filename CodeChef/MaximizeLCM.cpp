#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	if(y==0) return x; return gcd(y,x%y);	
}
int main(){
	int t;
	int n,m;
	int *arr;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int *lcm;
	cin>>t;
	while(t--){
		cin>>n>>m;
		arr = new int[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		lcm = new int[m+1];
		int lcmX = arr[0];
		for(int i=1;i<n;i++){
			lcmX = (arr[i]*lcmX)/gcd(arr[i],lcmX);
		}
		int newI = 0;
		int max = 0;
		for(int i=1;i<=m;i++){
			int temp = (lcmX*i)/gcd(lcmX,i);
			if(max<temp && newI<i){
				max = temp;
				newI = i;
			}
		}
		cout<<newI<<endl;
		delete []arr;
		delete []lcm;
	}
	return 0;
}


