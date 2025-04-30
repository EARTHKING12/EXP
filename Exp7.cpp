#include<iostream>
using namespace std;

class Flights {
    string arr[5] = {"Mumbai", "Pune", "Solapur", "Delhi", "Sambhaji Nagar"};
    int time[5][5];
    int matrix[5][5];

public:
    Flights() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = 0;
                time[i][j] = 0;
            }
        }
    }

    void Giveflights(int n, int m, int k) {
        matrix[n - 1][m - 1] = 1;
        matrix[m - 1][n - 1] = 1;
        time[n - 1][m - 1] = k;
        time[m - 1][n - 1] = k;
    }

    void displaymatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void seeFlights() {
        cout << "\nFlight Details:\n";
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (matrix[i][j] == 1) {
                    cout << arr[i] << " --> " << arr[j] << " (Time: " << time[i][j] << " mins)" << endl;
                }
            }
        }
    }

    void connection() {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            bool connected = false;
            for (int j = 0; j < 5; j++) {
                if (matrix[i][j] == 1) {
                    connected = true;
                    break;
                }
            }
            if (connected) {
                count++;
            }
        }
        if (count == 5) {
            cout << "Graph is Connected\n";
        } else {
            cout << "Graph is Not Connected\n";
        }
    }

    void checkconnection(int n, int m) {
        if (matrix[n - 1][m - 1] == 1) {
            cout << "Connection exists (Ready to Fly)\n";
        } else {
            cout << "No direct flight (Not connected)\n";
        }
    }
};

int main() {
    Flights s1;
    int n, m, k;
    int ch = 0;

    while (ch != 6) {
        cout << "\n---------------------------- Menu for AIRHOUSE ----------------------------";
        cout << "\n1. Give Flight Details";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. See Flight Details";
        cout << "\n4. Check Direct Flight Connection";
        cout << "\n5. Check if Graph is Connected";
        cout << "\n6. Exit Application";
        cout << "\nEnter option: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\n1. Mumbai\n2. Pune\n3. Solapur\n4. Delhi\n5. Sambhaji Nagar\n";
                cout << "Enter Starting point of Flight: ";
                cin >> n;
                cout << "Enter Terminal point of Flight: ";
                cin >> m;
                cout << "Enter Time required: ";
                cin >> k;
                s1.Giveflights(n, m, k);
                break;

            case 2:
                s1.displaymatrix();
                break;

            case 3:
                s1.seeFlights();
                break;

            case 4:
                cout << "\n1. Mumbai\n2. Pune\n3. Solapur\n4. Delhi\n5. Sambhaji Nagar\n";
                cout << "Enter Starting point of Flight: ";
                cin >> n;
                cout << "Enter Terminal point of Flight: ";
                cin >> m;
                s1.checkconnection(n, m); // ✅ FIXED: Added function call
                break;

            case 5:
                s1.connection(); // ✅ FIXED: Added missing break
                break;

            case 6:
                cout << "Exiting from AirHouse...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}


/*
//sir

#include <iostream>
#include <cstdlib>
#include <cstdio>     
#include <cstring>
using namespace std;
typedef struct Node
{
	int data;
	struct Node *next;
}NODE;

class Graph
{
	int G[10][10];
	NODE Header[10];
	const char city[5][20]={"Pune","Mumbai","Delhi","Jaipur","Chakan"};
	int visited[10];
	int mNodes; //No. of nodes in Adjacency Matrix Graph
	int lNodes; //No. of nodes in Adjacency List Graph
	public:
	Graph()
	{
		//Initialization of Adjacency Matrix
		for (int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				G[i][j]=0;
			
		//Initialization of List Header
		for (int i=0;i<10;i++)
		{
			Header[i].data=i+1;
			Header[i].next=NULL;
			visited[i]=0;
		}
		mNodes=0;
		lNodes=0;
	}
	
	//Initialization of Adjacency Matrix
	void init_Matrix()
	{
		mNodes=5;//set this value equal to number of cities
		for (int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				G[i][j]=0;
	}
	
	//Initialization of List Header
	void init_List()
	{
		for (int i=0;i<10;i++)
		{
			Header[i].data=i+1;
			Header[i].next=NULL;
			visited[i]=0;
		}
	}
	
	//Initialization of visited array
	void init_visited()
	{
		for (int i=0;i<10;i++)
			visited[i]=0;
	}
	
	//Read graph as adjacency matrix
	void readGAM()
	{
		int i,j;
		int flag=1;
		init_Matrix();
		mNodes=5;//set this value equal to number of cities
		while(flag==1)
		{
			cout<<"\nEnter source node:";
			cin>>i;
			cout<<"\nEnter destination node:";
			cin>>j;
			G[i][j]=1;
			cout<<"\nDo you want to add more edge yes=1 or no=0:";
			cin>>flag;
		}
	}
	
	//Print graph as adjacency matrix
	void printGAM()
	{
		int i,j,k=0;
		cout<<"\n\t";
		for (i=0;i<mNodes;i++)
			cout<<city[i]<<"\t";
		cout<<"\n";
		for (i=1;i<=mNodes;i++)
		{
			cout<<city[i-1]<<"\t";
			for(j=1;j<=mNodes;j++)
				cout<<G[i][j]<<"\t";
			
			cout<<"\n";
		}
	}

	//Function for DFS traversal
	void DFS_RECURSIVE(int i)
	{
		int j;
		cout<<" "<<i;
		visited[i]=1;
		for(j=1;j<=mNodes;j++)
			if(!visited[j] && G[i][j]==1)
				DFS_RECURSIVE(j);
	}
	
	//Function to see whether graph is connected or not
	bool isConnected()
	{
		int i;
		init_visited();
		
		//Make a DFS traversal on complete graph starting from vertax '1'
		DFS_RECURSIVE(1);
		
		//if any of the nodes in graph is not connected then it will remain unvisited
		for(i=1;i<=mNodes;i++)
			if(visited[i]==0)//if a node is unvisited then graph is not connected
				return false;
		
		return true;//if all nodes are visted then graph is connected
	}
};


/** Main Contains menu **/
int main()
{
    Graph g1;
	int n;
	int cho=0;
	while(cho != 4)
	{
     cout<<"\n********CONNECTED GRAPH*********";
     cout<<"\n1-Read Graph Adjacency Matrix";
     cout<<"\n2-Print Graph Adjacency Matrix";
	 cout<<"\n3-Check Graph Connected or Not Connected";
     cout<<"\n4-EXIT";
     cout<<"\nEnter ur choice:";
     cin>>cho;
     switch(cho)
     {
       case 1:
		g1.readGAM();
		break;
       case 2:
		g1.printGAM();
		break;
	   case 3:
		if (g1.isConnected())
			cout<<"\nGraph is connected!";
		else
			cout<<"\nGraph is not connected!";
		break;
	   case 4:
		cout<<"\nProgram Exits!!";
		break;
       default:
		cout<<"\nWrong choice!";
     }
    }
	
    return 0;
}
*/
