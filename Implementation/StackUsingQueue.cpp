/**
 * Stack using queue
 * 
 * Using two queues
 * push operation costly O(n)
 * pop O(1)
 */ 
#include<bits/stdc++.h>
using namespace std;

class StackUsingQueue
{
private:
    queue<int>q1, q2;
public:
    void push(int i)
    {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(i);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        /*
        q2.push(i);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        */
        cout<<i<< "pushed"<<endl;       
    }
    void pop()
    {
        if(q1.empty())
        {
            cout<<"empty queue"<<endl;
            return;
        }
        cout<<q1.front()<<"poped"<<endl;
        q1.pop();
    }
    int top()
    {
        if(q1.empty())
        {
            cout<<"NO elements"<<endl;
            return -1;
        }
        return q1.front();
    }
};

int main()
{
    StackUsingQueue sq;
    sq.push(1);
    sq.push(2);
    sq.push(3);
    sq.push(4);
    cout<<sq.top()<<endl; // 4 
    sq.pop();  // 4 poped
    cout<<sq.top()<<endl;  // 3
    return 0;
}
