/*
In the faraway city of Codeland, a flu epidemic has broken out, caused by a strain known as hairy flu.
There are M people living in the city, each resident having a unique personal ID number from the range of 0 to M – 1, inclusive. Infection with this strain lasts exactly one day, and a person can catch it multiple times per season (since it mutates too quickly for lasting immunity).
On the first day of the epidemic, the flu was brought from another faraway country by a group of residents nicknamed “init-patients”, whose ID numbers are known. The flu's spread is based on them.
Each following day, a resident with ID number p will catch the flu iff there exists a resident with ID a who was infected the previous day, as well as an init-patient with ID b, such that:
                (a * b) mod M = p.
The numbers a and b need not be distinct. For example, consider a case where there are 101 people in the town, and the init-patients are 5 and 50. On the first day, the init-patients are infected by definition. On the second day, the residents infected are 25, 48 (250 mod 101), and 76 (2500 mod 101). On the third day, one of the infected patients is 77, since (48 * 50) mod 101 = 77.
Who will catch the flu on the K-th day?
Input Format:
The first line of input contains three positive integers, K, M, and N.
The second line of input contains N space-separated nonnegative integers, the personal ID numbers of residents who were infected on the first day (the init-patients). These numbers are unique, increasing, and do not exceed M - 1. 
Constraints:
1 ≤ K ≤ 10^18
3 ≤ M ≤ 1500 
N < M
Output Format:
The first and only line of output must contain the personal ID numbers of residents infected with flu on the K-th day, given space-separated and in increasing order. 
Sample Input 1:
1 100 3
1 2 3 
Sample Output 1:
1 2 3 
Sample Input 2:
2 100 3
1 2 3
Sample Output 2:
1 2 3 4 6 9
*/