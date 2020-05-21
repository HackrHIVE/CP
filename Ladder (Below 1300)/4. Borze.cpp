#include<iostream>
using namespace std;
int main(){
    string input;
    cin>>input;
    string output = "";
    for(int i=0;i<input.length();i++){
        if(input[i]=='.')
        output = output + "0";
        if(i<=input.length()-2){
            if(input[i]=='-' && input[i+1]=='.'){
            	output += "1";
            	i++;
			}
            else if(input[i]=='-' && input[i+1]=='-'){
	            output += "2";
    			i++;        	
			}
            else if(input[i]=='-')
            output += "0";
        }
        else{
        	if(input[i]=='-')
        	output += "0";
		}
    }
    cout<<output;
    return 0;
}
