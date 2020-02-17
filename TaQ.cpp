#include<iostream>
using namespace std;
int main(){
	int x;
    cin>>x;
    string s;
    cin>>s;
    int l=s.length();  
    string s1("");
    x=x%(l-1);
    // s1.resize(l);
    for(int i=0;i<x;i++){
        int start=0,end=l-1;
        bool ok=true;
        for(int j=0;j<l && start<=end;j++){
                if(ok){
                    s1+=s[start++];
                    ok=false;
                }
                else{
                    s1+=s[end--];
                    ok=true;
                }
            }
        s = s1;
        s1.clear();
    }
    cout<<s;
	return 0;
}

