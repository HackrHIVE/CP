#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    //input string
    getline(cin, s);
    //vector for storing tokens
    vector<string> out;
    int n = s.length();
    //temp string to store the tokens while traversing input string
    string temp = "";
    //boolean to check whether we are in a quote or not
    bool inQuote = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '\"')
        {
            //when we encounter a quote then we have to check whether we are entering a new quote or exiting previous quote token
            if (inQuote)
            {
                //if we are exiting previous quote token then increment i so that we can jump to next quote token string in the next iteration skipping space character
                //push temp string value stored till now to vector
                //and now clear temp string to start fresh so that we can store new tokens
                //set inQuote to false 
                i++;
                out.push_back(temp);
                inQuote = false;
                temp.clear();
                continue;
            }
            else
            {
                //set inQuote to true, meaning we have entered into a new string token
                inQuote = true;
                continue;
            }
        }
        //adding current character to temp string
        temp += s[i];
    }
    //printing string tokens stored in vector
    for (auto x : out)
        cout << x << endl;
    return 0;
}