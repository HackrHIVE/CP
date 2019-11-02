#include<iostream>
#include<string>  
using namespace std;
bool checkLucky(long long int countLucky){
    string str= to_string(countLucky);  
    for(int i=0;str[i]!=0;i++){
        if(str[i]=='4' || str[i]=='7')
            continue;
        return false;
    }  
}
int main(){
    string input;
    cin>>input;
    long long int countLucky = 0;
    for(int i=0;input[i]!=0;i++){
        if(input[i]=='4' || input[i]=='7')
            countLucky++;
    }   
    (checkLucky(countLucky)) ? cout<<"YES" : cout<<"NO";
    return 0;
}
