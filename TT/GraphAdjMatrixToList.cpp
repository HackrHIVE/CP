#include<bits/stdc++.h>
using namespace std;
void printAdjList(vector<vector<int> >adj){
    for(int i=1;i<adj.size();i++){
        cout<<"Vertices connected with vertice("<<i<<") => ";
        for(int j=0;j<adj[i].size();j++) cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
	/*
    Adjacency Matrix
    */
    int vertices,edges;
    cin>>vertices>>edges;
    int i1,i2;
	vector<vector<int> >adj1(vertices+1);
    int **arr = new int*[vertices];
    memset(arr,vertices*vertices*sizeof(int),0);
    for(int i=0;i<vertices;i++) arr[i] = new int[vertices];
	for(int i=0;i<edges;i++){
        cin>>i1>>i2;
        arr[i1-1][i2-1] = 1;
        arr[i2-1][i1-1] = 1;
    }
    for(int i=0;i<vertices;i++){
    	for(int j=0;j<=i;j++)cout<<"  ";
    	for(int j=i+1;j<vertices;j++){
    		cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
    for(int i=0;i<vertices;i++){
    	for(int j=i+1;j<vertices;j++){
    		if(arr[i][j]==1){
    			adj1[i+1].push_back(j+1);
    			adj1[j+1].push_back(i+1);
			}
		}
	}
    printAdjList(adj1);
	return 0;
}


