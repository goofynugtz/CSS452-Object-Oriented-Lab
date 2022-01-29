#include <iostream>
#include "./matrix.h"
using namespace std;



int main (void){

  int rows, columns;
  cout << "\nEnter #rows #columns of first matrix: ";
  cin >> rows >> columns;
  Matrix A(rows, columns);
  A.fillValues();
  cout << "\nEnter #rows #columns of second matrix: ";
  cin >> rows >> columns;
  Matrix B(rows, columns);
  B.fillValues();

  Matrix result = A*B;
  result.previewMatrix();
  
  return 0;
}