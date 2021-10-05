/**
 * Queue implementation using LinkedList
 * push(int d)   - O(1) - add at end ; enqueue
 * pop()         O(1)   - delete at front ; dequeue
 * front()       O(1)  - front node maintained
 * rear()       O(1)   - rear node maintained
 */

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d):data(d)
    {
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = rear = NULL;
    }

    // add at end
    void push(int d)
    {
        Node *newnode = new Node(d);
        if(rear == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }        
    }
    // delete at front
    void pop()
    {
        if(front == NULL)
        {
            return;
        }
        Node *temp = front->next;
        free(front);
        front = temp;
        if(front == NULL)
        {
            rear = NULL;
        }
    }
    // last added element
    int getrear()
    {
        return rear->data;
    }
    // first element
    int getfront()
    {
        return front->data;
    }
    void display()
    {
        Node *temp = front;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(2);
    q.push(30);

    q.display(); // 10 2 30
    cout<<q.getfront()<<endl;   // 10
    cout<<q.getrear()<<endl;   // 30
    q.pop();
    q.pop();
    cout<<q.getfront()<<endl;   // 30
    cout<<q.getrear()<<endl;   // 30
    return 0;
}
