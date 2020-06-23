#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
};
class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    Node *root;
    int size;
    MyLinkedList()
    {
        root = NULL;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= size)
            return -1;
        int i = 0;
        Node *temp = root;
        while (i < size)
        {
            if (i == index)
                return temp->data;
            temp = temp->next;
            i++;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = root;
        root = newNode;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        Node *temp = root;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        Node *temp = root;
        int i = 0;
        while (i < size)
        {
            if (i + 1 == index)
            {
                Node *newNode = new Node();
                newNode->data = val;
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
            i++;
        }
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        if (index == 0)
        {
            root = root->next;
            size--;
            return;
        }
        Node *temp = root;
        int i = 0;
        while (i + 1 != index)
        {
            temp = temp->next;
            i++;
        }
        Node *toDelete = temp->next;
        size--;
        temp->next = temp->next->next;
        delete toDelete;
    }
    void printAll()
    {
        cout << "LinkedList : ";
        Node *temp = root;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    MyLinkedList *obj;
    vector<string> inFun = {"MyLinkedList", "addAtHead", "addAtIndex", "get", "addAtHead", "addAtTail", "get", "addAtTail", "get", "addAtHead", "get", "addAtHead"};
    vector<vector<int>> inArg = {{}, {5}, {1, 2}, {1}, {6}, {2}, {3}, {1}, {5}, {2}, {2}, {6}};
    for (int i = 0; i < inFun.size(); i++)
    {
        cout << "i : " << i << " : ";
        string x = inFun[i];
        if (x.compare("MyLinkedList") == 0)
        {
            cout << "Calling MyLinkedList()\n";
            obj = new MyLinkedList();
        }
        else if (x.compare("deleteAtIndex") == 0)
        {
            cout << "Calling deleteAtIndex(" << inArg[i][0] << ")\n";
            obj->deleteAtIndex(inArg[i][0]);
        }
        else if (x.compare("addAtIndex") == 0)
        {
            cout << "Calling addAtIndex(" << inArg[i][0] << "," << inArg[i][1] << ")\n";
            obj->addAtIndex(inArg[i][0], inArg[i][1]);
        }
        else if (x.compare("addAtTail") == 0)
        {
            cout << "Calling addAtTail(" << inArg[i][0] << ")\n";
            obj->addAtTail(inArg[i][0]);
        }
        else if (x.compare("addAtHead") == 0)
        {
            cout << "Calling addAtHead(" << inArg[i][0] << ")\n";
            obj->addAtHead(inArg[i][0]);
        }
        else if (x.compare("get") == 0)
        {
            cout << "Calling get(" << inArg[i][0] << ") => ";
            cout << obj->get(inArg[i][0]) << endl;
        }
        cout << "Calling printAll()\t";
        obj->printAll();
    }
    return 0;
}