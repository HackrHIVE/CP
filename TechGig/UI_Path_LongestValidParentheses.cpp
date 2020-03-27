#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int i=0;
    int longest = 0;
    while(i<s.length()){
    	if(s.length()-i<longest) break;
        int net = 0;
        int j =i;
        int fin = i;
        int temp=0;
        bool done = false;
        // cout<<"FOR i="<<i<<endl;
        for(j=i;j<s.length();j++){
        	// cout<<"j : "<<j<<" --> "<<s[j];
            if(s[j]=='(') net++;
            else if(s[j]==')') net--;
            if(net<0){
                break;
            }
            if(net==0){
                if(j+1<s.length()){
                    if(s[j+1]==')'){
                    	fin = j;
				        temp = j-i+1;
                    	done = true;
                    	break;
					}
                }
                else {
                	fin = j;
				    temp = j-i+1;
                	done = true;
                	break;
				}
				temp = j-i+1;
				// cout<<"\ttemp : "<<temp;
            }
            // cout<<"\tnet : "<<net<<endl;
        }
        int le = fin-i+1;
        if(le < temp) le = temp;
    // cout<<"le : "<<le<<endl;
        if(longest<le && temp!=0) longest = le;
        i++;
    }
    cout<<"Longest : "<<longest<<endl;
    return 0;
}