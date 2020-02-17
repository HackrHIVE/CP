#include<bits/stdc++.h>
#include "list"
using namespace std;
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		vector <string> arrS;
		map<char,list<string>> mappy;
		string* arr= new string[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			for(int j=0;arr[i][j]!=0;j++)
			if(mappy.find(arr[i][j])!=mappy.end()){
			    list<string> x = mappy[arr[i][j]];
			    x.push_back(arr[i]);
			    mappy[arr[i][j]] = x;
			}
			else{
				list <string> x;
				x.push_back(arr[i]);
			    mappy.insert(make_pair(arr[i][j],x));
			}
		}
		set<string> setty;
		list<string> x = mappy['a'];
		for (std::list<string>::iterator it=x.begin(); it != x.end(); ++it)
    		setty.insert(*it);
		x = mappy['e'];
		for (std::list<string>::iterator it=x.begin(); it != x.end(); ++it)
    		setty.insert(*it);
		x = mappy['i'];
		for (std::list<string>::iterator it=x.begin(); it != x.end(); ++it)
    		setty.insert(*it);
		x = mappy['o'];
		for (std::list<string>::iterator it=x.begin(); it != x.end(); ++it)
    		setty.insert(*it);
		x = mappy['u'];
		for (std::list<string>::iterator it=x.begin(); it != x.end(); ++it)
    		setty.insert(*it);
		int a = setty.size();
		int numerator = a*(a-1)*(a-2);
		int res = numerator/6;
		cout<<res<<endl;
	}
	return 0;
}



