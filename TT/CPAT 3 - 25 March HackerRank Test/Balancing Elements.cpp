#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
struct mappyEl{
    int odd,even;
};
struct mappyAf{
    int odd,even;
};
int countBalancingElements(vector<int> arr) {
    int oddSum = 0,evenSum = 0;
    int count = 0;
    unordered_map<int,mappyEl> mappy;
    mappyEl temp;
    temp.odd = 0;
    temp.even = 0;
    mappy.insert(make_pair(0,temp));
    int n = arr.size();
    for(int i=0;i<n;i++){
        (i%2==0) ? evenSum+=arr[i] : oddSum+=arr[i];
        mappyEl temp;
        temp.odd = oddSum;
        temp.even = evenSum;
        mappy.insert(make_pair(i+1,temp));
    }
    unordered_map<int,mappyAf> mappyA;
    mappyAf tempA;
    tempA.odd = 0;
    tempA.even = 0;
    mappyA.insert(make_pair(n-1,tempA));
    oddSum = 0;
	evenSum = 0;
    for(int i=n-1;i>=1;i--){
        ((i-1)%2==0) ? evenSum+=arr[i] : oddSum+=arr[i];
        mappyAf temp;
        temp.odd = oddSum;
        temp.even = evenSum;
        mappyA.insert(make_pair(i-1,temp));
    }
    for(int i=0;i<n;i++){
        oddSum = mappy[i].odd;
        evenSum = mappy[i].even;
//        cout<<"for i:"<<i<<endl;
//        cout<<"oddSum (B): "<<oddSum<<endl;
//        cout<<"evenSum (B): "<<evenSum<<endl;
		oddSum += mappyA[i].odd;
		evenSum += mappyA[i].even;
//        cout<<"oddSum (A): "<<oddSum<<endl;
//        cout<<"evenSum (A): "<<evenSum<<endl;
        if(oddSum == evenSum) count++;
    }
//    cout<<"count : "<<count<<endl;
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = countBalancingElements(arr);

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
