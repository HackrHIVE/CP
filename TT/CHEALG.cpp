#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    string s;
    cin>>t;
    string s1("");
    while(t--){
        cin>>s;
        char x = s[0];
        int count = 1;
        if(s.length()==1){
        	
            cout<<"NO\n";
        }
        else{
            for(int i=1;i<s.length();i++){
                if(x==s[i]){
                    count++;
                    if(i==s.length()-1){
                        s1+=x;
                        s1+=to_string(count);
                    }
                }
                else{
                    s1+=x;
                    s1+=to_string(count);
                    x = s[i];
                    count = 0;
                    i--;
                }
            }
        if(s1.length()<s.length()) cout<<"YES\n";
        else cout<<"NO\n";
        
        s1.erase();
        }
        
    }
    return 0;
}
