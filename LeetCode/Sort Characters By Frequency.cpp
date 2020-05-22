#include<bits/stdc++.h>
using namespace std;
struct CharInt{
    char character;
    int count = 0;
};
bool myCMP(CharInt x,CharInt y){
    return x.count > y.count;
}
string frequencySort(string s) {
    string out = "";
    CharInt* arr = new CharInt[128];
    for(int i=0;i<s.length();i++){
        arr[s[i]].character = s[i];
        arr[s[i]].count++;
    }
    sort(arr,arr+128,myCMP);
    for(int i=0;i<128;i++){
        if(arr[i].count == 0) break;

        for(int j=0;j<arr[i].count;j++) out += arr[i].character;
    }

    return out;
}
int main(){
    cout<<frequencySort("tree");   
    return 0;
}