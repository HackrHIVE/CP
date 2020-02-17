#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int powerUnitDigit(int x,long int m){
    return fmod(pow(x,m),10.0);
}
int unitDigitOfTwo(int x,int y){
    return (x*y)%10;
}
int unitDigitOfTwoAdd(int x,int y){
    return (x+y)%10;
}
string solve(long int m, vector<string> s) {
    // fill this function
    int overallDigit = 0;
    for(int i=0;i<s.size();i++){
        int lastDigit = 0;
        for(int j=0;j<s[i].length();j++){
            int ascii = s[i][j];
            int unitDigitSquare = fmod(pow(ascii,m),10.0);
            // cout<<"For ("<<s[i]<<")unitDigitSquare("<<ascii<<") : "<<unitDigitSquare<<endl;
            // (lastDigit==0) ? unitDigitSquare : unitDigitOfTwo(lastDigit,unitDigitSquare);
            if(lastDigit==0){
                // cout<<"First\n";
                lastDigit = unitDigitSquare;
            }
            else lastDigit = unitDigitOfTwo(lastDigit,unitDigitSquare);
            // cout<<"Last Digit : "<<lastDigit<<endl;
        }
        // cout<<"Last Digit : "<<lastDigit<<endl;
        if(overallDigit==0){
                // cout<<"First\n";
                overallDigit = lastDigit;
        }
        else overallDigit = unitDigitOfTwoAdd(overallDigit,lastDigit);
        // (overallDigit==0) ? lastDigit : unitDigitOfTwoAdd(overallDigit,lastDigit);
        // cout<<"Overall Digit : "<<overallDigit<<endl;
    }
    if(overallDigit%2==0) 
        return "EVEN";
    return "ODD";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        long int m = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split(rtrim(s_temp_temp));

        vector<string> s(k);

        for (int i = 0; i < k; i++) {
            string s_item = s_temp[i];

            s[i] = s_item;
        }

        string ans = solve(m, s);

        fout << ans << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

