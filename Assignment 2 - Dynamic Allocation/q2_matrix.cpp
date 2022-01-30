#include <iostream>
#include "./matrix.h"
using namespace std;



int main (void){

  int rows, columns;
  cout << "\nEnter #rows #columns of first matrix: ";
  cin >> rows >> columns;
  Matrix A(rows, columns);
  cin >> A;
  
  cout << "\nEnter #rows #columns of second matrix: ";
  cin >> rows >> columns;
  Matrix B(rows, columns);
  cin >> B;

  Matrix result = A*B;
  cout << result;
  
  return 0;
}