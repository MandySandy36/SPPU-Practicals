#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class student
{
	private:
		int roll;
		float marks;
		char name[20];
	public:
		void accept()
		{
			cout<<"\nEnter roll no:";
			cin>>roll;
			cout<<"\nEnter marks of student:";
			cin>>marks;
			cout<<"\nEnter name of student:";
			cin>>name;
		}
		void display()
		{ 
			cout<<"\nName : "<<name;
			cout<<"\nRoll no: "<<roll;
			cout<<"\nMarks are: "<<marks;
		}
};
int main()
{
	int ch,n,i;
	fstream f;
	student s[10];
	while(1)
	{
		cout<<"\nMenu :";
		cout<<"\n1.Create :";
		cout<<"\n2.write :";
		cout<<"\n3.read :";
		cout<<"\n4.append :";
		cout<<"\n5.exit :";
		cout<<"\nEnter ur choice:";
		cin>>ch;
		switch(ch) 
		{
			case 1:
				f.open("file.txt",ios::out);
				cout<<"\nFile is successfully created :";
				f.close();
				break;
			case 2:
				f.open("file.txt",ios::out | ios::app);
				cout<<"\nhow many students do u want to enter:";
				cin>>n;
				for(i=0;i<n;i++)
				{
					s[i].accept();
					f.write((char*)& s,sizeof (s));
				}
				f.close();
				break;
			case 3:
				f.open("file.txt",ios::in );
				for(i=0;i<n;i++) 
				{
					f.read((char*)& s,sizeof (s));
					s[i].display();
				}
				f.close();
				break;
			case 4:
				{
					f.open("file.txt",ios::app);
					s[i].accept();
					f.write((char*)& s,sizeof (s));
					n++;
					f.close();
				}
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}
