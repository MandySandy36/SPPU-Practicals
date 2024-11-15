#include <iostream> 
using namespace std; 
const int MAX=5; 
class Order 
{ 
    int order_id; 
    char orderer_name[10]; 
    public: 
    void acceptOrder() 
    { 
        cout<<"\nEnter Order ID :: "; 
        cin>>order_id; 
        cout<<"\nEnter Orderer Name ::"; 
        cin>>orderer_name; 
    } 
    void displayOrder() 
    { 
        cout<<"\n\t"<<order_id<<"\t\t"<<orderer_name; 
    } 
    friend class Queue; 
}; 
class Queue 
{ 
    Order data[MAX]; 
    int front,rear; 
    public: 
    Queue() 
    { 
        front=rear=-1; 
    } 
    void enqueue(); 
    void dequeue(); 
    int isFull(); 
    int isEmpty(); 
    void display(); 
}; 
//---------------------------------------------------- 
int Queue::isFull() 
{ 
    if((front==(rear+1)%MAX ))
        return 1; 
    else 
        return 0; 
} 
//---------------------------------------------------- 
int Queue::isEmpty() 
{ 
    if(rear==-1) 
        return 1; 
    else 
        return 0; 
} 
//---------------------------------------------------- 
void Queue::enqueue() 
{ 
    if(isFull()) 
    { 
        cout<<"\nCan't place order ! Queue is Full !"; 
    } 
    else 
    { 
        Order temp; 
        temp.acceptOrder(); 
        if(front==-1) 
        { 
            front=0; 
        } 
        rear=(rear+1)%MAX;
        data[rear]=temp; 
        cout<<"\nOrder Placed successfully"; 
    } 
} 
//---------------------------------------------------- 
void Queue::dequeue() 
{ 
    if(isEmpty()) 
    { 
        cout<<"\nNo orders to Serve !"; 
    } 
    else 
    { 
        front=(front+1)%MAX; 
        cout<<"\nOrder Served successfully !"; 
        if(front==rear) 
        front=rear=-1; 
    } 
} 
//---------------------------------------------------- 
void Queue::display() 
{ 
    if(isEmpty()) 
    { 
        cout<<"\nNo orders to display !"; 
    } 
    else 
    { 
        int i=front; 
        cout<<"\n\t----------- Orders in Queue -------------"; 
        cout<<"\n\n\tOrder ID\tOrderer Name"; 
        cout<<"\n\t-----------------------------------------"; 
        if(front<=rear) 
        { 
            while(i<=rear) 
            { 
                data[i].displayOrder(); 
                i++; 
            } 
        } 
        else 
        { 
            while(i<MAX) 
            { 
                data[i].displayOrder(); 
                i++; 
            } 
            i=0; 
            while(i<=rear) 
            { 
                data[i].displayOrder(); 
                i++; 
            } 
        } 
    } 
} 
//---------------------------------------------------- 
int main() 
{ 
    int ch; 
    Queue q; 
    cout<<"\n-------------- Pizza Parlor Menu --------------"; 
    cout<<"\n1. Place Order"; 
    cout<<"\n2. Serve Order"; 
    cout<<"\n3. Display Orders"; 
    cout<<"\n4. Exit"; 
    do 
    { 
        cout<<"\n--------------------------------------"; 
        cout<<"\nEnter your choice :: "; 
        cin>>ch; 
        cout<<"\n--------------------------------------"; 
        switch(ch) 
        { 
        case 1: 
            q.enqueue(); 
            break; 
        case 2: 
            q.dequeue(); 
            break; 
        case 3: 
            q.display(); 
            break; 
        } 
    }while(ch!=4); 
}