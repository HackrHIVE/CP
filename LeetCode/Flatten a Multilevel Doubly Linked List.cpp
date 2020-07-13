#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};
class Solution
{
public:
    Node *flatten(Node *head)
    {
        
    }
};
int main()
{
    Solution *sol = new Solution();
    Node *temp = new Node();
    temp->val = 10;
    Node *root = sol->flatten(temp);
    return 0;
}