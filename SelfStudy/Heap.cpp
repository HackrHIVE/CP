#include <bits/stdc++.h>
using namespace std;
class Heap
{
    //getMin
    //removeMin
    //insert
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
                if (arr[parentIndex] > arr[currentIndex])
                    swap(arr[parentIndex], arr[currentIndex]);
                else
                    break;
                currentIndex = parentIndex;
            }
        }
    }
    int getMin()
    {
        if (arr.size() > 1)
            return arr[0];
        return -1;
    }
    void removeMin()
    {
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        int parentIndex = 0;
        int childLeft = (parentIndex * 2) + 1;
        int childRight = (parentIndex * 2) + 2;
        while (childLeft < arr.size())
        {
            int minIndex = parentIndex;
            int childMin = (arr[childLeft] > arr[childRight]) ? childRight : childLeft;
            if (arr[minIndex] > arr[childMin])
                minIndex = childMin;
            if (minIndex == parentIndex)
                break;
            swap(arr[parentIndex], arr[minIndex]);
            parentIndex = minIndex;
            childLeft = (parentIndex * 2) + 1;
            childRight = (parentIndex * 2) + 2;
        }
    }
    void heapSort(vector<int> &array)
    {
        
    }
};
int main()
{
    Heap *h = new Heap();
    h->insert(5);
    h->insert(3);
    h->insert(1);
    h->insert(10);
    cout << h->getMin() << endl;
    h->removeMin();
    cout << h->getMin() << endl;
    vector<int> arr = {};
    cout << "Before Heap Sort : \n";
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    h->heapSort(arr);
    cout << "After Heap Sort : \n";
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}