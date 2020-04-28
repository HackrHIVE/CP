#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int max = 0;
    string convertToString(char* a, int size) 
    { 
        int i; 
        string s = ""; 
        for (i = 0; i < size; i++) { 
            s = s + a[i]; 
        } 
        return s; 
    } 
    bool fun(char* x , int size,unordered_map<int,string> &mappy){
        cout<<x<<"\t"<<x[0]<<" to "<<x[size-1]<<endl;
        string temp = convertToString(x,size);
        cout<<"TempString : "<<temp<<endl;
        if(size<2){
            // mappy[size] = x;
            mappy[size] = temp;
            if(max<size) max = size;
            return true;
        }
        if(x[0]==x[size-1]){
            cout<<"0:"<<x[0]<<"\t-1:"<<x[size-1];
            cout<<"\tsize : "<<size<<endl;
            if(size==2){
                if(max<size){
                    max = size;
                    string temp = convertToString(x,size);
                    mappy[size] = temp;
                }
                return true;
            }
            if(fun(x+1,size-2,mappy)){
                cout<<"Found one\n";
                string temp = convertToString(x,size);
                mappy[size] = temp;
                if(max<size) max = size;
                return true;
            }
            return false;
        }
        else{
//            if(fun(x,size-1,mappy)){
//                string temp = convertToString(x,size-1);
//                mappy[size-1] = temp;
//                cout<<"Set at "<<size-1<<" :== value -> "<<temp<<endl;
//            }
cout<<"calling for ";
for(int i=1;i<size-1;i++){
	cout<<x[i];
}
cout<<endl;
            if(fun(x+1,size-1,mappy)){
                string temp = convertToString(x+1,size-1);
                mappy[size-1] = temp;
                cout<<"Set at "<<size-1<<" :== value -> "<<temp<<endl;
            }
            return false;
        }
    }
    string longestPalindrome(string s) {
        unordered_map<int,string> mappy;
        char *cstr = &s[0];
        cout<<"len ** -> "<<s.length()<<endl;
        cout<<"*/* "<<s[0]<<endl;
        fun(cstr,s.length(),mappy);
        cout<<"MAX : "<<max<<endl;
        return mappy[max];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
