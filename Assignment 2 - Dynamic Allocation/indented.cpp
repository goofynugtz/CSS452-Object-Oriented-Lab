#include <iostream>
using namespace std;

int main(void){
  cout << "Hello";
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 20; j++){
      cout << i+j << "\n";
      if (i+j==30){
        cout << "Hello Again";
      }
      else {
        continue;
      }
    }
  }
}
