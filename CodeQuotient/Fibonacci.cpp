#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 5;
	int i = 2;
	int a = 0;
	int b = 1;
	while(i<n){
		cout<<a<<" ";
		a = a+b;
		if(i<n){
			cout<<b<<" ";
			b = a+b;
			i++;	
		}
		i++;
	}
	return 0;
}

