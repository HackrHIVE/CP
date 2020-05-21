#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = NULL;
    ListNode* even = NULL;
    ListNode* evenStart = NULL;
    ListNode* oddStart = NULL;
    odd = head;
    oddStart = odd;
    if(head->next == NULL) return odd;
    evenStart = odd->next;
    even = odd->next;
    while(even && odd){
        cout<<"Current ODD : "<<odd->val<<endl;
        cout<<"Current EVEN : "<<even->val<<endl;
        if(!even->next) break;
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
        cout<<"NEW ODD : "<<odd->val<<endl;
        if(even)cout<<"NEW EVEN : "<<even->val<<endl;
    }
    odd->next = evenStart;
    return oddStart;
}
int main(){
    ListNode* obj = new ListNode(1);
    obj->next = new ListNode(2);
    obj->next->next = new ListNode(3);
    obj->next->next->next = new ListNode(4);
    obj->next->next->next->next = new ListNode(5);
    obj->next->next->next->next->next = new ListNode(6);
    obj->next->next->next->next->next->next = new ListNode(7);
    obj->next->next->next->next->next->next->next = new ListNode(8);
    ListNode* out = oddEvenList(obj);
    while(out){
        cout<<"X : ";
        cout<<out->val<<endl;
        out = out->next;
    }
    return 0;
}