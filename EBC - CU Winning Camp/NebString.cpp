#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string suffix;
    suffix += s[n - 1];
    string prefix;
    prefix += s[0];
    string nobericString;
    for (int i = n - 1; i > 0; i--)
    {

        if (s[i] == s[i - 1])
        {
            suffix += s[i - 1];
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            prefix += s[i + 1];
        }
        else
        {
            break;
        }
    }
    //cout<<suffix<<" "<<prefix;
    nobericString += suffix;
    nobericString += prefix;
    cout << nobericString << endl;
    vector<string> vlog;
    for (int i = 0; i < nobericString.size(); i++)
    {
        string temp = nobericString.substr(0, i + 1);
        vlog.push_back(temp);
    }
    
    vector<int> countofprefix;
    for (int i = 0; i < vlog.size(); i++)
    {
        string tok = vlog[i];
        size_t pos = nobericString.find(tok, 0);
        int count = 0;
        while (pos != string::npos)
        {
            count++;
            pos = nobericString.find(tok, pos + 1);
        }
        countofprefix.push_back(count);
    }
    for (int i = 0; i < countofprefix.size(); i++)
        cout << countofprefix[i] << " ";

    return 0;
}