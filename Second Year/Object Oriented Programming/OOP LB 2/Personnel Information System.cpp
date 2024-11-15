#include<iostream>
#include<cstring>
using namespace std;
class db
{
    int rollno;
    char name[20];
    char Class[10];
    char div[10];
    char dob[10]; 
    char bg[5];
    char contact[10];
    char phone[10]; 
    char license[12];
    public:
        static int stdno;
        static int count()
        {
            cout<<"\n No. of object created:"<<stdno;
        }
        inline void fun()
        {
                    cout<<"\n Inline fun"; 
        }
        db()
        {
            rollno=1;
            strcpy(name,"ABC");
            strcpy(Class,"1");
            strcpy(div,"A");
            strcpy(dob,"DD/MM/YYYY");
            strcpy(bg,"A+");
            strcpy(contact,"Pune");
            strcpy(phone,"1234567");
            strcpy(license,"ABC123");
            ++stdno;
        }
        db(db*obj)
        {
            strcpy(name,obj->name);
            strcpy(Class,obj->Class);
            strcpy(div,obj->div);
            strcpy(dob,obj->dob);
            strcpy(bg,obj->bg);
            strcpy(contact,obj->contact);
            strcpy(phone,obj->phone);
            strcpy(license,obj->license);
            ++stdno;  
        }
        void getdata()
        {
            cout<<"Roll no:";
            cin>>rollno;
            cout<<"Name:";
            cin	>>name;
            cout<<"Class:";
            cin>>Class;
            cout<<"Division:";
            cin>>div;
            cout<<"Date of Birth:";
            cin>>dob;
            cout<<"Blood Group:";
            cin>>bg;
            cout<<"Contact Address:";
            cin>>contact;
            cout<<"Phone No.:";
            cin>>phone;
            cout<<"Driving License:";
            cin>>license;
        } 
        friend void display(db d);	
        ~db()
        {
            cout<<"\n Object is destroyed \n";
        }
}; 
void display(db d)
{
    cout<<"\nStudent Information\n";
    cout<<"Name:"<<d.name<<endl;
   	cout<<"Roll No:" <<d.rollno<<endl;
   	cout<<"Class:" <<d.Class<<endl;
   	cout<<"Division:" <<d.div<<endl;
   	cout<<"Date of Birth:" <<d.dob<<endl;
   	cout<<"Blood Group:" <<d.bg<<endl;
   	cout<<"Contact:" <<d.contact<<endl;
   	cout<<"Phone No.:" <<d.phone<<endl;
   	cout<<"Driving License:" <<d.license<<endl;
}

int db::stdno;  
int main()
{
   	int n,i;
   	db d1,*ptr[5];
    display (d1);
   	d1.getdata();
   	display(d1);
   	db d2(&d1);
   	cout<<"\n use of copy constuctor \n";
   	display(d2);
   	cout<<"\n How many objects you want to create: ";
   	cin>>n;
   	for(i=0;i<n;i++)
   	{
   		ptr[i]=new db();
   		ptr[i]->getdata();
   	}
    cout<<"\n Student database \n";
  	for(i=0;i<n;i++)
 	{
        display(*ptr[i]);
	}
   	db::count();
   	for(i=0;i<n;i++)
    {
        delete(ptr[i]);
   	}
    cout<<"\n Object deleted";
   	return 0;
}