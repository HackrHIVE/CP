#include<iostream>
using namespace std;
int maxAvg = 0.0;
void solveIt(int **sum,int **arr,int row,int col,int x,int y,int steps,int cost){
    if(x==row-1 && y==col-1) {
        double temp = cost/(double)steps;
        if(::maxAvg<temp) ::maxAvg = temp;
        return;
    }
    if(x<row && y<col){
        int right = 0,bottom = 0;
        if(y+1<col) {
            solveIt(sum,arr,row,col,x,y+1,steps+1,cost+arr[x][y+1]);
		}
        if(x+1<row) {
            solveIt(sum,arr,row,col,x+1,y,steps+1,cost+arr[x+1][y]);
		}
    } 
    else return;
}
int main(){
	/*
	INPUT
	3 3
	1 4 5
	2 4 6
	6 7 9
	OUTPUT
	5.0
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
    solveIt(sum,arr,destX+1,destY+1,sourceX,sourceY,1,arr[0][0]);
    cout<<"Max Average : "<<::maxAvg<<endl;
    return 0;
}
