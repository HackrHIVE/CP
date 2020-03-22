#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> s;
	s.push_back(10);
	s.push_back(10);
	s.push_back(10);
	cout<<s.size()<<endl;
	s.erase(s.begin()+1);
	cout<<s.size()<<endl;
	return 0;
}


