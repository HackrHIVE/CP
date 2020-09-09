/*
 * @File: 232. Implement Queue using Stacks.cpp
 * @Author: Chirag Rawal (@hackrhive)
 * @File Created: Wednesday, 9th September 2020 10:34:54 pm
 * @Last Modified: Wednesday, 9th September 2020 10:57:58 pm
 */
#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    /** Initialize your data structure here. */
    stack<int> s;
    int front;
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stack<int> temp;
        while (!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        front = x;
        temp.push(x);
        while (!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int out = s.top();
        s.pop();
        return out;
        // stack<int> temp;
        // while (!s.empty())
        // {
        //     temp.push(s.top());
        //     s.pop();
        // }
        // int out = temp.top();
        // temp.pop();
        // while (!temp.empty())
        // {
        //     s.push(temp.top());
        //     front = temp.top();
        //     temp.pop();
        // }
        // return out;
    }

    /** Get the front element. */
    int peek()
    {
        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s.empty();
    }
};
int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << obj->peek() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;
    return 0;
}