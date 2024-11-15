#include <iostream>
#define MAX 20
using namespace std;
class deque
{
	int x[MAX];
	int front;
	int rear;
	public:
		void initialize();
		void enqueueRight(int);
		void display();
		int dequeueLeft();
		void enqueueLeft(int);
		int dequeueRight();
};

void deque::initialize()
{
	front=-1;
	rear=-1;
}

void deque::enqueueRight(int p)
{
	if(rear==MAX)
	{
		cout<<"\nDequeue Full from Right\n";
	}
	else
	{
		x[++rear]=p;
		if(front==-1)
		{
			front=0;
		}
	}
}

void deque::enqueueLeft(int p)
{
	if(rear==-1 && front==-1)
	{
		enqueueRight(p);
	}
	else if(front==0)
	{
		cout<<"\nDequeue Full from Left\n";
	}
	else
	{
		x[--front]=p;
	}
}

int deque::dequeueLeft()
{
	int p;
	if(rear==-1 && front==-1)
	{
		cout<<"\nDequeue Empty!!!\n";
	}
	else if(front==rear)
	{
		p=x[front];
		front=rear=-1;
		return p;
	}
	else
	{
		return x[front++];
	}
}

int deque::dequeueRight()
{
	int p;
	if(rear==-1 && front==-1)
	{
		cout<<"\nDequeue Empty!!!\n";
	}
	else if(front==rear)
	{
		p=x[front];
		front=rear=-1;
		return p;
	}
	else
	{
		return x[rear--];
	}
}

void deque::display()
{
	int i;
	if(front==-1&&rear==-1)
	{
		cout<<"\nDequeue Empty!!!";
	}
	else
	{
		cout<<"\nDequeue is:\n";
		for(i=front;i<=rear;i++)
		{
			cout<<x[i]<<"\n";
		}
	}
}

int main()
{
	deque q;
	int ch,x,flag=1,c2;
	while(flag)
	{
		cout<<"\n\n1. Enqueue (From Front)\n2. Enqueue (From Rear)\n3. Dequeue Right\n4. Dequeue Left\n5. Display\n6. Exit\n\nChoice:-";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the Element: ";
				cin>>x;
				q.enqueueLeft(x);
				break;
		    case 2:
				cout<<"\nEnter the Element: ";
				cin>>x;
				q.enqueueRight(x);
				break;
		    case 3:
				x=q.dequeueRight();
				cout<<"\nRemoved "<<x<<" from the Dequeue\n";
				break;
		    case 4:
				x=q.dequeueLeft();
				cout<<"\nRemoved "<<x<<" form the Dequeue\n";
				break;
		    case 5:
				q.display();
				break;
			case 6:
				flag=0;
				break;
			default:
				cout<<"\nWrong choice!!! Try Again.\n";
		}
	}
	return 0;
}
