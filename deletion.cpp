#include<iostream>
using namespace std;

int main (){
    int ara[10] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2;

    cout << "Before: " << endl;
    for(int i = 0; i < n; i++){
        cout << ara[i] << " ";
    }

    for(int i = pos - 1; i < n - 1; i++){
        ara[i] = ara[i + 1];
    }

    n--;

    cout << "\nAfter Deletion: ";
    for(int i = 0; i < n; i++){
        cout << ara[i] << " ";
    }

    return 0;
}
