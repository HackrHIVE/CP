#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int **transpose = new int *[m];
    for (int i = 0; i < m; i++)
    {
        transpose[i] = new int[n];
        for (int j = 0; j < n; j++)
            transpose[i][j] = arr[j][i];
    }
    cout << "Transpose : \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << transpose[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    for (int i = 0; i < m; i++)
        delete[] transpose[i];
    delete[] arr;
    delete[] transpose;
    return 0;
}