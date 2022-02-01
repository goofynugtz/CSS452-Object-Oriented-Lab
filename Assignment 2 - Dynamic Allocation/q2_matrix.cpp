#include <iostream>
#include "./matrix.h"
using namespace std;

int main (void){

  int order;
  cout << "\nEnter #order of matrix: ";
  cin >> order;
  Matrix A(order);
  cout << "\nA: ";
  cin >> A;
  
  Matrix B(order);
  cout << "\nB: ";
  cin >> B;

  Matrix result = A*B;
  cout << result;
  cout << "Determinant of Result: " << result.calculateDeterminant() << "\n";
  
  return 0;
}