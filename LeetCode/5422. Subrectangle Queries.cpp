#include <bits/stdc++.h>
using namespace std;
class SubrectangleQueries
{
public:
    vector<vector<int>> rec;
    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        rec = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                rec[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        return rec[row][col];
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    vector<vector<int>> rectangle = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    SubrectangleQueries *obj = new SubrectangleQueries(rectangle);
    obj->updateSubrectangle(0, 0, 2, 2, 100);
    cout << obj->getValue(0, 0) << endl;
    return 0;
}