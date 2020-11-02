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
    bool isPalindrome(ListNode *head)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        int firstHalf = 0;
        int lo = 1;
        int mid = size / 2;
        int hi = size;
        temp = head;
        while (lo <= mid)
        {
            cout << "lo : " << lo << endl;
            if (firstHalf > 0)
                firstHalf *= 10;
            firstHalf += temp->val;
            lo++;
            temp = temp->next;
            cout << "Set to " << temp->val << endl;
        }
        cout << "firstHalf -> " << firstHalf << endl;
        if (size % 2 != 0)
        {
            lo++;
            temp = temp->next;
            cout << "Skipping\n";
        }
        while (lo <= hi)
        {
            cout << "Current -> " << temp->val << endl;
            int last = firstHalf % 10;
            if (last != temp->val)
                return false;
            firstHalf /= 10;
            temp = temp->next;
            lo++;
        }
        return true;
    }
};
int main()
{
    Solution *sol = new Solution();
    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(2);
    node->next->next->next = new ListNode(1);
    cout << sol->isPalindrome(node) << endl;
    return 0;
}