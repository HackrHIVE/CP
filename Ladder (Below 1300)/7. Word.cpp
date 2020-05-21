#include<iostream>
using namespace std;
int main(){
    string input;
    cin>>input;
    int countLower = 0,countUpper = 0;
    for(int i=0;input[i]!=0;i++){
        if(int(input[i])>=65 && int(input[i])<=90) //Upper
            countUpper++;
        else if(int(input[i])>=97 && int(input[i])<=122) //Lower
            countLower++;
    }
    if(countLower<countUpper){
        //Convert to Upper
        if(countLower == 0){
            cout<<input;
        }
        else{
            for(int i=0;input[i]!=0;i++){

                if(int(input[i])>=65 && int(input[i])<=90) //Upper
                    continue;
                
                input[i] = (char)(int(input[i]-32));
            }
            cout<<input;
        }
    }
    else{
        if(countUpper == 0){
            cout<<input;
        }
        else{
            for(int i=0;input[i]!=0;i++){

                if(int(input[i])>=97 && int(input[i])<=122) //Lower
                    continue;

                input[i] = (char)(int(input[i]+32));
            }
            cout<<input;
        }
    }
    return 0;
}