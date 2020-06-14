#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	string a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		int max = 0;
		if(a.length()==1 && b.length()==1) cout<<a+b;
		else if(a.length()==1 && b.length()==2){
			int a1 = a[0]-48;
			int b1 = b[0]-48;
			int b2 = b[1]-48;
			max = a1 + (b1*10+b2);
			if(b1<a1){
				if(b1+(a1*10+b2)>max){
					max = b1 + (a1*10+b2);
				}
				if(b2+(a1*10+b1)>max){
					max = b2 + (a1*10+b1);
				}
			}
		}
		else if(a.length()==2 && b.length()==1){
			int a1 = a[0]-48;
			int a2 = a[1]-48;
			int b1 = b[0]-48;
			max = (a1*10+a2) + b1;
			if(b1>a1){
				if(a1+(b1*10+a2)>max){
					max = a1 + (b1*10+a2);
				}
				if(a2+(b1*10+a1)>max){
					max = a2 + (b1*10+a1);
				}
			}
		}
		else {
			int a1 = a[0]-48;
			int a2 = a[1]-48;
			int b1 = b[0]-48;
			int b2 = b[1]-48;
			max = (a1*10+a2) + (b1*10+b2);
			if(b1 < a2){
				if(a1*10+b1+a2*10+b2 > max){
					max = a1*10+b1+a2*10+b2;
				}
			}
			if(a1 < b2){
				if(b2*10+a2 + b1*10+a1 > max){
					max = b2*10+a2 + b1*10+a1;
				}
			}
		}
		cout<<max<<endl;
	}
	return 0;
}


