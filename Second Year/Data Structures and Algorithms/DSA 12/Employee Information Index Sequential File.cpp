#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Emp
{
  	int empid;
	char name[20];
	char design[20];
	float salary;
   	public: 
		Emp()
		{
			empid=0;
			strcpy(name,"");
			strcpy(design,"");
			salary=0.0;
		}
		int acceptempid()
		{
			return(empid);
		}
		void getdata()
		{
			cout<<"\nEnter Emp details:";
			cout<<"\nEnter emp id:";
			cin>>empid;
			cout<<"Enter emp name : ";
			cin>>name;
			cout<<"Enter Designation : ";
			cin>>design;
			cout<<"Enter salary: ";
			cin>>salary;
		}
		void display()
		{
			cout<<"\n Emp Details";
			cout<<"\n Emp id = "<<empid;
			cout<<"\n Emp Name = "<<name;
			cout<<"\n Designation = "<<design;
			cout<<"\n Salary = "<<salary;
		}
};
class fileop
{
	ifstream fin;
	ofstream fout;
	fstream fs;
	public:
		void insert();
		void show();
		void search(int);
		int deleterecord(int);
		int append(int);
};
void fileop::insert()
{
	Emp obj;
	obj.getdata();
	fout.open("data.txt",ios::ate|ios::app);
	fout.write((char*)&obj,sizeof(obj));
	fout.close();
}
void fileop::show()
{
	Emp obj;
	fin.open("data.txt");
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		obj.display();
	}
	fin.close();
}
void fileop::search(int rno)
{
	Emp obj;
	int flag=0;
	fin.open("data.txt");
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		if(obj. acceptempid()==rno)
		{
			flag=1;
			break;
		}
	}
	fin.close();
	if(flag==1)
	{
		cout<<"\n Emp found";
		obj.display();
	}
	else
	{
		cout<<"\n Emp not found";
	}
}
int fileop::deleterecord(int rno)
{
	Emp obj;
	int flag=0;
	fin.open("data.txt");
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		if(obj. acceptempid()==rno)
		{
			flag=1;
		}
		else
		{
			fout.write((char*)&obj,sizeof(obj));
		}
	}
	fin.close();
	fout.close();
	remove("data.txt");
	rename("temp.txt","data.txt");
	return(flag);
}
int fileop::append(int rno)
{
	Emp obj;
	int flag=0;
	fs.open("data.txt");
	fs.seekg(0,ios::beg);
	while(fs.read((char*)&obj,sizeof(obj)))
	{
		if(obj. acceptempid()==rno)
		{
			flag=1;
			cout<<"\n Enter new details: ";
			obj.getdata();
			fs.seekp((int)fs.tellg()-sizeof(obj),ios::beg);
			fs.write((char*)&obj,sizeof(obj));
		}
	}
	fs.close();
	return(flag);
}
 
      
int main()
{
   fileop fobj;
    char ch='y';
    int choice,key, n;
    do{
        cout<<"\n Main Menu";
        cout<<"\n 1. Create";
        cout<<"\n 2. Display";
        cout<<"\n 3. Search";
        cout<<"\n 4. Delete";
        cout<<"\n 5. Append";
        cout<<"\n 6. Exit";
        cout<<"\n Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: 
		fobj.insert();
            		break;
            case 2: 
		fobj.show();
            		break;
            case 3: 
             		cout<<"\n Enter emp id to search : ";
              	cin>>n;
              	fobj.search(n);
            		break;
            case 4: 
              	cout<<"\n Enter emp id to delete : ";
              	cin>>n;
              	fobj.deleterecord(n);
            		break;
            case 5: 
               	cout<<"\n Enter emp id to edit : ";
              	cin>>n;
              	fobj.append(n);
            		break;
            case 6: 
		exit(0);
        }
    	cout<<"\n Do you want to continue:";
    	cin>>ch;
    }while(ch=='y');
    return 0;
}
