#include<bits/stdc++.h>
using namespace std;
int nextPsum(int **arr,int *store,int p,int n,int k){
	int max = 0;
	int sum = 0;
	int row = 0;
	for(int i=0;i<n;i++){
		sum = 0;
		for(int j=store[i];j<store[j]+p;j++)	sum += arr[i][j];
		if(max<sum){
			max = sum;
			row = i;
		}
	}
	return max;
}
int main(){
	int t;
	int n_stack,k,p;
	int **arr;
	int *store;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n_stack>>k>>p;
		arr = new int*[n_stack];
		for(int j=0;j<n_stack;j++){
			arr[j] = new int[k];
			for(int y=0;y<k;y++) cin>>arr[j][y];
		}
		store = new int[n_stack];
		memset(store,0,sizeof(int)*n_stack);
		int row=0,col=0;
		int max = 0;
		int sum = 0;
		bool race = false;
		while(p!=0){
			race = false;
			max = 0;
			row = 0;
			col = 0;
			for(int u=0;u<n_stack;u++){
				if(store[u]<k){
					if(max<arr[u][store[u]]){
						max = arr[u][store[u]];
						row = u;
						col = store[u];
					}
					else if(max==arr[u][store[u]]) race = true;
				}
			}
			if(!race){
				p--;
				sum += max;
				store[row]++;
			}
			else{
				if(p<=k){
					int sumy = nextPsum(arr,store,p,n_stack,k);
					sum += sumy;
					break;
				}
			}
		}
		cout<<"Case #"<<i+1<<": "<<sum<<endl;
	}
	return 0;
}
