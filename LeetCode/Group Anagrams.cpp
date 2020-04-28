#include<bits/stdc++.h>
using namespace std;
//vector<vector<string>>
void groupAnagrams(vector<string> s) {
    unordered_map<string, vector<string> > mappy;
    string temp(26,48);
    string zeroes(26,48);
    for(int i=0;i<s.size();i++){
        temp = zeroes;
        for(int j=0;j<s[i].length();j++){
//        	if(temp[s[i][j]-97] == 48)
            temp[s[i][j]-97] = temp[s[i][j]-97]+1;
        }
        if(mappy.find(temp)==mappy.end()){
            vector <string> tempV;
            tempV.push_back(s[i]);
            mappy.insert(make_pair(temp,tempV));
        }
        else{
            vector <string> tempV = mappy[temp];
            tempV.push_back(s[i]);
            mappy[temp] = tempV;
        }
    }
    vector <vector<string> > result;
    unordered_map<string, vector<string> >::iterator it = mappy.begin();
    while(it!=mappy.end()){
        result.push_back(it->second);
		for(int i=0;i<it->second.size();i++) cout<<it->second[i]<<" ";
		cout<<endl;
        it++;
    }
//    return result;
}
int main(){
	groupAnagrams(vector<string> {"boo","bob"});
	return 0;
}

