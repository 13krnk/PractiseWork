/**
 * queue Implementation using array
 * Adding from one end and deleting from other end
 * 
 * // push pop front O(1)
 * array fixed size defined and no extra allocation and copying happened.
 */

#include<iostream>
using namespace std;

#define MAX 7
class Queue
{
int *q;
int front;
int rear;
int size;
public:
Queue(int size)
{
    q = new int[size];
    front = rear = -1;
    this->size = size;
}
~Queue() 
{
    delete[] q;
}
void push(int d)
{
    if(rear == size -1)  // queue full condition
    {
        cout<<"Queue is FUll"<<endl;
        return;
    }
    if(front == -1) // first time
    {
        front++;
    }
    q[++rear] = d;   
}

void pop()
{
    if(front == -1 && rear == -1) // queue is empty
    {
        cout<<"Queue is Empty"<<endl;
        return ;
    }
    if(front == rear) // single element exist
    {
        front = rear = -1;
    }
    else
    {
        cout<<"poped ele:"<<q[front]<<endl;
        front++;
    }
}
int getfront()
{
    return q[front];
}
int getback()
{
    return q[rear];
}
void display()
{
    if(front == -1)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    for(int i=front; i<=rear; i++)
    {
        cout<<q[i]<<" ";
    }
    cout<<endl;
}
};

int main()
{
    Queue *q = new Queue(5);
    q->push(1);
    q->push(2);
    q->push(3);
    q->display();   // 1 2 3
    q->pop();  // front 2
    q->push(4); 
    q->push(5);  
    q->push(6);  // full, drawback even empty space availble but not using
                  // thats why circular queue required.  
    cout<<q->getfront()<<endl; // 2
    cout<<q->getback()<<endl;  // 5  
    return 0;
}