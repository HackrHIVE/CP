#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countPerms' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
#define mod 1000000007
int modmod(string x,int n){
	cout<<"string : "<<x<<endl;
    int l = x.length();
    if(l==n) return 1;
    long long int count = 0;
    switch (x[l-1]) {
        case 'a':{
        	cout<<"case a:: "<<endl;
            count += modmod(x+'e',n)%mod;
        }
        break;
        case 'e':{
        	cout<<"case e:: "<<endl;
            count += modmod(x+'a',n)%mod;
            count += modmod(x+'i',n)%mod;
        }
        break;
        case 'i':{
        	cout<<"case i:: "<<endl;
            count += modmod(x+'a',n)%mod;
            count += modmod(x+'e',n)%mod;
            count += modmod(x+'o',n)%mod;
            count += modmod(x+'u',n)%mod;
        }
        break;
        case 'o':{
        	cout<<"case o:: "<<endl;
            count += modmod(x+'i',n)%mod;
            count += modmod(x+'u',n)%mod;
        }
        break;
        case 'u':{
        	cout<<"case u:: "<<endl;
            count += modmod(x+'a',n)%mod;
        }
        break;
    }
    return count%mod;
}
//int countPerms(int n) {
//    string x = "aeiou";
//    long long count = 0;
//    for(auto y : x){
//        string temp(1,y);
//        count += modmod(temp,n)%mod;
//    }
//    cout<<"count : "<<count%mod<<endl;
//    return count%mod;
//}
int countPerms(int n){
    int arr[5][5] = { {0,1,1,0,1},{1,0,1,0,0},{0,1,0,1,0},{0,0,1,0,0},{0,0,1,1,0} };
    vector<int> dp(5,1);
    for(int i=2;i<=n;i++){
        vector<int> tem(5.0);
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++) if(arr[j][k]==1) tem[j] = (tem[j] + dp[k])%mod;
        }
        dp = tem;
    }
    int count = 0;
    for(int i=0;i<5;i++) count = (count + dp[i])%mod;
    
    cout<<"Count : "<<count<<endl;
    return count%mod;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = countPerms(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
