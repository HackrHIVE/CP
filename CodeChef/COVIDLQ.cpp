#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,i,temp;
	int last1 = -1;
	bool covid;
	cin>>t;
	while(t--){
		last1 = -1;
		cin>>n;
		vector <int> arr;
		covid = false;
		for(i=0;i<n;i++){
			cin>>temp;
			if(temp==1){
				if(last1==-1) last1 = i;
				else{
					if(i-last1>=6) last1 = i;
					else covid = true;
				}
			}
		}
		if(covid) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
