#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
	//a = 5 b = 6
	a = a+b; //11
	b = a+b; //17
	a = b-a; //6
	b = b-a-a; //5
}
int main(){
	int a = 6;
	int b = 3;
	int c = 5;
	int d = 2;
	if(a>b) swap(a,b);
	if(c>d) swap(c,d);
	if(a>c) swap(a,c);
	if(b>d) swap(b,d);
	if(b>c) swap(b,c);
	cout<<a<<" "<<b<<" "<<c<<" "<<d;
	return 0;
}

