#include<bits/stdc++.h>
using namespace std;
long maxValue(int n, vector<vector<int>> rounds) {
    vector<long int> arr(n+1,0);
    vector<long int> sum(n+1,0);
    long maxValue = 0;
    int start = 0;
    int end = 0;
    int investment = 0;
    for(int i=0;i<rounds.size();i++){
        start = rounds[i][0];
        end = rounds[i][1];
        investment = rounds[i][2];
        sum[start] += investment;

        if(end +1 < n+1) sum[end+1] -= investment;
    }
    arr[1] += sum[1];
    for(int i=2;i<=n;i++){
        sum[i] += sum[i-1];
        arr[i] += sum[i];
        if(maxValue<arr[i]) maxValue = arr[i];
    }
    return maxValue;
}
int main(){
	
	return 0;
}

