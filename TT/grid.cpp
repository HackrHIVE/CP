#include <iostream>
using namespace std;
int count = 0;
bool solveIt(int **sum, int **arr, int row, int col, int x, int y)
{
    cout << "solveIt() --> "
         << "x:" << x << "\ty:" << y << endl;
    if (x == row - 1 && y == col - 1)
    {
        cout << "found one finally\n";
        ::count++;
        return true;
    }
    if (x < row && y < col)
    {
        if (arr[x][y] == 1)
        {
            cout << "x:" << x << "\ty:" << y << endl;

            if (y + 1 < col)
            {
                cout << "**calling solveIt() --> "
                     << "x:" << x << "\ty:" << y + 1 << endl;
                if (solveIt(sum, arr, row, col, x, y + 1))
                    return true;
            }
            if (x + 1 < row)
            {
                cout << "**calling solveIt() --> "
                     << "x:" << x + 1 << "\ty:" << y << endl;
                if (solveIt(sum, arr, row, col, x + 1, y))
                    return true;
            }
            return false;
        }
        else
            return false;
    }
    else
        return false;
}
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
    int **sum = new int *[n];
    for (int i = 0; i < n; i++)
    {
        sum[i] = new int[m];
        for (int j = 0; j < m; j++)
            sum[i][j] = 0;
    }
    //    for(int i=0;i<n;i++){
    //    	for(int j=0;j<m;j++) cout<<arr[i][j]<<" ";
    //    	cout<<endl;
    //	}
    sum[n - 1][m - 1] = 1;
    if (solveIt(sum, arr, n, m, 0, 0))
        cout << "Total Path Possible : " << ::count << endl;
    else
        cout << "No possible path found!\n";

    cout << "Paths : " << sum[0] << endl;
    return 0;
}
