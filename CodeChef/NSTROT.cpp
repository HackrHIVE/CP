#include<bits/stdc++.h>
using namespace std;
int log2(int x){
	if(x<=1) return 0;
	return log2(floor(x/2))+1;
}
int fn(int *arr1,int *arr2,int n){
	int *tempX = new int[n+1];
	int *tempY = new int[n+1];
	for(int i=0;i<n;i++){
		tempX[arr1[i]] = i;
	}
	for(int i=0;i<n;i++){
		tempY[arr2[i]] = i;
	}
	int ret = 0;
	for(int i=1;i<=n;i++){
		ret += log2(abs(tempX[i]-tempY[i]));
	}
	return ret;
}
int main(){
	int t,n,v;
	cin>>t;
	int *p,*q;
	cout<<"log2(1) : "<<log2(1)<<endl;
	cout<<"log2(2) : "<<log2(2)<<endl;
	cout<<"log2(3) : "<<log2(3)<<endl;
	cout<<"log2(4) : "<<log2(4)<<endl;
	while(t--){
		cin>>n>>v;
		p = new int[n];
		q = new int[n];
		for(int i=0;i<n;i++) cin>>p[i];
		for(int i=0;i<n;i++) cin>>q[i];
		int res = 1;
		for(int i=0;i<v;i++){
			if(i==0) res *= fn(p,q,n);
			int *temp = new int[i];
			int *r = new int[n];
			for(int j=0;j<i;j++){
				temp[j] = q[n-i+j];
			}
			for(int j=i;j<n;j++){
				r[j] = q[j-i];
			}
			for(int j=0;j<i;j++){
				r[j] = temp[j];
			}
			res *= fn(p,r,n);
			delete []temp;
			delete []r;
		}
		res %= 998244353;
		cout<<res<<endl;
	}
	return 0;
}
