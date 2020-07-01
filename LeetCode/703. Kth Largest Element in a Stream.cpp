#include <bits/stdc++.h>
using namespace std;
class KthLargest
{
    vector<int> arr;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto x : nums)
            insert(x);
    }
    void insert(int val)
    {
        arr.push_back(val);
        if (arr.size() == 1)
            return;
        int currentIndex = arr.size() - 1;
        int parentIndex;
        while (currentIndex > 0)
        {
            parentIndex = (currentIndex - 1) / 2;
            if (arr[parentIndex] < arr[currentIndex])
                swap(arr[parentIndex], arr[currentIndex]);
            else
                break;
            currentIndex = parentIndex;
        }
    }
    int fetch()
    {
        vector<int> temp = arr;
        int sizeArr = temp.size();
        
    }
    void printArr()
    {
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }
    int add(int val)
    {
        insert(val);
        // printArr();
        return fetch();
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    vector<int> in = {4, 5, 8, 2};
    KthLargest *sol = new KthLargest(3, in);
    vector<int> testcase = {3, 5, 10, 9, 4};
    for (auto x : testcase)
        cout << x << " : " << sol->add(x) << endl;
    return 0;
}