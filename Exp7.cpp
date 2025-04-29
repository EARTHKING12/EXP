#include<iostream>
using namespace std;
class Flights{
    string arr[5]={"Mumbai","Pune","Solapur","Delhi","Sambhaji Nagar"};
    int time[5][5];
    int matrix[5][5];
    public:
    Flights()
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                matrix[i][j]=0;
            }
        }
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                time[i][j]=0;
            }
        }
    }
    void Giveflights(int n,int m,int k)
    {
        matrix[n-1][m-1]=1;
        matrix[m-1][n-1]=1;
        time[n-1][m-1]=k;
        time[m-1][n-1]=k;
    }
    void displaymatrix()
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void seeFlights()
    {
        cout<<"FlightDetails::-\n";
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(matrix[i][j]==1)
                {
                    cout<<arr[i]<<"-->"<<arr[j]<<"-->"<<time[i][j]<<endl;
                }
            }
        }
    }
    void connection()
    {
        int count=0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(matrix[i][j]==1)
                {
                    count++;
                    break;
                }
            }
        }
        if(count==5)
        {
            cout<<"connected";
        }
        else
        {
            cout<<"Not connected";
        }
    }
    void checkconnection(int n,int m)
    {
        if(matrix[n-1][m-1]==1)
        {
            cout<<"Connection( Ready to Flight)";
        }
        else
        {
            cout<<"Not connected(No flight)";
        }
    }

};
int main()
{
    Flights s1;
    int n,m,k;
    int ch=0;
    while(ch!=6)
    {
        cout<<"----------------------------Menu for AIRHOUSE--------------------------------------";
        cout<<"\n1.Give Flight Details";
        cout<<"\n2.Display Matrix";
        cout<<"\n3.see Flight details";
        cout<<"\n4.check connected or not";
        cout<<"\n5.Check connection of graph";
        cout<<"\n6.Exit Application";
        cout<<"\nEnter option::-";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\n1.Mumbai";
                cout<<"\n2.Pune";
                cout<<"\n3.Solapur";
                cout<<"\n4.Delhi";
                cout<<"\n5.Sambhaji Nagar\n";
                cout<<"Enter Starting point of Flight";
                cin>>n;
                cout<<"Enter Terminal point of Flight";
                cin>>m;
                cout<<"Time required";
                cin>>k;
                s1.Giveflights(n,m,k);
                break;
            case 2:
                s1.displaymatrix();
                break;
            case 3:
                s1.seeFlights();
                break;
            case 4:
                cout<<"\n1.Mumbai";
                cout<<"\n2.Pune";
                cout<<"\n3.Solapur";
                cout<<"\n4.Delhi";
                cout<<"\n5.Sambhaji Nagar\n";
                cout<<"Enter Starting point of Flight";
                cin>>n;
                cout<<"Enter Terminal point of Flight";
                cin>>m;
                break;
            case 5:
                s1.connection();
            case 6:
                cout<<"Exit from AirHouse";
        }
    }
}