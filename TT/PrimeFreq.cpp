#include<bits/stdc++.h> 
using namespace std;
bool checkPrime(int n){
	int root = sqrt(n);
	for(int i=2;i<=root;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	map <int , int , greater<int> > myMap;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++){
		if(checkPrime(arr[i])){
			if(myMap.find(arr[i])!=myMap.end())
				myMap[arr[i]]++;
			else
				myMap.insert(make_pair(arr[i],1));
		}
	}
	map<int , int>::iterator it = myMap.begin();
	while(it!=myMap.end()){
		cout<<it->first<<" : "<<it->second<<endl; 
		it++;
	}
	return 0;
}

