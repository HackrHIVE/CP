#include<bits/stdc++.h>
using namespace std;
int total = 0;
vector<int> path;
void pintPath(){
	cout<<"Path : ";
	for(auto x:path) cout<<x<<" ";
	cout<<endl;
}
void findPath(vector<vector<int>> &arr,vector<vector<bool>> &visited,int row,int col,int x,int y,int rem){
    visited[x][y] = true;
    rem -= 1;
//    cout<<"Now Rem : "<<rem<<endl;
//    cout<<"x : "<<x<<"\ty : "<<y<<endl;
//    cout<<"---------> "<<arr[x][y]<<endl;
    if(x==0 && y==3){
	    visited[x][y] = false;
		if(rem == 0){
//	    	cout<<"HERE\n";
	    	total++;
			path.push_back(arr[x][y]);
	    	pintPath();
	        return;
		}
		return;
    }
    //up
	path.push_back(arr[x][y]);
    if(x>0){
        if(arr[x-1][y]!=0){
        	if(!visited[x-1][y]) {
//        		cout<<"UP\nx-1 : "<<x-1<<"\ty : "<<y<<endl;
        		findPath(arr,visited,row,col,x-1,y,rem);
			}
        }
    }
    //right
    if(y+1<col){
		if(arr[x][y+1]!=0){
			if(!visited[x][y+1]) {
//        		cout<<"RIGHT\nx : "<<x<<"\ty+1 : "<<y+1<<endl;
				findPath(arr,visited,row,col,x,y+1,rem);
			}
		}
    }
    //bottom
    if(x+1<row){
    	if(arr[x+1][y]!=0){	
			if(!visited[x+1][y]){
//        		cout<<"BOTTOM\nx+1 : "<<x+1<<"\ty : "<<y<<endl;
				findPath(arr,visited,row,col,x+1,y,rem);
			} 
		}
    }
    //left
    if(y>0){
		if(arr[x][y-1]!=0){
			if(!visited[x][y-1]){
//        		cout<<"LEFT\nx : "<<x<<"\ty-1 : "<<y-1<<endl;
				findPath(arr,visited,row,col,x,y-1,rem);
			}
		}
    }
    path.erase(path.begin()+16-rem,path.end());
    visited[x][y] = false;
}

int main(){
	vector <vector<int> > arr({
								vector<int>{1,2,3,4},
								vector<int>{5,6,7,8},
								vector<int>{9,10,11,12},
								vector<int>{13,14,15,16},
							  });
	vector <vector<bool> > visited(4, vector<bool>(4,false));
	vector <vector<int> > ways(4, vector<int>(4,0));
	visited[2][0] = true;
	visited[3][0] = true;
	path.push_back(arr[3][0]);
	path.push_back(arr[2][0]);
	path.push_back(arr[3][0]);
	int rem = 14;
	findPath(arr,visited,4,4,3,1,rem);
	visited[2][0] = false;
	visited[3][1] = true;
	path.clear();
	path.push_back(arr[3][0]);
	path.push_back(arr[3][1]);
	path.push_back(arr[3][0]);
	rem = 14;
	findPath(arr,visited,4,4,2,0,rem);
	cout<<"Ways : from 13 to 4 -> "<<total;
	return 0;
}

