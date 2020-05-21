#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x = n-10;
	if(x<=0){
		cout<<"0";
	}
	else{
		if((x>=2 && x<=9 ) || x==1 || x==11){
			cout<<"4";
		}
		else{
			cout<<"15";
		}
	}
	return 0;
}