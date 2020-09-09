/*
 * @File: 225. Implement Stack using Queues.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 9th September 2020 10:58:05 pm
 * @Last Modified: Wednesday, 9th September 2020 11:20:25 pm
 */
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        queue<int> s;
        s.push(x);
        while (!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
        q = s;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int out = q.front();
        q.pop();
        return out;
    }

    /** Get the top element. */
    int top()
    {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
};
int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;
    return 0;
}