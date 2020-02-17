#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i,temp,min,max,amazing = 0;
	for(i=0;i<n;i++){
		cin>>temp;
		if(i==0){
			min = temp;
			max = temp;
			continue;
		}
		if(temp>max){
			max = temp;
			amazing++;
		}
		if(temp<min){
			min = temp;
			amazing++;
		}
	}
	cout<<amazing;
	return 0;
}