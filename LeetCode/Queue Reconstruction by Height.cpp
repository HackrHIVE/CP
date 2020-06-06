#include <bits/stdc++.h>
using namespace std;
bool meraApnaKhudkaComparator(vector<int> x, vector<int> y)
{
    if (x[1] == y[1])
        return x[0] < y[0];
    return x[1] < y[1];
}
vector<vector<int>> reconstructQueue(vector<vector<int>> people)
{
    cout << "Input ->\n{";
    for (auto x : people)
        cout << " {" << x[0] << "," << x[1] << "} ,";
    cout << "}\n";
    sort(people.begin(), people.end(), meraApnaKhudkaComparator);
    cout << "After Sorting ->\n{";
    for (auto x : people)
        cout << " {" << x[0] << "," << x[1] << "} ,";
    cout << "}\n";
    vector<vector<int>> out;
    for (auto x : people)
    {
        int h = x[0];
        int k = x[1];
        int i = 0;
        while (k != 0 && i != out.size())
        {
            if (out[i][0] >= h)
                k--;
            i++;
        }
        cout << "Inserting {" << x[0] << "," << x[1] << "} at " << i << endl;
        if (i < out.size())
        {
            if (out[i][1] == x[1])
            {
                cout << "Special Case\n";
                while(i < out.size()){
                    if(out[i][1] == x[1]) i++;
                    else break;
                }
                cout<<"Now Inserting {" << x[0] << "," << x[1] << "} at "<<i<<endl;
                out.insert(out.begin() + i, x);
            }
            else
                out.insert(out.begin() + i, x);
        }
        else
            out.insert(out.begin() + i, x);
        cout << "New Vec Now ->\n{";
        for (auto y : out)
            cout << " {" << y[0] << "," << y[1] << "} ,";
        cout << "}\n";
    }

    return out;
}
int main()
{
    vector<vector<int>> out = reconstructQueue(vector<vector<int>>{{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}});
    cout << "Output ->\n{";
    for (auto x : out)
        cout << " {" << x[0] << "," << x[1] << "} ,";
    cout << "}\n";
    return 0;
}