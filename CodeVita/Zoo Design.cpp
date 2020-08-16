/*
 * @File: Zoo Design.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Sunday, 16th August 2020 12:31:05 am
 * @Last Modified: Sunday, 16th August 2020 2:13:18 am
 * @Status: Accepted
 */
#include <bits/stdc++.h>
using namespace std;
struct Animals
{
    int cost, minNo, maxArea, areaPerAnimal;
};
bool myWay(Animals x, Animals y)
{
    return x.cost > y.cost;
}
int main()
{
    Animals *arr = new Animals[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i].cost;
    for (int i = 0; i < 3; i++)
        cin >> arr[i].maxArea;
    for (int i = 0; i < 3; i++)
        cin >> arr[i].minNo >> arr[i].areaPerAnimal;
    int totalArea;
    cin >> totalArea;
    sort(arr, arr + 3, myWay);
    int totalCost = 0;
    int remainingArea = totalArea;
    int index = 0;
    while (remainingArea > 0 && index < 3)
    {
        Animals obj = arr[index];
        int currArea = obj.minNo * obj.areaPerAnimal;
        remainingArea -= currArea;
        totalCost += currArea * obj.cost;
        index++;
    }
    index--;
    while (remainingArea > 0 && index >= 0)
    {
        Animals obj = arr[index];
        int currArea = obj.minNo * obj.areaPerAnimal;
        int addArea = obj.maxArea - currArea;
        if (addArea > remainingArea)
            totalCost += remainingArea * obj.cost;
        else
            totalCost += addArea * obj.cost;
        remainingArea -= addArea;
        index--;
    }
    cout << totalCost;
    delete[] arr;
    return 0;
}
*