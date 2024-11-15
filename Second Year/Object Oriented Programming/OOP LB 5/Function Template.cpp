#include <iostream> 
#include<stdlib.h> 
#include<string.h> 
using namespace std; 
template<typename T> 

void sort(T a[],int n)
{
    int pos; T temp;
    for(int i=0;i<n-1;i++)
    {
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if (a[j]<a[pos])
                pos=j;
        }
        if (pos!=i)
        {
            temp=a[i]; a[i]=a[pos]; a[pos]=temp;
        }
    }
    //display element 
    cout<<"sorted elements are "; 
    for(int k=0;k<n;k++)
    {
        cout<<"\n"<<a[k];
    }
}

int main()
{
    int ch; 
    int no; 
    int ele;
    int fno; 
    while(1)
    {
        cout<<"\nmenu \n1.int sorting\n2.char sorting\n3.float sorting\n4.exit"; 
        cout<<"\nEnter choice:";
        cin>>ch; 
        switch(ch)
        {
            case 1:
                cout<<"\ninteger sorting\n";
                cout<<"\nenter no of element to be sorted\n"; 
                cin>>no;
                int sor1[100]; 
                cout<<"\nenter element\n"; 
                for(int i=0;i<no;i++)
                {
                    cin>>sor1[i];
                }                
                sort<int>(sor1,no); 
                break;
            case 2:
                cout<<"\ncharacter sorting\n"; 
                cout<<"\nenter no of element to be sorted\n"; 
                cin>>ele;
                char sor2[100]; 
                cout<<"\nenter element\n"; 
                for(int i=0;i<ele;i++)
                {
                    cin>>sor2[i];
                }
                sort<char>(sor2,ele); 
                break;
            case 3:
                cout<<"\nfloating type sorting\n"; 
                cout<<"\nenter no of element to be sorted\n"; 
                cin>>fno;
                float sor3[100]; 
                cout<<"\nenter element\n"; 
                for(int i=0;i<fno;i++)
                {
                    cin>>sor3[i];
                }
                sort<float>(sor3,fno); 
                break; 
            case 4:
                exit(0);
        }
    }
    return 0;
}
