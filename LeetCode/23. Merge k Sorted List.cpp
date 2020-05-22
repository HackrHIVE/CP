#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printMyList(ListNode* head){
    while(head->next != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
ListNode* mergeKLists(vector<ListNode*> lists) {
    ListNode* tempList = NULL;
    ListNode* currentNode;
    while(true){
        ListNode* minItem = NULL;
        int index = -1;
        for(int i=0;i<lists.size();i++){
            if(lists[i] == NULL){
                continue;
            }
            if(minItem == NULL){
                minItem = lists[i];
                index = i;
                continue;
            }
            if(lists[i]->val < minItem->val){
                minItem = lists[i];
                index = i;
            }
        }
        if(minItem == NULL || index == -1){
            // printMyList(tempList);
            break;
        }
        if(tempList == NULL){
            tempList = new ListNode(minItem->val);
            currentNode = tempList;
            if(lists[index]->next == NULL) lists[index] = NULL;
            else lists[index] = lists[index]->next;
            continue;
        }
        currentNode->next = minItem;
        currentNode = currentNode->next;
        if(lists[index]->next == NULL) lists[index] = NULL;
        else lists[index] = lists[index]->next;
    }
    return tempList;
}
int main(){
    /*
    The Hard Way - with proper LinkedList.
    This problem could be done easily with pushing all the values into a vector and then
    sorting that vector , we can create a linkedlist and return the head node.
    */
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(4);
    node1->next->next = new ListNode(5);
    ListNode* node2 = new ListNode(1);
    node2->next = new ListNode(3);
    node2->next->next = new ListNode(4);
    ListNode* node3 = new ListNode(2);
    node3->next = new ListNode(6);
    ListNode* newNode = mergeKLists(vector<ListNode*>{node1,node2,node3});
    cout<<"GOT HeadNode\n";
    return 0;
}