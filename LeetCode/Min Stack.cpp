#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int min;
};
class MinStack {
public:
    /** initialize your data structure here. */
    stack <Node*> arr;
    
    MinStack() {
    	
    }
    
    void push(int x) {
        Node *op = new Node();
        op->data = x;
        if(arr.size()==0){
        	op->min = x;
		}
		else{
			Node *oldMin = arr.top();
			if(oldMin->min > x){
				op->min = x;
			}
			else op->min = oldMin->min;
		}
		arr.push(op);
    }
    
    void pop() {
        arr.pop();
    }
    
    int top() {
    	if(arr.size() == 0) return 0;
        Node *toppy = arr.top();
        return toppy->data;
    }
    
    int getMin() {
    	if(arr.size() == 0) return 0;
        Node *toppy = arr.top();
        return toppy->min;
    }
};
int main(){
	MinStack* obj = new MinStack();
	obj->push(5);
	obj->push(55);
	obj->push(51);
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();
	cout<<"3 : "<<param_3<<endl;
	cout<<"4 : "<<param_4<<endl;
	return 0;
}

