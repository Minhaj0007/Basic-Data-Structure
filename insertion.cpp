#include<iostream>
using namespace std;

int main (){
    int ara[10] = {11, 22, 33, 44};
    int n = 4;
    int pos = 1;
    int value = 99;

    cout << "Before: " << endl;
    for(int i = 0; i < n; i++){
        cout << ara[i] << " ";
    }
    for(int i = n - 1; i >= pos - 1; i--){
        ara[i + 1] = ara[i];
    }
    ara[pos - 1] = value;
    n++;

    cout << "\nAfter Insertion: ";
    for(int i = 0; i < n; i++){
        cout << ara[i] << " ";
    }

    return 0;
}
