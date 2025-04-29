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
