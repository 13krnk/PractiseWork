/**
  stack Impementation Using Array
  void push(int d)   O(n) , if  array is fixed size then O(1)
  void pop()         O(1)
  int top()          O(1)
*/

#include<bits/stdc++.h>
using namespace std;

namespace local
{

class stack
{
    int *a;
    int capacity;
    int size;
public:
    stack(): size(0), capacity(1)
    {
        a = new int[1];
    }
    void push(int data)
    {
        if(size == capacity)
        {
            capacity = 2*capacity;
            int *b = new int[capacity];
            for(int i =0; i<capacity; i++)
            {
                b[i] = a[i];
            }
            delete[] a;
            a = b;
        }
        a[size++] = data;
    }
    void pop()
    {
        if(size <= 0)
        {
            cout<<"Stack underflow"<<endl;
            return;
        }
        int x = a[size-1];
        cout<<x<<" element poped"<<endl;
        size--;        
    }
    int top()
    {
        if(size <= 0)
        {
            cout<<"Empty stack"<<endl;
            return -1;
        }
        return a[size-1];
    }
    void print()
    {
        int i =0;
        while(i< size)
        {
            cout<<a[i]<<" ";
            i++;
        }
        cout<<endl;
    }
};

} // local

int main()
{
    local::stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    s.pop();
    s.pop();
    s.push(100);
    s.pop();
    s.pop();
    s.pop();
    s.print();
    cout<<s.top()<<endl;
    return 0;
}