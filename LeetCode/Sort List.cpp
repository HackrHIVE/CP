/*
 * @File: Sort List.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Tuesday, 13th October 2020 7:26:43 pm
 * @Last Modified: Tuesday, 13th October 2020 7:35:49 pm
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
    ListNode *sortList(ListNode *head)
    {
        ListNode *unsortedHead = head;
        cout << "in sortList()\n";
        while (unsortedHead != NULL)
        {
            cout << "in whileLoop1\n";
            ListNode *iterator = unsortedHead;
            ListNode *minNode = unsortedHead;
            while (iterator != NULL)
            {
                cout << "in whileLoop2\n";
                if (iterator->val < minNode->val)
                {
                    minNode = iterator;
                }
                iterator = iterator->next;
            }
            int tempVal = unsortedHead->val;
            unsortedHead->val = minNode->val;
            minNode->val = tempVal;
            unsortedHead = unsortedHead->next;
        }
        return head;
    }
};
int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    Solution *sol = new Solution();
    ListNode *outHead = sol->sortList(head);
    while (outHead != NULL)
    {
        cout << outHead->val;
        if (outHead->next != NULL)
            cout << " -> ";
        outHead = outHead->next;
    }
    cout << endl;
    return 0;
}