#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    return mergeKLists(vector<ListNode*>{l1,l2});
}
void printMyList(ListNode* head){
    while(head!= NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(4);
    ListNode* node2 = new ListNode(1);
    node2->next = new ListNode(3);
    node2->next->next = new ListNode(4);
    ListNode* out = mergeTwoLists(node1,node2);
    printMyList(out);
    return 0;
}