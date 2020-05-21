#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> p{0,1,0,3,12};
	int it = 0;
	int et = 0;
	while( it<p.size() && et<p.size() ){
		if(p[et]!=0 && p[it]==0){
			int temp = p[et];
			p[et] = p[it];
			p[it] = temp;
			it++;
		}
		if(p[it]!=0) it++;
		et++;
	}
	
	for(int i=0;i<p.size();i++){
		cout<<p[i]<<" ";
	}
	
	return 0;
}

