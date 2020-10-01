/*
 * @File: RandomSongPlayer.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Thursday, 1st October 2020 6:26:50 pm
 * @Last Modified: Thursday, 1st October 2020 7:04:18 pm
 * @Question: The third question was to implement an audio/song player where 
 *            there are n songs and needs to be played in a randomized order and a played 
 *            song must not be repeated until all the unrepeated songs have been played. 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand((unsigned)time(0));
    int lo = 0;
    int hi = 9;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //Assuming we are going to play in total 65 songs.
    for (int i = 0; i < 65; i++)
    {
        while (hi > 0)
        {
            int index = rand() % (hi - lo);
            cout << arr[index] << endl;
            swap(arr[index], arr[hi]);
            //Swap Song on index with current hi
            //And then decrement hi
            //We will have left and right partition in which played songs will be on right side
            hi--;
        }
        cout << arr[hi] << endl;
        hi = 9;
    }
    return 0;
}