#include<iostream>
using namespace std;
#define MAX 100

class Hashing {
public:
    long long arr[MAX], n, key;
    string arr2[MAX];
    string name;

    void compalsary() {
        cout << "Enter the size of table: ";
        cin >> n;
        for(int i = 0; i < n; i++) {
            arr[i] = -1;
            arr2[i] = ""; // initialize as empty string
        }
    }

    void display() {
        cout << "\n--- Hash Table ---\n";
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                cout << i << " ---> " << arr2[i] << endl;
            }
        }
    }

    void insert() {
        cout << "Enter the key (number): ";
        cin >> key;
        cout << "Enter the name: ";
        cin >> name;
        
        int index = key % n;
        if(arr[index] != -1) { // collision
            bool inserted = false;
            for(int i = 0; i < n; i++) {
                if(arr[i] == -1) { // empty spot found
                    arr[i] = key;
                    arr2[i] = name;
                    inserted = true;
                    cout << "Inserted at index " << i << " after collision.\n";
                    break;
                }
            }
            if(!inserted) {
                cout << "Table is full. Cannot insert.\n";
            }
        }
        else { // no collision
            arr[index] = key;
            arr2[index] = name;
            cout << "Inserted at index " << index << ".\n";
        }
    }

    void Delete() {
        int num, c = 0;
        cout << "Enter number to delete: ";
        cin >> num;
        for(int i = 0; i < n; i++) {
            if(arr[i] == num) {
                arr[i] = -1;
                arr2[i] = "";
                c = 0;
                cout << "Deleted successfully.\n";
                return;
            }
            else {
                c = 1;
            }
        }
        if(c == 1) {
            cout << "Number not found in table.\n";
        }
    }

    void search() {
        int number;
        cout << "Enter number to search: ";
        cin >> number;
        bool found = false;
        for(int i = 0; i < n; i++) {
            if(arr[i] == number) {
                cout << "Number found at index " << i << ".\n";
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "Number not found.\n";
        }
    }
};

int main() {
    int choice = 0;
    Hashing obj;
    obj.compalsary();
    while(choice != 5) {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.Delete();
                break;
            case 3:
                obj.search();
                break;
            case 4:
                obj.display();
                break;
            case 5:
                cout << "Exiting Program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
