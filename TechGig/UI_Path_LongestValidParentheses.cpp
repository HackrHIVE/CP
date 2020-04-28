#include<bits/stdc++.h>
using namespace std;
int balancedParenthesis(char *str){
	int i=0;
    int longest = 0;
    int count = 0;
    string s(str);
    while(i<s.length()){
    	if(s.length()-i<longest) break;
        int net = 0;
        int j =i;
        int fin = i;
        int temp=0;
        bool done = false;
        vector< stack<int> > p;
        // cout<<"FOR i="<<i<<endl;
        for(j=i;j<s.length();j++){
        	// cout<<"j : "<<j<<" --> "<<s[j];
            if(s[j]=='('){
            	net++;
            	stack<int> temp;
            	temp.push(1);
            	p.push_back(temp);
			}
            else if(s[j]==')'){
            	net--;
            	if(p.size()>0){
				
            	if(!p[p.size()-1].empty()) p[p.size()-1].pop();
            	if(p[p.size()-1].empty()){
            		p.erase(p.begin()+p.size()-1);
            		count++;
				}
			}
			}
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
    if(s.length()==longest) return count;
    return -1;
}
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
        for(j=i;j<s.length();j++){
            if(s[j]=='('){
            	net++;
			}
            else if(s[j]==')'){
            	net--;
			}
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
            }
        }
        int le = fin-i+1;
        if(le < temp) le = temp;
        if(longest<le && temp!=0) longest = le;
        i++;
    }
    cout<<"Longest : "<<longest<<endl;
    return 0;
}
