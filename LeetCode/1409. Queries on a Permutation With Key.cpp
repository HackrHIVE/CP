#include<bits/stdc++.h>
using namespace std;
vector<int> processQueries(vector<int> queries, int m) {
    unordered_map<int,int> pos;
    unordered_map<int,int> arr;
    vector<int> out;
    for(int i=0;i<m;i++){
        pos.insert(make_pair(i+1,i));
        arr.insert(make_pair(i,i+1));
    }
    for(int i=0;i<queries.size();i++){
        int element = queries[i];
        int index = pos[element];
        out.push_back(index);
        for(int j=index;j>0;j--){
            arr[j] = arr[j-1];
            pos[arr[j]] = j;
        }
        pos[element] = 0;
        arr[0] = element;
    }
    return out;
}
int main(){
	vector<int> out = processQueries(vector<int>{3,1,2,1},5);
	for(auto it: out){
		cout<<it<<endl;
	}
	return 0;
}

