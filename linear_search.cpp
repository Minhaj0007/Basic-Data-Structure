#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ara[n];
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }
    int key = 30;
    int flag = 0;
    int pos;
    for(int i  = 0; i < n; i++){
        if(ara[i] == key){
            flag = 1;
            pos = i;
            break;
        }
    }
    if(flag){
        cout << "The element is found at index :" << pos << endl;
    }
    else{
        cout << "NOT FOUND" << endl;
    }
}
