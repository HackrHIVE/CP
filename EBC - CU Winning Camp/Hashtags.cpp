#include<bits/stdc++.h>
using namespace std;
bool myCMP(pair<string,int> x,pair<string,int> y){
    if(x.second == y.second) return (x.first.compare(y.first) < 0);

    return x.second > y.second;
}
int main(){
    int n;
    cin>>n;
    unordered_map<string,int> umap;
    n++;
    while(n--){
        string inp;
        getline(cin,inp);
        char charArr[inp.size()+1];
        strcpy(charArr,inp.c_str());
        char *delimit = strtok(charArr, " ");
        while (delimit != NULL) 
        { 
            string tempWord = string(delimit);
            if(tempWord[0] == '#'){
                //Found a hashtag
                umap[tempWord]++;
            }
            delimit = strtok(NULL, " "); 
        } 
    }
    vector<pair<string,int> > pairs;
    unordered_map<string,int>::iterator itr = umap.begin();
    while(itr != umap.end()){
        pairs.push_back(make_pair(itr->first,itr->second));
        itr++;
    }
    sort(pairs.begin(),pairs.end(),myCMP);

    for(int i=0;i<pairs.size();i++){
        cout<<pairs[i].first<<endl;
    }
    return 0;
}