// #include <bits/stdc++.h>
// using namespace std;
// int maxLen = 0;
// void dfs(vector<vector<int>> &arr, int steps, int row,
//          int col, vector<vector<bool>> &visited,
//          int sX, int sY)
// {
//     if (sX == row && sY == col)
//     {
//         maxLen = max(maxLen, steps);
//         return;
//     }
//     visited[row][col] = true;
//     bool doneAndDusted = false;
//     if (row + 1 < arr.size())
//     {
//         if (!visited[row + 1][col])
//         {
//             dfs(arr, steps + 1, row + 1, col, visited, sX, sY);
//             doneAndDusted = true;
//         }
//     }
//     if (col + 1 < arr[0].size())
//     {
//         if (!visited[row][col + 1])
//         {
//             doneAndDusted = true;
//             dfs(arr, steps + 1, row, col + 1, visited, sX, sY);
//         }
//     }
//     if (row > 0)
//     {
//         if (!visited[row - 1][col])
//         {
//             doneAndDusted = true;
//             dfs(arr, steps + 1, row - 1, col, visited, sX, sY);
//         }
//     }
//     if (col > 0)
//     {
//         if (!visited[row][col - 1])
//         {
//             doneAndDusted = true;
//             dfs(arr, steps + 1, row, col - 1, visited, sX, sY);
//         }
//     }
//     if (!doneAndDusted)
//     {
//         cout << "doneAndDusted\n";
//         if (row + 1 == sX && col == sY)
//         {

//             maxLen = max(maxLen, steps + 1);
//             return;
//         }
//         if (row - 1 == sX && col == sY)
//         {

//             maxLen = max(maxLen, steps + 1);
//             return;
//         }
//         if (row == sX && col + 1 == sY)
//         {

//             maxLen = max(maxLen, steps + 1);
//             return;
//         }
//         if (row == sX && col - 1 == sY)
//         {

//             maxLen = max(maxLen, steps + 1);
//             return;
//         }
//     }
// }
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cout.tie(nullptr);
//     std::cin.tie(nullptr);
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> arr(m, vector<int>(n));
//     vector<vector<bool>> visited(m, vector<bool>(n));
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             cin >> arr[i][j];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i][j] == 1 && !visited[i][j])
//             {
//                 dfs(arr, 0, i, j, visited, i, j);
//             }
//         }
//     }
//     cout << maxLen << endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, int i,int j, int &count){
	if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0)
		return;
	count++;
	grid[i][j] = 0;
	dfs(grid,i+1,j,count);
	dfs(grid,i-1,j,count);
	dfs(grid,i,j+1,count);
	dfs(grid,i,j-1,count);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	int maxArea = 0;
	int m = grid.size(), n = grid[0].size();
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(grid[i][j] == 1){
				int temp = 0;
				dfs(grid,i,j,temp);
				maxArea = max(maxArea,temp);
			}
		}
	}
	return maxArea;
}
int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int> > grid ( m, vector<int> (n,0) );
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>grid[i][j];
	}
	cout<<maxAreaOfIsland(grid);
}