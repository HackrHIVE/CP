#include<bits/stdc++.h>
using namespace std;
int main(){
	vector <int> arr{9,1,10,3,13,4,1,2};
	/*
	9 1 10 3 13 4 1 2
	*/
	int *output = new int[arr.size()];
	int max = arr[arr.size()-1];
	int indexMax = arr.size()-1;
	output[arr.size()-1] = 0;
	for(int i=arr.size()-2;i>=0;i--){
		if(arr[indexMax]<arr[i]){
			output[i] = 1+output[indexMax];
			indexMax = i;
		}
		else output[i] = 0;
	}
	int min = arr[0];
	
	for(int i=1;i<arr.size();i++){
		if(arr[i]<min){
			
		}
	}
	for(int i=0;i<arr.size();i++) cout<<output[i]<<" ";
	return 0;
}

