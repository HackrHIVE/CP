#include<iostream>
using namespace std;
int main(){
	string x;
	cin>>x;
	bool check = false;
	for(int i=0;x[i]!=0;i++){
		if(x[i]=='H'||x[i]=='Q'||x[i]=='9'){
			check = true;
		}
		continue;
	}
	(check)?cout<<"YES":cout<<"NO";
	return 0;
}
