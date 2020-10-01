#include <bits/stdc++.h>
using namespace std;
class Heap
{
    vector<int> arr;

public:
    Heap()
    {
    }
    void insert(int val)
    {
        arr.push_back(val);
        if (arr.size() > 1)
        {
            int currentIndex = arr.size() - 1;
            while (currentIndex > 0)
            {
                int parentIndex = (currentIndex - 1) / 2;
                if (arr[parentIndex] < arr[currentIndex])
                    swap(arr[parentIndex], arr[currentIndex]);
                else
                    break;
                currentIndex = parentIndex;
            }
        }
    }
    int getMax()
    {
        if (arr.size() > 1)
            return arr[0];
        return -1;
    }
    void removeMax()
    {
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        int parentIndex = 0;
        int childLeft = (parentIndex * 2) + 1;
        int childRight = (parentIndex * 2) + 2;
        while (childLeft < arr.size())
        {
            int maxIndex = parentIndex;
            int childMin = (arr[childLeft] < arr[childRight]) ? childRight : childLeft;
            if (arr[maxIndex] < arr[childMin])
                maxIndex = childMin;
            if (maxIndex == parentIndex)
                break;
            swap(arr[parentIndex], arr[maxIndex]);
            parentIndex = maxIndex;
            childLeft = (parentIndex * 2) + 1;
            childRight = (parentIndex * 2) + 2;
        }
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    Heap *h = new Heap();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        h->insert(arr[i]);
    }
    cout << h->getMax() << endl;
    
    return 0;
}