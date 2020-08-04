#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next, *prev;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
class LinkedList
{
    ListNode *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void mainMenu()
    {
        cout << "1.Add a node" << endl;
        cout << "2.Display LinkedList" << endl;
        cout << "3.Reverse LinkedList" << endl;
        cout << "Choice =>> ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addMenu();
            break;
        case 2:
            display();
            break;
        case 3:
            reverse();
            break;
        }
    }
    void addMenu()
    {
        cout << "Value to add : ";
        int value;
        cin >> value;
        ListNode *new_node = new ListNode();
        new_node->data = value;

        new_node->next = head;
        new_node->prev = NULL;

        if (head != NULL)
            head->prev = new_node;

            head = new_node;
        cout << value << " added in the linkedlist\n";
        mainMenu();
    }
    void display()
    {
        ListNode *node = head;
        ListNode *last;
        while (node != NULL)
        {
            printf(" %d ", node->data);
            last = node;
            node = node->next;
        }
        cout << endl;
        mainMenu();
    }
    void reverse()
    {
        ListNode *temp = NULL;
        ListNode *current = head;

        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL)
            head = temp->prev;

        mainMenu();
    }
};
int main()
{
    LinkedList *obj = new LinkedList();
    obj->mainMenu();
    return 0;
}