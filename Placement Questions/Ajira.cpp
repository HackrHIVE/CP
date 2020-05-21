#include <string>
#include <iostream>
#include <sstream> 
#include <vector> 
#include <map>
using namespace std;
int requiredWater = 0;
map<string,int> mapForIndex;
vector<string> indexesForWeakOnes;
map<string,string> linkForPipeline;
void getMeSomeWater(string cluster,int req,int n,int *capacity,int *daily){
    int index = mapForIndex[cluster];
    int rem = capacity[index]-(daily[index]*n);
    if(rem<req){
        int req = (n-capacity[index]/daily[index])*daily[index];
        if(linkForPipeline[cluster] == "F"){
            requiredWater+= capacity[index];
            return;
        }
        getMeSomeWater(linkForPipeline[cluster],req,n,capacity,daily);
    }
}
int main()
{
    int n;
    cin>>n;
    int c;
    cin>>c;
    string c_id[c];
    int daily[c];
    int capacity[c];
    for(int i=0;i<c;i++){
        cin>>c_id[i]>>daily[i]>>capacity[i];
        mapForIndex[c_id[i]] = i;
        requiredWater += capacity[i];
        if(capacity[i]/daily[i]<n) indexesForWeakOnes.push_back(c_id[i]);
    }
    
    int pipelinks;
    cin>>pipelinks;
    string links;
    for(int i=0;i<pipelinks;i++){
        cin>>links;
        size_t pos = links.find('_');
        string first = links.substr(0,pos);
        string second = links.substr(pos+1);
        linkForPipeline[second] = first;
    }
    
    for(int i=0;i<indexesForWeakOnes.size();i++){
        string nameOfCluster = indexesForWeakOnes[i];
        int index = mapForIndex[nameOfCluster];
        int required = daily[index]*n;
        if(required < capacity[index]) continue;
        
        if(linkForPipeline[nameOfCluster] == "F"){
            //Federal Body
            requiredWater += capacity[index];
        }
        else{
            //Another Chain
            int req = (n-capacity[index]/daily[index])*daily[index];
            getMeSomeWater(linkForPipeline[nameOfCluster],req,n,capacity,daily);
        }
    }
    
    cout<<requiredWater;
}