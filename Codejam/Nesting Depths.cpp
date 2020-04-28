#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        string s;
        cin>>s;
        int max = 0;
        for(int j=0;j<s.length();j++) if(s[j]-48>max) max= s[j]-48;
        if(max==0){ 
            cout<<"Case #"<<i<<": "<<s<<endl;
            continue;
        }
        else if(max==1){
            vector<string> arr;
            string temp = "";
            bool one = false;
            for(int j=0;j<s.length();j++){
            	if(j==0){
            		if(s[j]=='0') temp+= "0";
            		else{
            			temp+="1";
            			one = true;
					}
					continue;
				}
				if(s[j]=='0'){
					if(one){
						arr.push_back(temp);
						temp = "0";
						one = false;
					}else{
						temp += "0";
					}
				}
				else{
					if(one){
						temp += "1";
					}
					else{
						arr.push_back(temp);
						temp = "1";
						one = true;
					}
				}
			}
			arr.push_back(temp);
			temp = "";
			for(int j=0;j<arr.size();j++){
				if(arr[j][0]=='0') temp+= arr[j];
				else{
					temp += "("+arr[j]+")";
				}
			}
			cout<<"Case #"<<i<<": "<<temp<<endl;
            continue;
        }
        else{
            string temp = "";
            int par = 0;
            for(int j=0;j<s.length();j++){
            	string x(1,s[j]);
            	if(s[j]=='0'){
            		if(par==0) temp += "0";
            		else{
            			for(int y=0;y<par;y++) temp+=")";
            			par = 0;
            			temp += "0";
					}
				}
				else{
					if(par<s[j]-48){
						for(int y=par;y<s[j]-48;y++) temp += "(";
						temp += x;
						par = s[j]-48;
					}
					else if(par>s[j]-48){
						while(par!=s[j]-48){
							temp += ")";
							par--;
						}
						temp += x;
					}
					else{
						temp += x;
					}
				}
			}
			while(par>0){
				temp += ")";
				par--;
			}
			cout<<"Case #"<<i<<": "<<temp<<endl;
        }
    }
    return 0;
}
