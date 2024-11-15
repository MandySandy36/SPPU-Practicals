#include<iostream>
using namespace std;
class strng
{	public:
        char cInp[30],cWSpace[30],cStack[20],cReverse[30];
        int top;
		strng()
		{
			top=-1;
		}
		void Palindrome1();
		void reverse1();
		void push(char );
		char pop();
};

void strng :: push(char element)
{
	if(top<20)
		cStack[++top]=element;
	else
		cout<<"Stack Full";
}

char strng :: pop()
{
	if(top!=-1)
		return cStack[top--];
	else
		cout<<"Stack Empty";
}

void strng :: Palindrome1()
{
	int i=0,b=1;
	cout<<"\n\nEnter the String:";
	cin>>cWSpace;
	cout<<"\n\nEntered the String is:"<<cWSpace;
	while(cWSpace[i]!='\0')
	{
		push(cWSpace[i]);
		i++;
	}
	i=0;
	while(cWSpace[i]!='\0')
	{
		char ch=pop();
		if(cWSpace[i]!=ch)
			b=0;
		i++;
	}
	if(b==1)
	    cout<<"\n\nTHE STRING IS PALINDROME";
	else
	    cout<<"\n\nTHE STRING IS NOT PALINDROME";
}

void strng :: reverse1()
{
	int i=0;
	cout<<"\nEnter the String:";
	cin>>cWSpace;
	cout<<"\nEntered the String is:"<<cWSpace;
	while(cWSpace[i]!='\0')
	{
		push(cWSpace[i]);
		i++;
	}
	i=0;
	while(cWSpace[i]!='\0')
	{
		char ch=pop();
		cReverse[i]=ch;
		i++;
	}
	cReverse[i]='\0';
	cout<<"\nReverse String is:"<<cReverse;
	cout<<"\n";	
}


int main()
{	
	strng a;
    a.Palindrome1();
	a.reverse1();
	return 0;	
}