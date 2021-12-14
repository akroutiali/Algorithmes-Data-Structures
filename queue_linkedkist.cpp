#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int value;
    Node*next;
    Node(int val)
    {
        value=val;
    }
};
class Queue 
{
    private:
    Node*start=nullptr;
    Node*last=nullptr;
    public:
    Queue()
    {
        start=nullptr;
        last=nullptr;
    }
   void enqueue(int val)
   {
    if(start==nullptr)
    {
        start=new Node(val);
        last=start;
    }
    else
    {
        last->next=new Node(val);
        last=last->next;
    }
    
    }
    void dequeue()
    {
        if(start == nullptr)
        return;
        else
        start=start->next;
        if(start ==nullptr)
        last=start;
    }
    void print()
    {
        Node* current =start;
        while(current != nullptr)
        {
            cout<<current->value<<endl;
            current=current->next;
        }
        
    }
    void top()
    {
        if(last ==nullptr)
        cout<<"the queue is empty"<<endl;
        else
        cout<<"the top element is"<<last->value<<endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.top();
    q.enqueue(20);
    q.dequeue();
    q.top();
    

    return 0;
}
