#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    vector <char> s1;
    string temp1 = "";
    string temp2 = "";
    int index = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]!='#'){
            s1.push_back(s[i]);
            index++;
        }
        else{
            int length = 0;
            for(int j=i;j<s.length();j++){
                if(s[j]=='#') length++;
                else break;
            }
            i += length-1;
            if(index<=length){
                s1.empty();
                index = 0;
            }
            else{
                s1.erase(s1.begin()+index-length,s1.end());
                index -= length;
            }
        }
    }
    for(int i=0;i<s1.size();i++) temp1 += s1[i]+"";
    
    vector <char> s2;
    index = 0;
    for(int i=0;i<t.length();i++){
        if(t[i]!='#'){
            s2.push_back(t[i]);
            index++;
        }
        else{
            int length = 0;
            for(int j=i;j<t.length();j++){
                if(t[j]=='#') length++;
                else break;
            }
            i += length-1;
            if(index<=length){
                s2.clear();
                index = 0;
            }
            else{
                s2.erase(s2.begin()+index-length,s2.end());
                index -= length;
            }
        }
    }
    for(int i=0;i<s2.size();i++) temp2 += s2[i]+"";
    if(temp1 == temp2) cout<<"True";
    else cout<<"False";
}
