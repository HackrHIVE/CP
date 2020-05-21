#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'fewestCoins' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING coins as parameter.
 */
unordered_map<char,int> getBackCount(string s){
    unordered_map<char,int> mappy;
    for(int i=0;i<s.length();i++){
        if(mappy.find(s[i])!=mappy.end()){
            mappy[s[i]]++;
            // mappy.insert(make_pair(s[i],mappy[s[i]]+1));
        }
        else{
            mappy.insert(make_pair(s[i],1));
        }
    }
    return mappy;
}

int fewestCoins(string coins) {
	if(coins.length()==1) return INT_MAX;
    unordered_map<char,int> charss = getBackCount(coins);
    int uniqChar = charss.size();
    int length = coins.length();
    int shortest = coins.length();
    for(int i=0;i<length;i++){
        cout<<"Calling getBackCount() for "<<coins<<endl;
        cout<<"Shortest -> "<<coins.length()<<endl;
        unordered_map<char,int> mappy = getBackCount(coins);
        cout<<mappy.size()<<endl<<"*"<<uniqChar<<endl;
        if(mappy.size()==uniqChar){
        	
            cout<<coins[0]<<" -> "<<mappy[coins[0]]<<endl;
            cout<<coins[coins.length()-1]<<" -> "<<mappy[coins[coins.length()-1]]<<endl;
            int left=INT_MAX,right=INT_MAX;
            if(mappy[coins[0]]>1){
                // cout<<"Slicing string from : "<<1<<" to "<<coins.length()-1<<endl;
                left = fewestCoins(coins.substr(1,coins.length()-1));
            }
            if(mappy[coins[coins.length()-1]]>1){
                right = fewestCoins(coins.substr(0,coins.length()-2));
                // cout<<"Slicing string from : "<<0<<" to "<<coins.length()-2<<endl;
            }
            if(left==INT_MAX && right==INT_MAX)return coins.length();
            else{
            	cout<<left<<" = "<<right<<endl;
                (left>right)?coins = coins.substr(0,coins.length()-2):coins = coins.substr(1,coins.length()-1);
            }
        }
    }
    return coins.length();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string coins;
    getline(cin, coins);

    int result = fewestCoins(coins);

    fout <<"FINAL RESULT :-> "<< result << "\n";

    fout.close();

    return 0;
}
