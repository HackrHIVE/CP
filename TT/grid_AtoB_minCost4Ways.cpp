#include <iostream>
using namespace std;
int MinCost = INT_MAX;
void findPath(int **arr, bool **visited, int row, int col, int x, int y, int cost)
{
  visited[x][y] = true;

  if (x == row && y == col)
  {
    cost += arr[x][y];
    if (cost < MinCost)
      MinCost = cost;
    visited[x][y] = false;
    return;
  }
  //up
  if (x > 0)
  {
    if (arr[x - 1][y] != 0)
    {
      if (!visited[x - 1][y])
      {
        findPath(arr, visited, row, col, x - 1, y, cost + arr[x][y]);
      }
    }
  }
  //right
  if (y < col)
  {
    if (arr[x][y + 1] != 0)
    {
      if (!visited[x][y + 1])
      {
        findPath(arr, visited, row, col, x, y + 1, cost + arr[x][y]);
      }
    }
  }
  //bottom
  if (x < row)
  {
    if (arr[x + 1][y] != 0)
    {
      if (!visited[x + 1][y])
      {
        findPath(arr, visited, row, col, x + 1, y, cost + arr[x][y]);
      }
    }
  }
  //left
  if (y > 0)
  {
    if (arr[x][y - 1] != 0)
    {
      if (!visited[x][y - 1])
      {
        findPath(arr, visited, row, col, x, y - 1, cost + arr[x][y]);
      }
    }
  }

  visited[x][y] = false;
}
/*
INPUT
3 3
1 0 1
1 1 1
0 1 1
OUTPUT
3
*/
int main()
{
  int row, col;
  cin >> row >> col;
  int **arr = new int *[row];
  bool **visited = new bool *[row];
  for (int i = 0; i < row; i++)
  {
    arr[i] = new int[col];
    visited[i] = new bool[col];
    for (int j = 0; j < col; j++)
    {
      cin >> arr[i][j];
      visited[i][j] = false;
    }
  }
  findPath(arr, visited, row - 1, col - 1, 0, 0, 0);
  cout << MinCost << endl;
  return 0;
}
