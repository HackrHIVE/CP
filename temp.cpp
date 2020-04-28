#include<bits/stdc++.h> 
using namespace std; 
int ** help(int n){
    
    int** arr = new int*[n];
    for(int i=0;i<n;i++) arr[i] = new int[n];
    int k=0;//row
    int l=0;//col
    int x=1;
while(l<n&&k<n){
    for(int i=0;i<n;i++){
        arr[k][l]=x++;
    }k++;
    for(int i=k;i<n;i++){
        arr[i][n-1]=x++;
    }n--;
    
    if(k<n){
        for(int i=n-1;i>=0;i--){
            arr[i][n-1]=x++;
        }
    }n--;
    if(l<n){
        for(int i=n-1;i>=k;i--){
            arr[i][l]=x++;
        }l++;
    }
    
}
	return arr;
}

vector<vector<int> > generateMatrix(int A) {

int** ans;
 ans=help(A);
    for(int i=0;i<A;i++){
    	for(int j=0;j<A;j++) cout<<ans[i][j]<<" ";
    	cout<<endl;
	}
vector<vector<int> > v;
for (int i=0; i<A; i++) 
{
vector<int>temp;
for(int j=0;j<A;j++)
{
int a=ans[i][j];
        temp.push_back(a); 
}
v.push_back(temp);
}
return v;


    
}
int main(){
	return 0;
}
