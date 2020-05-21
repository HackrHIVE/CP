#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
unsigned int countSetBits(int n) 
{ 
    unsigned int count = 0; 
    while (n) { 
        n &= (n - 1); 
        count++; 
    } 
    return count; 
} 
vector<int> sortByBits(vector<int>& arr) {
    int countBit = 0;
    map<int,vector<int> > mappy;
    for(int i=0;i<arr.size();i++){
        countBit = countSetBits(arr[i]);
        if(mappy.find(countBit)!=mappy.end()){
            vector <int> temp = mappy[countBit];
            temp.push_back(arr[i]);
            mappy[countBit] = temp;
        }
        else{
            vector <int> temp;
            temp.push_back(arr[i]);
            mappy[countBit] = temp;
        }
    }
    vector<int> returnVec;
    vector<int> temp;
    map<int, vector<int> >::iterator it = mappy.begin();
    while(it!=mappy.end()){
        temp = it->second;
            sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)returnVec.push_back(temp[i]);
        it++;
    }
    return returnVec;
}
int main(){
    vector<int> inp;
//    int arr[] = {1024,512,256,128,64,32,16,8,4,2,1};
    inp.push_back(1024);
    inp.push_back(512);
    inp.push_back(256);
    inp.push_back(128);
    inp.push_back(64);
    inp.push_back(32);
    inp.push_back(16);
    inp.push_back(8);
    inp.push_back(4);
    inp.push_back(2);
    inp.push_back(1);
    vector<int> out = sortByBits(inp);
    for(int i=0;i<out.size();i++){
        cout<<out[i]<<" ";
    }
}
