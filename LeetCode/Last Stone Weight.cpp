#include<bits/stdc++.h>
using namespace std;
void printVec(vector<int> stones){
	cout<<"New Arr : ";
	for(auto x: stones) cout<<x<<" ";
	cout<<endl;
}
int lastStoneWeight(vector<int> stones) {
    sort(stones.begin(),stones.end(),greater<int>());
    while(stones.size()>1){
    	cout<<"Size : "<<stones.size()<<endl;
        int first = stones[0];
        int second = stones[1];
        if(first == second){
            stones.erase(stones.begin(),stones.begin()+2);
            printVec(stones);
        }
        else{
            first = abs(first-second);
            stones[1] = first;
            stones.erase(stones.begin(),stones.begin()+1);
            printVec(stones);
        }
    	sort(stones.begin(),stones.end(),greater<int>());
    }
    
    if(stones.size() == 0) return 0;
    return stones[0];
}
int main(){
	cout<<lastStoneWeight(vector<int>{2,7,4,1,8,1});
	return 0;
}

