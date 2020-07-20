#include <iostream>
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return NULL;

        ListNode *temp = head;

        while (head != NULL)
        {
            if (head->val != val)
                break;
            head = head->next;
            temp = head;
        }

        while (temp != NULL)
        {
            while (temp->next != NULL)
            {
                if (temp->next->val == val)
                    temp->next = temp->next->next;
                else
                    break;
            }
            temp = temp->next;
        }

        return head;
    }
};
int main()
{
    Solution *sol = new Solution();
    ListNode *root = new ListNode(1);
    root->next = new ListNode(1);
    ListNode *temp = sol->removeElements(root, 1);

    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }

    return 0;
}