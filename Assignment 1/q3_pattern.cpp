#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


void pattern (int n){
  
  for (int i = 1; i <= n; i++){
    cout << setw(2*(i-1)) << "";
    for (int j = i; j <= n; j++){
      cout << j << " ";
    }
    for (int j = n-1; j >= i; j--){
      cout << j << " ";
    }
    cout << endl;
  }

  for (int i = n-1; i >= 1; i--){
    cout << setw(2*(i-1)) << "";
    for (int j = i; j <= n; j++){
      cout << j << " ";
    }
    for (int j = n-1; j >= i; j--){
      cout << j << " ";
    }
    cout << endl;
  }
}


int main(void){

  cout << "\n>> Enter a number: ";
  int n; cin >> n;
  
  cout << "\n";
  pattern(n);
  
  return 0;
}