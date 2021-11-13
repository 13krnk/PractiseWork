/**
 * Stack implementation using linkedList
 * push(int d)   O(1)
 * pop()         O(1)
 * top()         O(1)
 */
 #include<iostream>
 using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d):data(d)
    {
        this->next= NULL;
    }
};

 class Stack
 {
 public:   
    Node *head;  // head node.
    Stack()
    {
        head = NULL;
    }
    // add at start.
    void push(int d)
    {
        Node *newnode = new Node(d);
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    // delete at first
    void pop()
    {
        if(head == NULL)
        {
            return;
        }
        Node *temp = head->next;
        free(head);
        head = temp;
    }
    // top element
    int top()
    {
        return head->data;
    }
    // display
    void display()
    {
        Node *temp = head;
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
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();  // 30 20 10
    cout<<s.top()<<endl;  // 30
    s.pop();  
    s.pop();
    cout<<s.top()<<endl;  // 10
    return 0;
}