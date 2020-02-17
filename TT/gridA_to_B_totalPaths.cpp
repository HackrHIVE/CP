#include<iostream>
using namespace std;
int solveIt(int **sum,int **arr,int row,int col,int x,int y){
    if(x==row-1 && y==col-1) return 1;
    if(x<row && y<col){
        if(arr[x][y]==1){
            int right = 0,bottom = 0;
            if(y+1<col) {
                right = solveIt(sum,arr,row,col,x,y+1);
			}
            if(x+1<row) {
                bottom = solveIt(sum,arr,row,col,x+1,y);
			}
            sum[x][y] = right+bottom;
            return sum[x][y];
        }   
        else return 0; 
    } 
    else return 0;
}
int main(){
	/*
	INPUT
	5 5
	1 -1 -1 -1 -1
	1 1 1 -1 -1
	-1 1 1 1 -1
	-1 -1 1 1 1
	-1 -1 1 -1 1
	OUTPUT
	4
	*/
    int n,m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    int **sum = new int*[n];
    for(int i=0;i<n;i++){
        sum[i] = new int[m];
        for(int j=0;j<m;j++) sum[i][j]=0;
    }
	sum[n-1][m-1] = 1;
    int sourceX=0,sourceY=0;
    int destX=n-1,destY=m-1;
    cout<<"Paths : "<<solveIt(sum,arr,destX+1,destY+1,sourceX,sourceY)<<endl;
    return 0;
}
