#include<iostream>
#include<vector>
#include<string.h>
#include<cstring>
using namespace std;
struct Crate{
    string CodeName;
    int crateSize;
    Crate(string CodeNameX,int crateSizeX){
        CodeName = CodeNameX;
        crateSize = crateSizeX;
    }
};
/*
bool comparator(Crate x , Crate y){
    return x.crateSize<y.crateSize;
}
*/
int main(){
    char *inpu;
    int vacSize[3] = {0,0,0};
    vector<Crate> vacA;
    vector<Crate> vacB;
    vector<Crate> vacC;
    vector<Crate> que;
    while(1){
        cin>>inpu;
        char *tok = strtok(inpu," ");
        int i=0;
        string *arr = new string[3];
        while(tok!=NULL){
            arr[i++] = tok;
            tok = strtok(NULL," ");
        }
        string arry[4] = {"RECV","SEND","LOAD","XFER"};
        if(arr[0]==arry[0]){
            //RECV
            que.push_back(Crate(arr[1],atoi(arr[2].c_str())));
        }else if(arr[0]==arry[1]){
            //SEND

        }else if(arr[0]==arry[2]){
            //LOAD
            for(int i=0;i<que.size();i++){
                
            }
        }else if(arr[0]==arry[3]){
            //XFER

        }else break;
    }
    return 0;
}