
/**
Implement queue using stack

M2- Single stack
Using Single stack 

deque elements recursively keep in memory and push back to stack
push - O(1)
pop - O(n) linear time
*/

#include<bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int>es;
public:
    void push(int i)
    {
        cout<<i<<" pushed"<<endl;
        es.push(i);        
    }

    int recurse_pop()
    {
        if(es.size() == 1)
        {
            cout<<es.top()<<"popped"<<endl;
            int t = es.top();
            es.pop();
            return t;
        }
        
        int cur = es.top();
        es.pop();
        int res = recurse_pop();
        es.push(cur);
        return res;
    }

    int front()
    {        
        return es.top();
    }
    void print()
    {
        while (!es.empty())
        {
            cout<<es.top()<<" ";
            es.pop();
        }
    }    
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.recurse_pop();  // 1 poped
    cout<<q.front()<<endl; // 4
    q.recurse_pop();  // 2 poped
    q.print();    // 4 3 
}