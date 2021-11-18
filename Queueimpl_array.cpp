#include<iostream>
using namespace std;
#define MAX_SIZE 10
int front=-1;
int rear=-1;
int arr[MAX_SIZE];

bool isfull()
{
    if(front-rear==1)
        return true;
    else if(rear==MAX_SIZE && front==0)
        return true;
    return false;
}

bool isempty()
{
    if(front==-1 && rear==-1)
        return true;
    else if(front-rear==0)
        return true;
    return false;
}

void enqueue(int x)
{
    if(isfull())
    {
        cout<<"Cannot enqueue as array is full"<<endl;
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==MAX_SIZE-1)
        rear=0;
    else
        rear=rear+1;

    cout<<"rear="<<rear<<endl;
    arr[rear]=x;
    return;
}

void dequeue()
{
    if(isempty())
    {
        cout<<"Cannot dequeue as array is empty"<<endl;
        return;
    }
    else if(front==MAX_SIZE)
        front=0;
    else
    front=front+1;
    return;
}

void top()
{
    cout<<arr[front]<<endl;
    return;
}

int main()
{
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    top();
    dequeue();
    top();
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    enqueue(12);
    top();
    dequeue();
    top();
    return 0;
}
