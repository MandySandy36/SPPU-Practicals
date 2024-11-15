#include<iostream>
#define SIZE 10
using namespace std;
class priority
{
	int Queue1[SIZE],front,rear;
	public:
		priority()
		{
			front=0;
			rear=-1;
		}
		int isFull();
		int isEmpty();
		void Enqueue(int x);
		int Dequeue();
};

int priority::isFull()
{
	if(rear==SIZE-1)
		return 1;
	else
		return 0;
}

int priority::isEmpty()
{
	if(rear==front-1)
		return 1;
	else
		return 0;
}

int priority::Dequeue()
{
	if(isEmpty()==1)
	{
		cout<<endl<<" Queue EMPTY...!";
	}
	else
	{
		return Queue1[front++];
	}
}

void priority::Enqueue(int x)
{
	if(isFull()==1)
	{
		cout<<endl<<" Queue full..!";
	}
	else
	{
		rear++;
		if(rear==0)
			Queue1[rear]=x;
		else
		{
			int index;
			
			for(index=rear-1; index>=0; index--)
			{
				if(x < Queue1[index])
				{
					Queue1[index+1]=Queue1[index];
				}
				else
				{
					break;
				}
			}
			Queue1[index+1]=x;
		}
		cout<<endl<<"Priority Queue: ";
		for(int i=0;i<=rear;i++)
		cout<<Queue1[i]<<",";
	}
}

int main()
{
	priority obj;
	int i, n, p, d;
	cout<<"\n How many jobs: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter job(1-9): ";
		cin>>p;
		obj.Enqueue(p);
	}
	cout<<"\n Dequeue:";
	while(!obj.isEmpty())
	{
		d=obj.Dequeue();
		cout<<endl<<d<<", ";
	}	
	cout<<endl;
	return 22;
}