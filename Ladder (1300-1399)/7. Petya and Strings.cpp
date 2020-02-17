#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string s1 ,s2;
	cin>>s1;
	cin>>s2;
	int x1,x2;
	bool broke = false;
	int len = (s1.length()<s2.length())?s1.length():s2.length();
	for(int i=0;i<len;i++){
		x1 = s1[i];
		x2 = s2[i];
		if(x1<=90)
			x1 -= 65;
		if(x1>90)
			x1 -= 97;
		if(x2<=90)
			x2 -= 65;
		if(x2>90)
			x2 -= 97;
		if(x1==x2)
			continue;
		else if(x1>x2){
			cout<<"1";
			broke = true;
			break;
		}
		else{
			cout<<"-1";
			broke = true;
			break;
		}
	}
	if(!broke)
		cout<<"0";
	return 0;
}
