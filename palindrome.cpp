#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int low = 0;
    int high = s.length()-1;
    bool pal = true;
    while(low < high){
        if(s[low++] == s[high--]) continue;
        else {
            pal = false;
            break;
        }
    }
    if(pal) cout<<"Palindrome";
    else cout<<"Not Palindrome"; 
    return 0;
}