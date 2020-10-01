#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxShared' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH friends as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int maxShared(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight)
{

    int **arr = new int *[friends_nodes];
    for (int i = 0; i < friends_nodes; i++)
    {
        arr[i] = new int[friends_nodes];
    }
    memset(arr, 0, sizeof(arr[0][0]) * friends_nodes * friends_nodes);
    for (int i = 0; i < friends_from.size(); i++)
    {
        cout << "i: " << friends_from[i] - 1 << endl
             << "j: " << friends_to[i] - 1 << endl;
        arr[friends_from[i] - 1][friends_to[i] - 1]++;
    }

    int max = 0;
    int maxI, maxJ;

    for (int i = 0; i < friends_nodes; i++)
    {
        for (int j = 0; j < friends_nodes; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                maxI = i;
                maxJ = j;
            }
            else if (arr[i][j] == max)
            {
                if (++i * ++j > ++maxI * ++maxJ)
                {
                    i--;
                    j--;
                    maxI--;
                    maxJ--;
                    maxI = i;
                    maxJ = j;
                }
            }
        }
    }

    return (maxI + 1) * (maxJ + 1);

    // int maxI = -1;
    // int maxCount = 0;
    // int maxProduct = 1;
    // map<int,set<int> >mappy;
    // for(int i=0;i<friends_from.size();i++){
    //     if(mappy.find(friends_weight[i])==mappy.end()){
    //         set <int> x;
    //         x.insert(friends_from[i]);
    //         x.insert(friends_to[i]);
    //         mappy.insert(make_pair(friends_weight[i],x));
    //         if(maxCount<2){
    //             maxCount = 2;

    //             maxI = i;
    //         }
    //         continue;
    //     }
    //     set <int> x = mappy[friends_weight[i]];
    //     x.insert(friends_from[i]);
    //     x.insert(friends_to[i]);
    //     mappy.insert(make_pair(friends_weight[i],x));
    //     if(maxCount<x.size()){
    //         maxCount = x.size();
    //         maxI = i;
    //     }
    // }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string friends_nodes_edges_temp;
    getline(cin, friends_nodes_edges_temp);

    vector<string> friends_nodes_edges = split(rtrim(friends_nodes_edges_temp));

    int friends_nodes = stoi(friends_nodes_edges[0]);
    int friends_edges = stoi(friends_nodes_edges[1]);

    vector<int> friends_from(friends_edges);
    vector<int> friends_to(friends_edges);
    vector<int> friends_weight(friends_edges);

    for (int i = 0; i < friends_edges; i++)
    {
        string friends_from_to_weight_temp;
        getline(cin, friends_from_to_weight_temp);

        vector<string> friends_from_to_weight = split(rtrim(friends_from_to_weight_temp));

        int friends_from_temp = stoi(friends_from_to_weight[0]);
        int friends_to_temp = stoi(friends_from_to_weight[1]);
        int friends_weight_temp = stoi(friends_from_to_weight[2]);

        friends_from[i] = friends_from_temp;
        friends_to[i] = friends_to_temp;
        friends_weight[i] = friends_weight_temp;
    }

    int result = maxShared(friends_nodes, friends_from, friends_to, friends_weight);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
