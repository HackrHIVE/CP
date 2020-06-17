#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validIP6Component(string x)
    {
        if (x.length() > 0 && x.length() <= 4)
        {
            for (auto i : x)
            {
                if ((i >= 48 && i <= 57) || (i >= 65 && i <= 70) || (i >= 97 && i <= 102))
                    continue;
                return false;
            }
            return true;
        }
        return false;
    }
    bool validIP4Component(string x)
    {
        if (x[0] == '0' && x.length() > 1)
            return false;
        if (x.length() > 0 && x.length() <= 3)
        {
            for (auto i : x)
            {
                if ((i >= 48 && i <= 57))
                    continue;
                return false;
            }
            return true;
        }
        return false;
    }
    string validIPAddress(string IP)
    {
        if (IP.find(".") != string::npos)
        {
            //ipV4
            if (IP.length() >= 7 && IP.length() <= 15)
            {
                std::string s = IP;
                std::string delimiter = ".";
                size_t pos = 0;
                std::string token;
                int total = 0;
                vector<string> out;
                bool somethingFishy = false;
                while ((pos = s.find(delimiter)) != std::string::npos)
                {
                    total++;
                    if (total == 4)
                    {
                        somethingFishy = true;
                        break;
                    }
                    token = s.substr(0, pos);
                    if (token.length() > 3)
                        break;
                    if (!validIP4Component(token))
                        break;
                    int val = stoi(token);
                    if (val > 255)
                        break;
                    s.erase(0, pos + delimiter.length());
                }
                if (!somethingFishy && total == 3)
                    if (validIP4Component(s))
                        if (s.length() <= 3)
                            if (stoi(s) <= 255)
                                return "IPv4";
            }
        }
        if (IP.find(":") != string::npos)
        {
            //ipV6
            if (IP.length() >= 15 && IP.length() <= 39)
            {
                std::string s = IP;
                std::string delimiter = ":";
                size_t pos = 0;
                std::string token;
                while ((pos = s.find(delimiter)) != std::string::npos)
                {
                    token = s.substr(0, pos);
                    if (!validIP6Component(token))
                        break;
                    s.erase(0, pos + delimiter.length());
                }
                if (validIP6Component(s))
                    return "IPv6";
            }
        }
        return "Neither";
    }
};
int main()
{
    Solution *sol = new Solution();
    cout << "Enter IP : ";
    string x;
    cin >> x;
    cout << sol->validIPAddress(x) << endl;
    return 0;
}