#include <bits/stdc++.h>
using namespace std;
char *characterAt(char *input1, int input2)
{
    int size = 0;
    char *error = new char[2];
    error[0] = '-';
    error[1] = '1';
    for (int i = 1; input1[i] != 0; i += 2)
    {
        if (input1[i] >= 48)
            size += input1[i] - 48;
    }
    if (input2 > size)
        return error;
    char *out = new char[size];
    int index = 0;
    for (int i = 0; input1[i] != 0; i += 2)
    {
        if (input1[i] >= 97 && input1[i] <= 122 && input1[i + 1] >= 48 && input1[i + 1] <= 57)
        {
            char temp = input1[i];
            int frq = input1[i + 1] - 48;
            while (frq-- && frq >= 0)
            {
                out[index++] = temp;
            }
        }
        else
            return error;
    }
    char *charOut = new char[1];
    charOut[0] = out[input2 - 1];
    return charOut;
}
int main()
{
    char *arr = new char[4];
    arr[0] = 'a';
    arr[1] = '3';
    arr[2] = 'b';
    arr[3] = '2';
    // arr[4] = 'f';
    // arr[5] = '3';
    char *out = characterAt(arr, 4);
    cout << out << endl;
    return 0;
}