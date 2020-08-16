/*
 * @File: String Pair.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Sunday, 16th August 2020 1:21:15 am
 * @Last Modified: Sunday, 16th August 2020 2:24:00 am
 * @Status: Not Accepted
 */
#include <iostream>
#include <unordered_map>
using namespace std;
string expand(int value)
{
    const char *const ones[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                                  "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                                  "eighteen", "nineteen"};
    const char *const tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                                  "eighty", "ninety"};
    if (value > 100)
        return "greater 100";
    else if (value == 100)
        return "hundred";
    else if (value >= 20)
    {
        string x = tens[value / 10];
        if (value % 10)
            x += " " + expand(value % 10);
        return x;
    }
    else
        return ones[value];
    return "";
}
int countVowel(string x)
{
    int out = 0;
    for (auto i : x)
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
            out++;
    return out;
}
int pairs2(int *arr, int n, int sum)
{
    int count = 0;
    int low = 0;
    int high = n - 1;
    for (int i = 0; i + 1 < n; i++)
    {
        int mid;
        low = i + 1;
        high = n - 1;
        int target = sum - arr[i];
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                count++;
                break;
            }
            if (arr[mid] > target)
                high--;
            else
                low++;
        }
    }
    return count;
    // while (low < high)
    // {
    //     if (arr[low] + arr[high] == sum)
    //         count++;
    //     if (arr[low] + arr[high] > sum)
    //         high--;
    //     else
    //         low++;
    // }
    // return count;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int count = 0;
    for (int i = 0; i < n; i++)
        count += countVowel(expand(arr[i]));
    cout << expand(pairs2(arr, n, count));
    delete[] arr;
}
