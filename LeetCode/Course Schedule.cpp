#include<bits/stdc++.h>
using namespace std;
bool isCycle(vector<vector<int>> adj,vector<int> &visited,int i){
    if(visited[i] == 1) return true;

    if(visited[i] == 0){
        visited[i] = 1;
        for(auto x : adj[i]){
            if(isCycle(adj,visited,x)) return true;
        }
    }

    visited[i] = 2;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
    vector<vector<int> > adjList(numCourses,vector<int>{});

    for(auto x : prerequisites) adjList[x[1]].push_back(x[0]);

    vector<int> visited(numCourses,0);

    for(int i=0;i<numCourses;i++){
        if(isCycle(adjList,visited,i)) return false;
    }

    return true;
}
int main(){
    cout<<canFinish(2,vector<vector<int>>{{1,0}})<<endl;   
    return 0;
}