#include<bits/stdc++.h>
using namespace std;
int findCount(char* inp,int len){
    
    if(len==0){
        return 0;
    }

	for(int i=0;i<len-3;i++){
		if(inp[i]=='g'){
			if(inp[i+1]=='o'){
				if(inp[i+2]=='o'){
					if(inp[i+3]=='g'){
						return 1+findCount(inp+1,len-1);
					}
				}
				return findCount(inp+1,len-1);
			}
			return findCount(inp+1,len-1);
		}
		return findCount(inp+1,len-1);
	}
    
	return findCount(inp+1,len-1);
}
int main(){
    char* inp=new char[100];
    cin>>inp;
    string temp="";
    for(int i=0;inp[i]!='\0';i++){
    	temp+=inp[i];
	}
    cout<<findCount(inp,temp.length());
    return 0;
}