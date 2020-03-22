#include <bits/stdc++.h>
/*
Question:
Given a string that consists of only two types of characters: '(' and ')', balance the parentheses by inserting either a '(' or a ')' as many times as necessary. Determine the minimum number of characters that must be inserted.
Example:
s = '(()))'
To make it a valid sequence, insert a '('at the beginning of the string, resulting in "((()))". The string is balanced after 
Return:
int:  the minimum number of insertions required to balance the parentheses
*/
using namespace std;
int getMin(string s) {
    int operations = 0;
    int net = 0;
    bool start = false;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='(') net++;
        else if(s[i]==')') net--;
        if(net<0 && i<len-1){
            if(s[i+1]=='('){
                operations += abs(net);
                net = 0;
            }
        }
    }
    operations += abs(net);
    return operations;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = getMin(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
