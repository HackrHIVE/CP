#include<bits/stdc++.h>
using namespace std;
vector<string> stringMatching(vector<string> words) {
        sort(words.begin(),words.end(),[](const string& lhs, const string& rhs) {
            return lhs.length() < rhs.length();
        });
        int count = 0;
        vector<string> temp;
        unordered_set<string> setty;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if (words[j].find(words[i]) != string::npos) {
                    setty.insert(words[i]);
                } 
            }
        }
        unordered_set<string> :: iterator itr; 
        for (itr = setty.begin(); itr != setty.end(); itr++) 
            temp.push_back((*itr));
        
        return temp;
    }
int main(){
	vector<string> out = stringMatching(vector<string>{"mass","as","hero","superhero"});
	
	for(auto it: out){
		cout<<it<<endl;
	}
	return 0;
}

