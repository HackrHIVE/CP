#include<iostream>
using namespace std;
bool checkUnique(int one,int ten,int hundred,int thousand){
    int arr[11]={0};
    arr[one]++;
    arr[ten]++;
    arr[hundred]++;
    arr[thousand]++;
    return !(arr[one]>1 || arr[ten]>1 || arr[hundred]>1 || arr[thousand]>1);
}
void incrementYear(int& one,int& ten,int& hundred,int& thousand){
    if(one==9){
        if(ten==9){
            if(hundred==9){
                thousand++;
                hundred = 0;
                ten = 0;
                one = 0;
            }
            else{
                ten = 0;
                one = 0;
                hundred++;
            }
        }
        else{
            ten++;
            one = 0;
        }
    }
    else
        one++;
}
int main(){
    string year;
    cin>>year;
    int thousand,hundred,ten,one;
    thousand = int(year[0])-48;
    hundred = int(year[1])-48;
    ten = int(year[2])-48;
    one = int(year[3])-48;
    do{
        incrementYear(one,ten,hundred,thousand);
    }
    while(!checkUnique(one,ten,hundred,thousand));
    cout<<thousand<<hundred<<ten<<one;
    return 0;
}
