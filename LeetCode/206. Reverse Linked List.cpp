/*
 * @File: 206. Reverse Linked List.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 9th September 2020 10:17:46 pm
 * @Last Modified: Wednesday, 9th September 2020 10:32:59 pm
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *out = NULL;
        while (head != NULL)
        {
            ListNode *nextNode = head->next;
            head->next = out;
            out = head;
            head = nextNode;
        }
        return out;
    }
};
int main()
{
    Solution *sol = new Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode *out = sol->reverseList(head);
    while (out != NULL)
    {
        cout << out->val << " -> ";
        out = out->next;
    }
    cout << "NULL\n";
    return 0;
}