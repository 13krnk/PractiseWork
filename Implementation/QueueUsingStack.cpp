/**
Implement queue using stack

M1- Using two stacks
stack1 - enque elements (push)
stack2 - deque elements (pop)

when push operaion called, keep push in enqeue stack
when pop operation,
if deque stack is empty, copy the elements from enqueu stack to dequeu stack.
pop enqueu stack.
if dequeu stack is not empty, take out the elemetn from deuque stack and pop it.

push - O(1)
pop - O(n) linear time
*/
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int>es;
    stack<int>ds;
public:
    void push(int i)
    {
        es.push(i);        
    }

    void pop()
    {
        if(es.empty() && ds.empty())
        {
            cout<<"empty stack"<<endl;
            return;
        }
        if(ds.empty())
        {
            while(!es.empty())
            {
                int t = es.top();
                es.pop();
                ds.push(t);
            }
        }
        cout<<"poped:"<<ds.top()<<endl;
        ds.pop();
    }

    int front()
    {
        if(es.empty() && ds.empty())
        {
            return -1;
        }
        if(ds.empty())
        {
            while(!es.empty())
            {
                int t = es.top();
                es.pop();
                ds.push(t);
            }
        }
        return ds.top();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
}