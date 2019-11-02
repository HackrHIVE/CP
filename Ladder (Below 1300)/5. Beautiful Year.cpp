#include<iostream>
using namespace std;
bool checkUnique(int one,int ten,int hundered,int thousand){
    int arr[10]={0};
    arr[one]++;
    arr[ten]++;
    arr[hundered]++;
    arr[thousand]++;
    return (arr[one]>1 || arr[ten]>1 || arr[hundered]>1 || arr[thousand]>1);
}
void incrementYear(int &one,int &ten,int &hundred,int &thousand){
    if(one==9){
        ten
    }
}
int main(){
    string year;
    cin>>year;
    int thousand,hundred,ten,one;
    thousand = int(year[0])-48;
    hundred = int(year[1])-48;
    ten = int(year[2])-48;
    one = int(year[3])-48+1;
    while(!checkUnique(one,ten,hundred,thousand)){

    }
    return 0;
}