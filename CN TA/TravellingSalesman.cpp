/*
Travelling Salesman
Send Feedback
Chances are that you have probably already heard of the travelling salesman problem. If you have, then you are aware that it is an NP-hard problem because it lacks an efficient solution. Well, this task is an uncommon version of the famous problem! Its uncommonness derives from the fact that this version is, actually, solvable.
The travelling salesman is on a mission to visit N cities, each exactly once. The cities are represented by numbers 1, 2, ..., N. What we know is the direct flight duration between each pair of cities. The salesman, being the efficient man that he is, wants to modify the city visiting sequence so that the total flight duration is the minimum possible.
Alas, all is not so simple. In addition, the salesman has a peculiar condition regarding the sequence. For each city labeled K must apply: either all cities with labels smaller than K have been visited before the city labeled K or they will all be visited after the city labeled K. In other words, the situation when one of such cities is visited before, and the other after is not allowed.
Assist the poor fellow in his ambitious mission and calculate the minimum total flight duration needed in order to travel to all the cities, starting from whichever and ending in whichever city, visiting every city exactly once, so that his peculiar request is fulfilled.
Input Format:
The first line of input contains the positive integer N, the number of cities.
Each of the following N lines contains N positive integers, say Xi. 
The number in Bth place in the Ath row represents the flight duration between cities A and B; that number is equal to the Ath number in the Bth row. When A = B, that number is 0. Otherwise, it is a positive value.  
Constraints:
2 ≤ N ≤ 1500
0 ≤ Xi ≤ 1000
Output Format:
The first and only line of output must contain the required minimum total flight duration. 
Sample Input 1:
3
0 5 2
5 0 4
2 4 0 
Sample Output 1:
7
Explanation:
The optimal sequence is 2, 1, 3 or 3, 1, 2. The sequence 1, 3, 2 is even more favourable, but it does not fulfill the salesman's condition
Sample Input 2:
4
0 15 7 8
15 0 16 9
7 16 0 12
8 9 12 0 
Sample Output 2:
31
Explanation:
The optimal sequence is 3, 1, 2, 4. The total flight duration via this route is 31.
*/