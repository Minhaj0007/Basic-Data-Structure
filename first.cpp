#include<iostream>
using namespace std;

int main (){
  int ara[3] = {1, 2, 3};
  cout << "Element\t Value\t Address\n";
  for(int i = 0; i < 3; i++){
    cout << "ara["<< i <<"]\t" << ara[i]
    << "\t" << &ara[i] << endl;
  }
  
  return 0;
}
