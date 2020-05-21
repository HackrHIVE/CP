#include<bits/stdc++.h>
using namespace std;
int minimizeBias(vector<int> ratings) {
    sort(ratings.begin(),ratings.end());
    int bias = 0;
    for(int i=0;i<ratings.size()-1;i+=2){
        bias += abs(ratings[i+1]-ratings[i]);
    }
    return bias;
}
int main(){

	return 0;
}
/*
A programming organization is planning a contest for several programmers, 
each of which has a certain rating. (The higher the rating, the better the programmer.)
 Each programmer is paired with another programmer, and the difference between their ratings 
 is denoted as the "bias amount". Given the ratings of all the programmers in the contest, 
 what is the minimum total bias amount that can be achieved by optimally planning the programmer 
 pairs? For example, let's say there are n = 4 programmers with ratings = [4, 2, 5, 1]. 
 The optimal solution is to pair the second programmer (2) with the fourth (1) for a difference of 1,
  and also the first programmer (4) with the third (5) for a difference of 1. This would result in a 
  total bias amount of 2. Because this is the minimum bias amount possible, the answer is 2.
*/
