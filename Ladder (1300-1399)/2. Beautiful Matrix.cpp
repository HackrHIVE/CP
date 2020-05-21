#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int x=-1,y=-1,c;
    int arr[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>c;
            if(c==1){
                x = i;
                y = j;
            }
            arr[i][j] = c;
        }
    }
    int middle = 2;
    int cost = abs(y-middle)+abs(x-middle);
    cout<<cost;
    return 0;
}
