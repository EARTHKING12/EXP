#include<iostream>
using namespace std;
#define MAX 100;
class Hashing{
    public:
    long long arr[100],n,key;
    string arr2[100];
    string name;
    void compalsary()
    {
        cout<<"Enter the size of table";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            arr[i]=-1;
            arr2[i]=-1;
        }
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=-1)
            {
                cout<<i<<"--->"<<arr2[i];
            }
        }
    }
    void insert()
    {
        cout<<"Enter the key";
        cin>>key;
        cout<<"Enter the name";
        cin>>name;
        int index=key%n;
        if(arr[index]!=-1)
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i]==0)
                {
                    arr[i]=key;
                    arr2[i]=name;
                }
            }
            cout<<"Table is full";
        }
        else{
            arr[index]=key;
            arr2[index]=name;
        }
    }
    void Delete()
    {
        int num,c=0;
        cout<<"Enter  number to delete";
        cin>>num;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==num)
            {
                arr[i]=-1;
                arr2[i]=-1;
                c=0;
                break;
            }
            else
            {
                c=1;
            }
        }
        if(c==1)
        {
            cout<<"Number is not in list";
        }
    }
    void search()
    {
        int number;
        cout<<"Enter number to search";
        cin>>number;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==number)
            {
                cout<<"Number is found at index"<<i;
            }
        }
    }
};
int main()
{
    int choice;
    Hashing obj;
    obj.compalsary();
    while(choice!=5)
    {
        cout<<"\n1.Insert";
        cout<<"\n2.Delete";
        cout<<"\n3.Search";
        cout<<"\n4.display";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice::";
        cin>>choice;
        switch(choice)
        {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.Delete();
                break;
            case 3:
                NULL;
                break;
            case 4:
                obj.display();
                break;
            case 5:
                cout<<"Exit";
        }
    }
}
