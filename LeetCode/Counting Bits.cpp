#include<bits/stdc++.h>
using namespace std;
vector<int> countBits1(int num) {
    vector<int> out;
    out.push_back(0);
    if(num == 0) return out;
    out.push_back(1);
    if(num == 1) return out;
    
    int low = 2;
    int high = 3;
    
    int countBits = 1;
    int curr = low; //our num => {0,num}
    int currSize = 2; //size for the range of bits {2,3} => 2 || {4,5,6,7} => 4
    int tempBatchSize = 1;
    int nextSize = tempBatchSize*2;
    while(curr<=num){
        if(curr == high){
            out.push_back(out[curr-low]+1);
            countBits = 1;
            low = high+1;
            high = low+(currSize*2)-1;
            currSize *= 2;
            curr = low;
            tempBatchSize = 1;
            nextSize = tempBatchSize*2;
            continue;
        }
        if(tempBatchSize < nextSize){
            out.push_back(out[curr-low]+1);
            tempBatchSize++;
            curr++;
        }
        else{
            nextSize *= 2;
        }
    }

    return out;
}
vector<int> countBits(int num) {
    vector<int> out;
    out.push_back(0);
    if(num == 0) return out;
    out.push_back(1);
    if(num == 1) return out;
    
    int low = 2;
    int high = 3;
    
    int countBits = 1;
    int curr = low; //our num => {0,num}
    int currSize = 2; //size for the range of bits {2,3} => 2 || {4,5,6,7} => 4
    int tempBatchSize = 1;
    int nextSize = tempBatchSize*2;
    while(curr<=num){
        if(curr == high){
            out.push_back(countBits+1);
            countBits = 1;
            low = high+1;
            high = low+(currSize*2)-1;
            currSize *= 2;
            curr = low;
            tempBatchSize = 1;
            nextSize = tempBatchSize*2;
            continue;
        }
        if(tempBatchSize < nextSize){
            out.push_back(countBits);
            tempBatchSize++;
            curr++;
        }
        else{
            nextSize *= 2;
            countBits++;
        }
    }

    return out;
}
int main(){
    vector<int> out = countBits1(16);
    for(int x=0;x<out.size();x++) cout<<x<<" : "<<out[x]<<endl;
    return 0;
}