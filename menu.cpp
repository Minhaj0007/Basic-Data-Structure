#include <iostream>
using namespace std;

int main() {
    int ch;
    int ara[10] = {10, 20, 30, 40, 50};
    int n = 5; 

    cout << "Enter your choice:\n";
    cout << "1. Display\n2. Insert\n3. Delete\n";
    cin >> ch;

    switch (ch) {
        case 1: { 
            cout << "Array elements: ";
            for (int i = 0; i < n; i++) {
                cout << ara[i] << " ";
            }
            cout << endl;
            break;
        }

        case 2: { 
            int pos = 2; 
            int value = 25;

            cout << "Before insertion: ";
            for (int i = 0; i < n; i++) cout << ara[i] << " ";

            
            for (int i = n; i > pos; i--) {
                ara[i] = ara[i - 1];
            }

            ara[pos] = value;
            n++;

            cout << "\nAfter insertion: ";
            for (int i = 0; i < n; i++) cout << ara[i] << " ";
            cout << endl;
            break;
        }

        case 3: { 
            int pos = 2;

            cout << "Before deletion: ";
            for (int i = 0; i < n; i++) cout << ara[i] << " ";

         
            for (int i = pos; i < n - 1; i++) {
                ara[i] = ara[i + 1];
            }

            n--;

            cout << "\nAfter deletion: ";
            for (int i = 0; i < n; i++) cout << ara[i] << " ";
            cout << endl;
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
